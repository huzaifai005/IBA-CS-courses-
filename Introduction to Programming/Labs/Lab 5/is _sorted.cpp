#include <iostream>
int main () {
    bool isSorted = true;
     double values[6] {1.5, 4.3, 7.0, 19.5, 25.1, 46.2};
for (int i=0; i<5; i++) {
if (values[i]>=values[i+1]) {
    isSorted = false;
    break;
}
}
if (isSorted) {
    std::cout << "true";
}
    else {
        std::cout << "false";
    }
}

