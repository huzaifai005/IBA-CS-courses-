#include<iostream>
#include<ctime>
int main () {
    std::srand(std::time(0));
    bool birthday[365] {false};
    int people = 0;
    while(true) {
        int birthdays =std::rand()%365;
        if (birthday[birthdays]) {
            break;
        }
        birthdays[birthday] = true;
        people = people + 1;
    }
    std::cout << "number of people until a match: " << people + 1;
}