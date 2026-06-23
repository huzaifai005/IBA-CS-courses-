
#include <iostream>
#include <vector>
#include <string>
#include <cctype>


template <typename T>
class Pipeline {
private:
    std::vector<T(*)(T)> function; 

public:
    
    void add(T (*func)(T)) {
        function.push_back(func);
    }

    
    T run(T value, bool a = false) {
        for (int i = 0; i < function.size(); i++) {
            value = function[i](value);
            if (a) {
                std::cout << "Step " << i + 1 << ": " << value << std::endl;
            }
        }
        return value;
    }
};

int add1(int x) {
    return x + 1;
}

int doubled(int x) {
    return x * 2;
}

int squared(int x) {
    return x * x;
}

std::string uppercase(std::string a) {
    for (int i = 0; i < a.length(); i++) {
        a[i] = toupper(a[i]);
    }
    return a;
}

std::string exclamation(std::string a) {
    return a + "!";
}

int main() {
    Pipeline<int> p1;
    p1.add(add1);
    p1.add(doubled);
    p1.add(squared);

    std::cout << "Integer pipeline:" << std::endl;
    int result = p1.run(5, true);
    std::cout << "Final result (int): " << result << "\n\n";

   
    Pipeline<std::string> p2;
    p2.add(uppercase);
    p2.add(exclamation);

    std::cout << "String pipeline:\n";
    std::string result2 = p2.run("hello", true);
    std::cout << "Final result (string): " << result2 << std::endl;
}
