#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>
#include "Graph.hpp"
#include "DepthFirstSearch.hpp" 

using namespace std;

const int WORDLENGTH = 5;

bool differsByOne(const string& w1, const string& w2) {
    if (w1.length() != WORDLENGTH || w2.length() != WORDLENGTH) return false;
    int differences = 0;
    for (int i = 0; i < WORDLENGTH; ++i) {
        if (w1[i] != w2[i]) {
            differences++;
        }
    }
    return differences == 1;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <start_word> <end_word>" << std::endl;
        std::cerr << "Provide a list of 5-letter words via standard input (e.g., from words5.txt)." << std::endl;
        return 1;
    }
    string startword = argv[1];
    string endword = argv[2];
    if (startword.length() != WORDLENGTH || endword.length() != WORDLENGTH) {
        std::cerr << "Error: Both words must be exactly " << WORDLENGTH << " letters long." << std::endl;
        return 1;
    }
    vector<string> words;
    unordered_map<string, int> word_to_index;
    string word;
    int index = 0;
    while (cin >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word.length() == WORDLENGTH) {
            words.push_back(word);
            word_to_index[word] = index++;
        }
    }
    if (words.empty()) {
        std::cerr << "Error: No 5-letter words loaded from standard input." << std::endl;
        return 1;
    }
    if (word_to_index.find(startword) == word_to_index.end()) {
        std::cerr << "Error: Start word '" << startword << "' not found in the dictionary." << std::endl;
        return 1;
    }
    if (word_to_index.find(endword) == word_to_index.end()) {
        std::cerr << "Error: End word '" << endword << "' not found in the dictionary." << std::endl;
        return 1;
    }
    int startindex = word_to_index.at(startword);
    int endindex = word_to_index.at(endword);
    int V = words.size();
    Graph G(V);
    std::cout << "Building graph with " << V << " vertices..." << std::endl;
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (differsByOne(words[i], words[j])) {
                G.addEdge(i, j);
            }
        }
    }
    std::cout << "Graph built with " << G.E() << " edges." << std::endl;
    DepthFirstSearch dfssolver(G, startindex);
    if (dfssolver.isConnected(endindex)) {
        vector<int> pathindices = dfssolver.pathTo(endindex);
        std::cout << std::endl;
        std::cout << "Word Ladder Found (via DFS):" << std::endl;
        std::cout << "Ladder (length " << pathindices.size() << "): ";
        for (size_t i = 0; i < pathindices.size(); ++i) {
            std::cout << words[pathindices[i]];
            if (i < pathindices.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "No word ladder exists between " << startword << " and " << endword;
        std::cout << std::endl;
    }
}
