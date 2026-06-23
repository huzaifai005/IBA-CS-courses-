
#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include<iostream>
#include <vector>

template <typename T>
struct insertion_sort {
    void operator()(std::vector<T>& vec) const {
        for (int i = 1; i < static_cast<int>(vec.size()); ++i) {
            T current = vec[i];
            int j = i;

            while (j > 0 && vec[j-1] > current) {
                vec[j] = vec[j-1];
                j--;
            }
            vec[j] = current;
        }
    }
};

#endif

