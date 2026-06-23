#include <iostream>
#include <string>

using namespace std;

int main() {
    string strings[] = {"Hello", "World", "in", "a", "frame"};
    int numStrings = sizeof(strings) / sizeof(strings[0]);

    int maxLength = 0;
    for (int i = 0; i < numStrings; i++) {
        if (strings[i].length() > maxLength) {
            maxLength = strings[i].length();
        }
    }


    for (int i = 0; i < maxLength + 2; i++) {
        cout << "*";
    }
    cout << endl;


    for (int i = 0; i < numStrings; i++) {
        cout << "* ";
        cout << strings[i];
        for (int j = strings[i].length(); j < maxLength; j++) {
            cout << " ";
        }
        cout << " *" << endl;
    }


    for (int i = 0; i < maxLength + 2; i++) {
        cout << "*";
    }
    cout << endl;

    return 0;
}
