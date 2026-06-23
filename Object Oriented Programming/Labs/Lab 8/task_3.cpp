#include<iostream>

class logger{
public:
    void log() {
    std::cout << std::endl;
    }

    template <typename T, typename... Args>
    void log(T item, Args... args) {
    std::cout << item << " ";
    log(args...);
    }
};

int main() {
    logger a; 
    a.log(2.1, 1, "Huzaifa", 'h', 7.0f);
}

//(1) logger.log(2.1, 1, "Huzaifa", 'h', 7.0f) ----------------------------------------- 2.1
// └── (2) logger.log(1, "Huzaifa", 'h', 7.0f) --------------------------------- 2.1 1
//      └── (3) logger.log("Huzaifa", 'h', 7.0f) ------------------------ 2.1 1 Huzaifa
//           └── (4) logger.log('h', 7.0f) -------------------- 2.1 1 Huzaifa h
//                └── (5) logger.log(7.0f) -------------- 2.1 1 Huzaifa h 7.0
//                     └── (6) logger.log() ------- 2.1 1 Huzaifa h 7.0 \n