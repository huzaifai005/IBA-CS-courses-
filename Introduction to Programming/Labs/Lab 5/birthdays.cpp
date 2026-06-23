#include<iostream>
#include<ctime>
int main () {
    std::srand(std::time(0));
    bool birthday[365] {false};
    int people = 0;
    double average;
    double sum = 0;
    double trials;
    std::cout << "Enter the number of trials: ";
    std::cin >> trials;
    for (int i = 0; i<=trials; i++) {
        people = 0;
    while(true) {
        int birthdays =std::rand()%365;
        if (birthday[birthdays]) {
            break;
        }
        birthdays[birthday] = true;
        people = people + 1;
    }
    sum = sum + people + 1;
    }
    average = sum/trials;
    std::cout << "average number of people until match: " << average;
}