#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>
#include "Task1.hpp"
#include "Task2.hpp"
#include "Task3.hpp"
#include "Task4.hpp"
#include "Task5.hpp"

class SortingBenchmark {
public:
    template <typename SortAlgorithm>
    double evaluate(SortAlgorithm sort, int N) {
        Stopwatch stopwatch;
        double total_time = 0.0;
        const int vector_size = 100000;

        for (int i = 0; i < N; ++i) {
            std::vector<int> data = generate_random_vector(vector_size);
            stopwatch.start();
            sort(data);
            stopwatch.stop();
            total_time += stopwatch.get_elapsed_time_seconds();
            if (!is_sorted(data)) {
                std::cerr << "Sorting failed!" << std::endl;
            }
        }

        return total_time / N;
    }

private:
    std::vector<int> generate_random_vector(int size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, size * 10);

        std::vector<int> data(size);
        for (auto& num : data) {
            num = dist(gen);
        }
        return data;
    }

    bool is_sorted(const std::vector<int>& vec) {
        return std::is_sorted(vec.begin(), vec.end());
    }
};

template <>
double SortingBenchmark::evaluate<BinaryTree<int>>(BinaryTree<int> tree, int N) {
    stopwatch stopwatch;
    double total_time = 0.0;
    const int vector_size = 100000;

    for (int i = 0; i < N; ++i) {
        std::vector<int> data = generate_random_vector(vector_size);
        
        stopwatch.start();
        auto sorted = tree(data);
        stopwatch.stop();
        
        total_time += stopwatch.get_elapsed_time_seconds();
        
        if (!is_sorted(sorted)) {
            std::cerr << "BinaryTree sort failed!" << std::endl;
        }
    }

    return total_time / N;
}

int main() {
    SortingBenchmark benchmark;
    const int runs = 5; 

    double insertion_time = benchmark.evaluate(insertion_sort<int>{}, runs);
    double selection_time = benchmark.evaluate(selection_sort<int>{}, runs);
    double shell_time = benchmark.evaluate(shell_sort<int>, runs);
    double binary_tree_time = benchmark.evaluate(BinaryTree<int>{}, runs);

    std::cout << "Average sorting times (seconds) over " << runs << " runs:\n";
    std::cout << "Insertion Sort: " << insertion_time << " seconds\n";
    std::cout << "Selection Sort: " << selection_time << " seconds\n";
    std::cout << "Shell Sort: " << shell_time << " seconds\n";
    std::cout << "Binary Tree Sort: " << binary_tree_time << " seconds\n";

}

// My findings:
// 1. Insertion Sort (insertion_sort<int>)
// Time Complexity:
// Worst/Average Case: O(n²) (quadratic time)
// Best Case: O(n) (if the input is already sorted)

// Expected Performance:
// Since the input is randomly generated, the average case dominates.
// For n = 100,000, insertion sort will be very slow (likely several seconds per run) due to nested loops.
// Why? Each element may require shifting many elements to its correct position.



// 2. Selection Sort (selection_sort<int>)
// Time Complexity:
// Always O(n²) (even in the best case, it scans the entire unsorted part).

// Expected Performance:
// Similar to insertion sort but usually slower because it always performs ~n²/2 comparisons, even if the array is partially sorted.
// For n = 100,000, it will likely be slower than insertion sort because it does more swaps.



// 3. Shell Sort (shell_sort<int>)
// Time Complexity:
// Depends on the gap sequence (here, it uses n/2, n/4, ..., 1).
// Average Case: O(n^(3/2)) (better than quadratic but worse than O(n log n)).
// Best Case: O(n log n) (with optimal gap sequences like Sedgewick’s).

// Expected Performance:
// Much faster than insertion/selection sort due to reducing the number of comparisons with larger gaps.
// For n = 100,000, it should run in milliseconds rather than seconds.




// 4. Binary Tree Sort (BinaryTree<int>)
// Time Complexity:
// Insertion: O(n log n) average case (if the tree remains balanced).
// Worst Case: O(n²) (if the tree becomes a degenerate linked list).
// Traversal: O(n) (in-order traversal).

// Expected Performance:
// Faster than O(n²) sorts but slower than optimized O(n log n) sorts (like std::sort).
// Overhead from dynamic memory allocations (tree node creations).
// For n = 100,000, it should be faster than Shell Sort but not as fast as heap/merge/quick sorts.






// Algorithm	     Avg. Time (s)	Time Complexity	      Key Observations
// Insertion Sort	  20.044 s	       O(n²)	          Slowest, as expected for large datasets (100,000 elements). Performs better than Selection Sort due to fewer swaps in practice.
// Selection Sort	  33.9967 s     	O(n²)	          Consistently the worst performer—always scans the entire unsorted portion, leading to excessive comparisons/swaps.
// Shell Sort	      0.0522 s	     O(n^(3/2))	          ~400x faster than Insertion Sort due to gap-based optimization. Near O(n log n) performance with this gap sequence.
// Binary Tree Sort   0.0550 s	     O(n log n)avg.      	Comparable to Shell Sort but slightly slower due to tree construction overhead. Worst case (unbalanced tree) could degrade to O(n²).