#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include<iostream>
#include <vector>

template <typename T>
struct selection_sort {
    void operator()(std::vector<T>& vec) const {
        for (int i = 0; i < static_cast<int>(vec.size()) - 1; ++i) {
            int minindex = i;
            for (int j = i + 1; j < static_cast<int>(vec.size()); ++j) {
                if (vec[j] < vec[minindex]) {
                    minindex = j;
                }
            }
            if (minindex != i) {
                T temp = vec[i];
                vec[i] = vec[minindex];
                vec[minindex] = temp;
            }
        }
    }
};

#endif 