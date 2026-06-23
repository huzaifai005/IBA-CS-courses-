#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include "digraph.hpp" 
#include "directed-dfs.hpp" 

std::vector<std::string> words;
std::unordered_map<std::string, int> word_to_index;
Digraph* G = nullptr;
std::vector<int> longestpath; 
std::vector<int> nextonlongestpath;
std::vector<int> currentpath;

int longestPathDFS(int v) {
    if (longestpath[v] != -1) {
        return longestpath[v];
    }
    int maxlength = 0;
    int bestneighbor = -1;
    for (int w : G->adj(v)) {
        int length = longestPathDFS(w);
        if (length > maxlength) {
            maxlength = length;
            bestneighbor = w;
        }
    }
    int pathlength = 1 + maxlength;
    longestpath[v] = pathlength;
    nextonlongestpath[v] = bestneighbor;
    return pathlength;
}

bool isChild(const std::string& w1, const std::string& w2) {
    if (w2.length() != w1.length() + 1) return false;
    for (size_t i = 0; i < w2.length(); ++i) {
        std::string w2minusone = w2.substr(0, i) + w2.substr(i + 1);
        if (w2minusone == w1) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::cerr << "Warning: Command line arguments are ignored. Reading dictionary from stdin." << std::endl;
    }
    std::string word;
    int index = 0;
    while (std::cin >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
        word_to_index[word] = index++;
    }
    if (words.empty()) {
        std::cerr << "Error: No words loaded from standard input. Please use redirection: ./solver < words.txt" << std::endl;
    }
    int V = words.size();
    Digraph wordgraph(V);
    G = &wordgraph;
    std::cout << "Building directed graph with " << V << " vertices..." << std::endl;
    for (int i = 0; i < V; ++i) {
        const std::string& w1 = words[i];
        for (int j = 0; j < V; ++j) {
            const std::string& w2 = words[j];
            if (w2.length() == w1.length() + 1) {
                if (isChild(w1, w2)) {
                    G->addEdge(i, j); 
                }
            }
        }
    }
    std::cout << "Graph built with " << G->E() << " directed edges." << std::endl;
    longestpath.assign(V, -1);
    nextonlongestpath.assign(V, -1);
    int maxpathlength = 0;
    int startoflongestpath = -1;
    for (int v = 0; v < V; ++v) {
        if (words[v].length() == 1) {
            int currentlength = longestPathDFS(v);
            if (currentlength > maxpathlength) {
                maxpathlength = currentlength;
                startoflongestpath = v;
            }
        }
    }
    if (maxpathlength >= 9) {
        std::cout << std::endl;
        std::cout << "Solution Found: A " << maxpathlength << "-word ladder exists!" << std::endl;
        std::cout << "Ladder (9 letters to 1 letter): " << std::endl;
        int currentvertex = -1;
        int maxlengthat9 = 0;
        for (int v = 0; v < V; ++v) {
            if (words[v].length() == 9) {
                int len = longestPathDFS(v);
                if (len > maxlengthat9) {
                    maxlengthat9 = len;
                    currentvertex = v;
                }
            }
        }
        if (currentvertex == -1 || maxlengthat9 < 9) {
            std::cout << "No nine-letter word path found." << std::endl;
            return 0;
        }
        std::vector<std::string> pathwords;
        while (currentvertex != -1) {
            pathwords.push_back(words[currentvertex]);
            currentvertex = nextonlongestpath[currentvertex];
        }
        for (size_t i = 0; i < pathwords.size(); ++i) {
            std::cout << pathwords[i];
            if (i < pathwords.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "No word ladder of 9 or more words found (max length: " << maxpathlength << ")." << std::endl;
    }
}
