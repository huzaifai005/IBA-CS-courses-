#include <iostream>
#include <string>
using namespace std;

bool isAnagram (const string& a, const string& b) {
    int counta = 0;
    int countb = 0;

    for (char c : a) {
        if((c>='a' && c<='z') || (c>='A' && c<='Z')) counta++;
    }


    for (char c : b) {
        if((c>='a' && c<='z') || (c>='A' && c<='Z')) countb++;
    }

    if (counta != countb) {
        return false;
    }

    bool charCheck1 [26] = {false};
    bool charCheck2 [26] = {false};

    for (char c : a) {
        if (isalpha(c)) charCheck1[tolower(c) - 'a'] = true;
    }

    for (char c : b) {
        if (isalpha(c)) charCheck2[tolower(c) - 'a'] = true;
    }

     for (int i = 0; i < 26; i++) {
        if (charCheck1[i] != charCheck2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string input1, input2;
    cout << "Enter the first string: ";
    getline(cin, input1);

    cout << "Enter the second string: ";
    getline(cin, input2);

    if (isAnagram(input1, input2)) {
        cout << "The two strings are anagrams." << endl;
    } else {
        cout << "The two strings are not anagrams." << endl;
    }
}