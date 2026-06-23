#include <iostream>
#include <string>
using namespace std;

string scytaleEncode(const string &text, int k) {
    string encoded = "";
    for (int i = 0; i < k; i++) { 
        for (int j = i; j < text.length(); j += k) {
            encoded += text[j];
        }
    }
    return encoded;
}

string scytaleDecode(const string &encoded, int k) {
    size_t length = encoded.length();
    int cols = (length + k - 1) / k; 
    string decoded(length, ' '); 

    size_t index = 0;
    for (int i = 0; i < k; i++) { 
        for (int j = i; j < length; j += k) { 
            decoded[j] = encoded[index++];
        }
    }
    return decoded;
}

int main() {
    string input;
    int k;

    cout << "Enter the text to encode: ";
    getline(cin, input);
    cout << "Enter the value of k (number of rows): ";
    cin >> k;

    string encoded = scytaleEncode(input, k);
    cout << "Encoded text: " << encoded << endl;

    string encrypt;
    int n;

    cout << "Enter the encrypt text: ";
    cin.ignore();
    getline(cin, encrypt);
    cout << "Enter the value of n (number of rows): ";
    cin >> n;

    string decoded = scytaleDecode(encrypt, n);
    cout << "Decoded text: " << decoded << endl;
}
