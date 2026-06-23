#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include<iostream>
#include <vector>

template <typename T>
void shell_sort(std::vector<T>& vec) {
    for (int jump = static_cast<int>(vec.size())/2; jump > 0; jump /= 2) {
        for (int i = jump; i < static_cast<int>(vec.size()); ++i) {
            T temp = vec[i];
            int j;
            for (j = i; j >= jump && vec[j - jump] > temp; j -= jump) {
                vec[j] = vec[j - jump];
            }
            vec[j] = temp;
        }
    }
};

#endif