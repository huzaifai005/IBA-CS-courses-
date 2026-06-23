#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
#include<numeric>   
#include<random>    

class sortingStrategy {
public: 
    virtual ~sortingStrategy() = default;
    virtual void partialSort(std::vector<int>& vec, int k, int& comparisons, int& swaps) = 0;

    int countInversions(std::vector<int>& vec) {
        int inversions = 0;
        for(size_t i = 0; i < vec.size(); i++) {
            for(size_t j = i + 1; j < vec.size(); j++) {
                if(vec[i] > vec[j]) {
                    inversions++;
                }
            }
        }
        return inversions;
    }
};

class insertionSort : public sortingStrategy {
public:
    void partialSort(std::vector<int>& vec, int k, int& comparisons, int& swaps) override {
        comparisons = 0;
        swaps = 0;
        int operations = 0;
        
        for(size_t i = 1; i < vec.size() && operations < k; i++) {
            int key = vec[i];
            size_t j = i;
            
            while(j > 0 && operations < k) {
                comparisons++;
                operations++;
                if(vec[j-1] > key) {
                    if(operations < k) {
                        vec[j] = vec[j-1];
                        swaps++;
                        operations++;
                        j--;
                    }
                } else {
                    break;
                }
            }
            vec[j] = key;
        }
    }
};

class selectionSort : public sortingStrategy {
public:
    void partialSort(std::vector<int>& vec, int k, int& comparisons, int& swaps) override {
        int operations = 0;
        comparisons = 0;
        swaps = 0;
        for (size_t i = 0; i < vec.size() - 1 && operations < k; ++i) {
            int minindex = i;
            for (size_t j = i + 1; j < vec.size() && operations < k; ++j) {
                operations++;
                comparisons++;
                if (vec[j] < vec[minindex]) {
                    minindex = j;
                }
            }
            if (minindex != i && operations < k) {
                swaps++;
                operations++;
                int temp = vec[i];
                vec[i] = vec[minindex];
                vec[minindex] = temp;
            }
        }
    }
};

class shellSort : public sortingStrategy {
public:
    void partialSort(std::vector<int>& vec, int k, int& comparisons, int& swaps) override {
        comparisons = 0;
        swaps = 0;
        int operations = 0;
        for (size_t jump = vec.size()/2; jump > 0 && operations < k; jump /= 2) {
            for (size_t i = jump; i < vec.size() && operations < k; ++i) {
                int temp = vec[i];
                size_t j;
                for (j = i; j >= jump && operations < k; j -= jump) {
                    comparisons++;
                    operations++;
                    if (vec[j - jump] > temp) {
                        if (operations < k) {
                            vec[j] = vec[j - jump];
                            swaps++;
                            operations++;
                        }
                    } else {
                        break;
                    }
                }
                if (j != i && operations < k) {
                    vec[j] = temp;
                }
            }
        }
    }
};

std::vector<int> generateRandomArray(int size) {
    std::vector<int> arr(size);
    std::iota(arr.begin(), arr.end(), 0); 
    std::shuffle(arr.begin(), arr.end(), std::mt19937{std::random_device{}()});
    return arr;
}

struct StrategyResult {
    std::string name;
    int comparisons;
    int swaps;
    int inversions;
    float cost;
};

StrategyResult testStrategy(const std::string& name, sortingStrategy& strategy, 
                 std::vector<int> arr, int k, 
                 float compareWeight, float swapWeight, float inversionWeight) {
    int comparisons, swaps;
    
    strategy.partialSort(arr, k, comparisons, swaps);
    int inversions = strategy.countInversions(arr);
    float weighted_cost = (compareWeight * comparisons) + 
                         (swapWeight * swaps) + 
                         (inversionWeight * inversions);
    
    std::cout << std::endl << name << " Results:" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "Operations used: " << (comparisons + swaps) << "/" << k << std::endl;
    std::cout << "Comparisons: " << comparisons << std::endl;
    std::cout << "Swaps: " << swaps << std::endl;
    std::cout << "Remaining inversions: " << inversions << std::endl;
    std::cout << "Weighted cost: " << weighted_cost << std::endl;

    return {name, comparisons, swaps, inversions, weighted_cost};
}

int main() {
    const int ARRAY_SIZE = 100;
    const int OPERATION_LIMIT = 3004;
    const float COMPARE_WEIGHT = 0.440941f;
    const float SWAP_WEIGHT = 0.321428f;
    const float INVERSION_WEIGHT = 0.0698281f;

    std::vector<int> arr = generateRandomArray(ARRAY_SIZE);
    
    insertionSort insertSorter;
    selectionSort selectSorter;
    shellSort shellSorter;
    
    std::vector<StrategyResult> results;
    
    results.push_back(testStrategy("Insertion Sort", insertSorter, arr, OPERATION_LIMIT, 
                COMPARE_WEIGHT, SWAP_WEIGHT, INVERSION_WEIGHT));
    
    results.push_back(testStrategy("Selection Sort", selectSorter, arr, OPERATION_LIMIT,
                COMPARE_WEIGHT, SWAP_WEIGHT, INVERSION_WEIGHT));
    
    results.push_back(testStrategy("Shell Sort", shellSorter, arr, OPERATION_LIMIT,
                COMPARE_WEIGHT, SWAP_WEIGHT, INVERSION_WEIGHT));

    float minCost = results[0].cost;
    for (const auto& res : results) {
        if (res.cost < minCost) {
            minCost = res.cost;
        }
    }

    std::cout << std::endl << "Best Strategy/Strategies:" << std::endl;
    for (const auto& res : results) {
        if (res.cost == minCost) {
            std::cout << "- " << res.name << " (Cost: " << res.cost << ")" << std::endl;
        }
    }
}