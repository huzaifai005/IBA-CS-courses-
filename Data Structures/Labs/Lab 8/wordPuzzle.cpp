#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include<stopWatch.hpp>
#include "hashTable.hpp" 


const int MAX_DICT_WORD_LENGTH = 22; 

struct FoundWord {
    std::string word;
    int startRow;
    int startCol;
    std::string direction;

    bool operator<(const FoundWord& other) const {
        if (direction != other.direction) return direction < other.direction;
        if (startRow != other.startRow) return startRow < other.startRow;
        return startCol < other.startCol;
    }
};

char** readInGrid(const std::string& filename, int& rows, int& cols) {
    std::ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open grid file " << filename << std::endl;
        rows = 0;
        cols = 0;
        return nullptr;
    }

    if (!(file >> rows >> cols)) {
        std::cerr << "Error: Could not read rows and columns from grid file." << std::endl;
        rows = 0;
        cols = 0;
        return nullptr;
    }

    char** grid = new char*[rows];
    for (int r = 0; r < rows; r++) {
        grid[r] = new char[cols];
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (!(file >> grid[r][c])) {
                 std::cerr << "Error: Grid data is incomplete or improperly formatted." << std::endl;
                 for (int i = 0; i <= r; i++) delete[] grid[i];
                 delete[] grid;
                 rows = 0;
                 cols = 0;
                 return nullptr;
            }
        }
    }

    file.close();
    return grid;
}

void deleteGrid(char** grid, int rows) {
    if (grid) {
        for (int r = 0; r < rows; r++) {
            delete[] grid[r];
        }
        delete[] grid;
    }
}

std::string getWordInGrid(char** grid, int numRows, int numCols, 
                          int startRow, int startCol, int dir, int len) {
    int code_dir = dir - 1; 
    static const int row_delta[] = {-1, -1, 0, +1, +1, +1, 0, -1};
    static const int col_delta[] = {0, +1, +1, +1, 0, -1, -1, -1};

    std::string output = "";
    
    int r = startRow;
    int c = startCol;

    for (int i = 0; i < len; i++) {
        if ((c >= numCols) || (r >= numRows) || (r < 0) || (c < 0))
            break;
        
        output += grid[r][c]; 
        r += row_delta[code_dir];
        c += col_delta[code_dir];
    }
    
    return output;
}

std::string getDirectionString(int direction) {
    switch (direction) {
        case 1: return "N";
        case 2: return "NE";
        case 3: return "E";
        case 4: return "SE";
        case 5: return "S";
        case 6: return "SW";
        case 7: return "W";
        case 8: return "NW";
        default: return "";
    }
}

int preprocessDictionary(const std::string& filename, int& wordCount) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        wordCount = 0;
        return 0;
    }

    std::string word;
    int maxLen = 0;
    wordCount = 0;

    while (std::getline(file, word)) {
        if (word.length() >= 3) {
            maxLen = std::max(maxLen, (int)word.length());
        }
        wordCount++;
    }

    return maxLen;
}

void loadDictionary(const std::string& filename, HashTable& ht) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open dictionary file " << filename << " for loading." << std::endl;
        return;
    }

    std::string word;
    while (std::getline(file, word)) {
        // HashTable::insert handles the length check
        ht.insert(word); 
    }
}

std::vector<FoundWord> searchGrid(const HashTable& ht, char** grid, int rows, int cols, int maxWordLen) {
    
    std::vector<FoundWord> foundWords;
    for (int r = 0; r < rows; ++r) {        
        for (int c = 0; c < cols; ++c) {    
            for (int d = 1; d <= 8; ++d) {  
                for (int l = 3; l <= maxWordLen; ++l) { 
                    
                    std::string word = getWordInGrid(grid, rows, cols, r, c, d, l);

                    if ((int)word.length() < l) {
                        break; 
                    }

                    if (ht.contains(word)) {
                        FoundWord fw;
                        fw.word = word;
                        fw.startRow = r;
                        fw.startCol = c;
                        fw.direction = getDirectionString(d);
                        foundWords.push_back(fw);
                    }
                }
            }
        }
    }

    return foundWords;
}

void printResults(std::vector<FoundWord>& foundWords, double elapsedTime) {
    std::sort(foundWords.begin(), foundWords.end());

    for (const auto& fw : foundWords) {
        std::cout << fw.direction << "(" << fw.startRow << ", " << fw.startCol << "):" 
                  << "\t" << fw.word << std::endl;
    }

    std::cout << foundWords.size() << " words found" << std::endl;
    
    std::cout << "Found all words in " << std::fixed << std::setprecision(6) 
              << elapsedTime << " seconds" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <dictionary_file> <grid_file>" << std::endl;
        return 1; 
    }

    const std::string dictionaryFilename = argv[1];
    const std::string gridFilename = argv[2];

    int totalWords;
    int maxDictWordLen = preprocessDictionary(dictionaryFilename, totalWords);

    if (totalWords == 0 || maxDictWordLen == 0) {
        std::cerr << "Error: Dictionary file is empty or contains no words of length >= 3. Exiting." << std::endl;
        return 1;
    }

    const double TARGET_LOAD_FACTOR = 0.5;
    int initialTableSize = (int)std::ceil(totalWords / TARGET_LOAD_FACTOR);
    
    HashTable dictionaryHT(initialTableSize); 
    loadDictionary(dictionaryFilename, dictionaryHT);

    int finalMaxWordLen = std::max(MAX_DICT_WORD_LENGTH, maxDictWordLen);

    int rows = 0, cols = 0;
    char** grid = readInGrid(gridFilename, rows, cols);

    if (!grid) {
        return 1; 
    }

    int maxSearchLength = std::min({rows, cols, finalMaxWordLen});
    
    if (maxSearchLength < 3) {
        std::vector<FoundWord> empty_words;
        printResults(empty_words, 0.0);
        deleteGrid(grid, rows);
        return 0; 
    }

    Stopwatch timer;
    timer.reset(); 

    std::vector<FoundWord> words = searchGrid(dictionaryHT, grid, rows, cols, maxSearchLength);

    double elapsedTime = timer.elapsedTime(); 
    
    deleteGrid(grid, rows);
    printResults(words, elapsedTime);

    return 0;
}