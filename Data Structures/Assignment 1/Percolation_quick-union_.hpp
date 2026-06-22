#pragma once 
#include<iostream>
#include<vector>
#include <stdexcept>


class WQU {
private:
    int n;
    int* parent;
    std::vector<int> size;
public:
    WQU(int s) : n{s}, parent{new int[n]}, size(s, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    ~WQU() { 
        delete[] parent; 
    }

    int find(int p) {
        while (p != parent[p])
        p = parent[p];
        return p;
    };

    void unify(int p, int q) {
        int root1 = find(p);
        int root2 = find(q);
        if (root1 == root2) {
            return;
        }
        if (size[root1] > size[root2]) {
            int temp = root1; root1 = root2; root2 = temp; 
        }
        parent[root1] = root2;
        size[root2] += size[root1];

    };
};


class Percolation {
private: 
    int n;
    std::vector<std::vector<bool>> grid;
    WQU qu;
    int virtualTop;
    int virtualBottom;
    int count;

    bool boundaryCheck(int row, int col) {
        return (row < 0 || row > n - 1 || col < 0 || col > n - 1);
    }

public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation(int n) : n(n), grid(n, std::vector<bool>(n, false)), qu(n*n+2), virtualTop(n*n), virtualBottom(n*n+1), count(0) {
        if(n<=0) {
            throw std::invalid_argument("dimensions can not be negative.");
        }
    }

    // opens the site (row, col) if it is not open already
    void open(int row, int col) {
        if(row < 0 || row > n-1 || col < 0 || col > n-1) {
            throw std::invalid_argument("out of bounds");
        }

         if (isOpen(row, col)) {
            return;
        }
        
        grid[row][col] = true;

        int idx = row * n + col; 

        if(!boundaryCheck(row, col + 1)) {
            if (isOpen(row, col + 1)) {
                qu.unify(idx, row*n + col+1);
            }
        }

        if(!boundaryCheck(row, col - 1)) {
            if(isOpen(row, col - 1)) {
                qu.unify(idx, row*n + col-1);
            }
        }

        if(!boundaryCheck(row + 1, col)) {
            if(isOpen(row + 1, col)) {
                qu.unify(idx, (row+1)*n + col);
            }
        }

        if(!boundaryCheck(row - 1, col)) {
            if(isOpen(row - 1, col)) {
                qu.unify(idx, (row-1)*n + col);
            }
        }

        if(row==0) {
            qu.unify(idx, virtualTop);
        }
        if(row==n-1) {
            qu.unify(idx, virtualBottom);
        }
        count++;
    }

    // is the site (row, col) open?
    bool isOpen(int row, int col) {
        if(row < 0 || row > n-1 || col < 0 || col > n-1) {
            throw std::invalid_argument("out of bounds");
        }
        return grid[row][col];
    }
    
    // is the site (row, col) full?
    bool isFull(int row, int col) {
        if(isOpen(row, col)) {
            if(qu.find(row*n+col)==qu.find(virtualTop)) {
                return true;
            }
        }
        return false;
    }
    
    // returns the number of open sites
    int numberOfOpenSites() {
        return count;
    }
    
    // does the system percolate?
    bool percolates() {
        return (qu.find(virtualTop) == qu.find(virtualBottom));
    }
    
