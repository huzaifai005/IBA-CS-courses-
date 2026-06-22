#pragma once
#include "Percolation(quick-union).hpp"
#include<stdexcept>
#include<random>
#include<vector>
#include <cmath>
#include "stopwatch.hpp"

class PercolationStats {
private:
int n;
int t;
std::vector<double> result;

public:
    // perform independent trials on an n-by-n grid
    PercolationStats(int n, int trials) : n(n), t(trials) {
        if(n <= 0 || t <= 0) {
            throw std::invalid_argument("n and trials must be positive.");
        }

        for(int i = 0; i < t; i++) {
            Percolation p(n);

            while(!p.percolates()) {
                int row = rand() % n;
                int col = rand() % n;
                p.open(row, col);
            }

            double probability = static_cast<double>(p.numberOfOpenSites())/(n*n);
            result.push_back(probability);
        }
    }

    // sample mean of percolation threshold
    double mean() {
        double sum = 0.0;
        for(double r : result) {
            sum += r;
        }
        return sum/t;
   };

    // sample standard deviation of percolation threshold
    double stddev() {
        double meanValue = mean();
        double sum = 0.0;
        for(double r : result) {
            sum += (r - meanValue) * (r - meanValue);
        }
        return std::sqrt(sum / (t - 1));
    };

    // low endpoint of 95% confidence interval
    double confidenceLow() {
        double meanValue = mean();
        double stddevValue = stddev();
        return (meanValue - (1.96*stddevValue)/(std::sqrt(t)));

    }

    // high endpoint of 95% confidence interval
    double confidenceHigh() {
        double meanValue = mean();
        double stddevValue = stddev();
        return (meanValue + (1.96*stddevValue)/(std::sqrt(t)));
    }

    // test client
    static void test() {
    Stopwatch sw;
    PercolationStats stats(200, 100);
    double elapsed = sw.elapsedTime();

    std::cout << "> PercolationStats " << 200 << " " << 100 << "\n";
    std::cout << "mean() = " << stats.mean() << "\n";
    std::cout << "stddev() = " << stats.stddev() << "\n";
    std::cout << "confidenceLow() = " << stats.confidenceLow() << "\n";
    std::cout << "confidenceHigh() = " << stats.confidenceHigh() << "\n";
    std::cout << "elapsed time = " << elapsed << "\n";
    }
};