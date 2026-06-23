#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using std::string, std::vector, std::cout, std::endl;

string encrypt(const string &s)
{
    string t1 = "";
    string t2 = "";
    int i = 1;

    for (char c : s)
    {
        if (i % 2 == 1)
            t1 += c;

        if (i % 2 == 0)
            t2 += c;

        i++;
    }

    return t1 + t2;
}

string railFenceDecode(const string &encoded) {
    int length = encoded.length();
    int half = (length + 1) / 2; 

    string decoded = "";
    for (int i = 0; i < half; i++) {
        decoded += encoded[i]; 
        if (half + i < length) {
            decoded += encoded[half + i]; 
        }
    }
    return decoded;
}

int main()
{
    string text;
    cout << "Input text: ";
    std::getline(std::cin, text);

    string encoded = encrypt(text);
    cout << "Encoded text: " << encoded << endl;

    string encrypted;
    cout << "Enter the encrypted text: ";
    std::getline(std::cin, encrypted);

    string decoded = railFenceDecode(encrypted);
    cout << "Decoded text: " << decoded << endl;
}