    // unit testing (required)
    static void test() {
    std::cout << "===== COMPREHENSIVE UNIT TEST - Testing ALL Public Methods =====" << std::endl;
    
    // Test 1: Constructor - normal case
    std::cout << "\n1. Testing Constructor (valid input):" << std::endl;
    Percolation p(3);
    std::cout << "    Percolation(3) created successfully" << std::endl;

    // Test 2: Constructor - error case
    std::cout << "\n2. Testing Constructor (invalid input):" << std::endl;
    try {
        Percolation p_invalid(0);
        std::cout << "    ERROR: Should have thrown exception!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "    Correctly threw exception: " << e.what() << std::endl;
    }

    // Test 3: isOpen() - on blocked sites
    std::cout << "\n3. Testing isOpen() on blocked sites:" << std::endl;
    std::cout << "   isOpen(0,0): " << p.isOpen(0, 0) << " (should be 0/false)" << std::endl;
    std::cout << "   isOpen(1,1): " << p.isOpen(1, 1) << " (should be 0/false)" << std::endl;
    std::cout << "   isOpen(2,2): " << p.isOpen(2, 2) << " (should be 0/false)" << std::endl;

    // Test 4: numberOfOpenSites() - initial state
    std::cout << "\n4. Testing numberOfOpenSites() initially:" << std::endl;
    std::cout << "   numberOfOpenSites(): " << p.numberOfOpenSites() << " (should be 0)" << std::endl;

    // Test 5: isFull() - on blocked sites
    std::cout << "\n5. Testing isFull() on blocked sites:" << std::endl;
    std::cout << "   isFull(0,0): " << p.isFull(0, 0) << " (should be 0/false)" << std::endl;
    std::cout << "   isFull(1,1): " << p.isFull(1, 1) << " (should be 0/false)" << std::endl;

    // Test 6: percolates() - initially
    std::cout << "\n6. Testing percolates() initially:" << std::endl;
    std::cout << "   percolates(): " << p.percolates() << " (should be 0/false)" << std::endl;

    // Test 7: open() - normal case
    std::cout << "\n7. Testing open() method:" << std::endl;
    p.open(0, 0);
    std::cout << "    Opened site (0,0)" << std::endl;
    p.open(1, 0);
    std::cout << "    Opened site (1,0)" << std::endl;
    p.open(2, 0);
    std::cout << "    Opened site (2,0)" << std::endl;

    // Test 8: isOpen() - on opened sites
    std::cout << "\n8. Testing isOpen() on opened sites:" << std::endl;
    std::cout << "   isOpen(0,0): " << p.isOpen(0, 0) << " (should be 1/true)" << std::endl;
    std::cout << "   isOpen(1,0): " << p.isOpen(1, 0) << " (should be 1/true)" << std::endl;
    std::cout << "   isOpen(2,0): " << p.isOpen(2, 0) << " (should be 1/true)" << std::endl;

    // Test 9: numberOfOpenSites() - after opening sites
    std::cout << "\n9. Testing numberOfOpenSites() after opening:" << std::endl;
    std::cout << "   numberOfOpenSites(): " << p.numberOfOpenSites() << " (should be 3)" << std::endl;

    // Test 10: isFull() - on opened connected sites
    std::cout << "\n10. Testing isFull() on connected sites:" << std::endl;
    std::cout << "   isFull(0,0): " << p.isFull(0, 0) << " (should be 1/true)" << std::endl;
    std::cout << "   isFull(1,0): " << p.isFull(1, 0) << " (should be 1/true)" << std::endl;
    std::cout << "   isFull(2,0): " << p.isFull(2, 0) << " (should be 1/true)" << std::endl;

    // Test 11: percolates() - after creating a path
    std::cout << "\n11. Testing percolates() with connected path:" << std::endl;
    std::cout << "   percolates(): " << p.percolates() << " (should be 1/true)" << std::endl;

    // Test 12: open() - error case
    std::cout << "\n12. Testing open() with invalid coordinates:" << std::endl;
    try {
        p.open(5, 2);
        std::cout << "    ERROR: Should have thrown exception!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "    Correctly threw exception: " << e.what() << std::endl;
    }

    // Test 13: isOpen() - error case
    std::cout << "\n13. Testing isOpen() with invalid coordinates:" << std::endl;
    try {
        p.isOpen(-1, 1);
        std::cout << "    ERROR: Should have thrown exception!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "    Correctly threw exception: " << e.what() << std::endl;
    }

    // Test 14: isFull() - error case
    std::cout << "\n14. Testing isFull() with invalid coordinates:" << std::endl;
    try {
        p.isFull(3, 3);
        std::cout << "    ERROR: Should have thrown exception!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "    Correctly threw exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== UNIT TEST COMPLETE - All public methods tested =====" << std::endl;
}
};
