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
    std::vector<std::string> words;
    std::ifstream file("wordlist.txt");
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open wordlist.txt" << std::endl;
        return 1;
    }

    std::string word;
    while (std::getline(file, word) && words.size() < n/2) {
        if (word.length() <= 10) {
            words.push_back(word);
        }
    }
    file.close();
    
    std::vector<std::string> final_list;
    for (const auto& original_word : words) {
        final_list.push_back(original_word);
        std::string anagram = original_word;
        std::shuffle(anagram.begin(), anagram.end(),
                   std::default_random_engine(std::random_device()()));
        final_list.push_back(anagram);
    }

    std::vector<std::string> sorted_list = final_list;
    for (auto& word : sorted_list) {
        std::sort(word.begin(), word.end());
    }

    std::vector<int> indices(sorted_list.size());
    for (int i = 0; i < indices.size(); ++i) {
        indices[i] = i;
    }

    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
        return sorted_list[a] < sorted_list[b];
    });

    std::cout << "Anagram groups:" << std::endl;
    int start = 0;
    for (int i = 1; i <= indices.size(); ++i) {
        if (i == indices.size() || sorted_list[indices[i]] != sorted_list[indices[i-1]]) {
            if (i - start > 1) {
                for (int j = start; j < i; ++j) {
                    std::cout << final_list[indices[j]];
                    if (j < i - 1) std::cout << " <-> ";
                }
                std::cout << std::endl;
            }
            start = i;
        }
    }
    
    return 0;
}