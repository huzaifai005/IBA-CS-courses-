#include <iostream>
#include <vector>
#include <stdexcept>  

template<typename Key>
class OrderedSet {
private:
    std::vector<Key> data;

    int binary_search(const Key& key) const {
        int low = 0, high = int(data.size()) - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (data[mid] == key) return mid;
            else if (data[mid] < key) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int binary_search_ceiling(const Key& key) const {
        int low = 0, high = int(data.size()) - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (data[mid] >= key) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

    int binary_search_rank(const Key& key) const {
        int low = 0, high = int(data.size()) - 1;
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (data[mid] < key) {
                result = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

public:
    OrderedSet() {}

    void add(const Key& key) {
        if (data.empty()) {
            data.push_back(key);
            return;
        }
        int pos = binary_search_rank(key);
        if (pos < (int)data.size() && data[pos] == key) return;

        data.push_back(key);  
        for (int i = int(data.size()) - 1; i > pos; i--) {
            data[i] = data[i - 1];
        }
        data[pos] = key;
    }

    bool contains(const Key& key) const {
        return binary_search(key) != -1;
    }

    Key ceiling(const Key& key) const {
        int index = binary_search_ceiling(key);
        if (index == -1) {
            throw std::out_of_range("No ceiling found");
        }
        return data[index];
    }

    int rank(const Key& key) const {
        return binary_search_rank(key);
    }

    Key select(int i) const {
        if (i < 0 || i >= (int)data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[i];
    }

    Key min() const {
        if (data.empty()) {
            throw std::out_of_range("Set is empty");
        }
        return data[0];
    }

    void remove(const Key& key) {
        int pos = binary_search(key);
        if (pos == -1) return;

        for (int i = pos; i < (int)data.size() - 1; i++) {
            data[i] = data[i + 1];
        }
        data.pop_back();
    }

    void print() const {
        for (auto& x : data) std::cout << x << " ";
        std::cout << "\n";
    }
};

int main() {
    OrderedSet<int> s;

    s.add(10);
    s.add(5);
    s.add(20);
    s.add(15);

    s.print(); 

    std::cout << "Contains 10? " << s.contains(10) << "\n";
    std::cout << "Contains 7? " << s.contains(7) << "\n";

    try {
        int c = s.ceiling(12);
        std::cout << "Ceiling of 12: " << c << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "Rank of 15: " << s.rank(15) << "\n";

    try {
        int sel = s.select(2);
        std::cout << "Select(2): " << sel << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << "\n";
    }

    try {
        int minimum = s.min();
        std::cout << "Min: " << minimum << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << "\n";
    }

    s.remove(10);
    s.print(); 
}
