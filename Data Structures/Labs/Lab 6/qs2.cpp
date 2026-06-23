#include <iostream>
#include <list>
#include <map>

class LRU {
private:
std::list<int> accesslist;
std::map<int, std::list<int>::iterator> item;

public:
LRU() = default;

void access(int items) {
    if (contains(items)) {
        accesslist.erase(item[items]);
    }
    accesslist.push_front(items);
        item[items] = accesslist.begin();
}
    
int remove() {
    if (empty()) {
        throw std::runtime_error("Cannot remove from empty cache");
    }
    int lruItem = accesslist.back();
    accesslist.pop_back();
    item.erase(lruItem);
    return lruItem;
}
        
bool contains(int items) const {
    return item.find(items) != item.end();
}
        
size_t size() const {
    return accesslist.size();
}

bool empty() const {
    return accesslist.empty();
}
    
void print() const {
    for (const auto& item : accesslist) {
        std::cout << item << " ";
    }
}
};

int main() {
LRU cache;
cache.access(10); cache.access(20); cache.access(30);
std::cout << "Cache after 10,20,30: "; cache.print(); // Expected: 30 20 10
cache.access(20); // move 20 to front
std::cout << "After accessing 20: "; cache.print(); // Expected: 20 30 10
std::cout << "Remove LRU = " << cache.remove() << std::endl;
std::cout << "Cache after remove: "; cache.print(); // Expected: 20 30
std::cout << "Contains 10? " << cache.contains(10) << "\n"; // Expected: 0 (false)
std::cout << "Size = " << cache.size() << "\n"; // Expected: Size = 2
std::cout << "Empty = " << cache.empty() << "\n"; // Expected: Empty = 0 (false)
}