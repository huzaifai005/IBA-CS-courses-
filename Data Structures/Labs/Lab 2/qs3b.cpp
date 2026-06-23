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

    for (int i = 0; i < final_list.size(); ++i) {
        for (int j = i + 1; j < final_list.size(); ++j) {
            if (final_list[i].length() != final_list[j].length()) {
                continue;
            }
            int freq1[26] = {0};
            int freq2[26] = {0};
            
            for (char c : final_list[i]) {
                freq1[c - 'a']++;
            }
            
            for (char c : final_list[j]) {
                freq2[c - 'a']++;
            }

            bool is_anagram = true;
            for (int k = 0; k < 26; ++k) {
                if (freq1[k] != freq2[k]) {
                    is_anagram = false;
                    break;
                }
            }
            
            if (is_anagram) {
                std::cout << final_list[i] << " <-> " << final_list[j] << std::endl;
            }
        }
    }
    
    return 0;
}