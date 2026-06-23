#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>

std::string random_word(int m) {
    std::string s;
    for (int i = 0; i < m; ++i) {
        s.push_back('a' + std::random_device()() % 26);
    }
    return s;
}

int main() {
    const int n = 1000;
    std::vector<std::string> word_list;
    std::ifstream file("wordlist.txt");
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open wordlist.txt" << std::endl;
        return 1;
    }
    

    std::string word;
    while (std::getline(file, word) && word_list.size() < n/2) {
        if (word.length() <= 10) { 
            word_list.push_back(word);
        }
    }
    file.close();
    
    std::vector<std::string> final_list;
    for (const auto& original_word : word_list) {
        final_list.push_back(original_word);
        std::string anagram = original_word;
        std::shuffle(anagram.begin(), anagram.end(),
                   std::default_random_engine(std::random_device()()));
        final_list.push_back(anagram);
    }

    for (const auto& word : final_list) {
        std::cout << word << std::endl;
    }
    
    return 0;
}