#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using std::string, std::vector, std::cout; 

string scramble(const string &s) {
    string word = s;
    for (int i = 1; i < word.size()-1; i++) {
double u = rand()/((double)RAND_MAX+1);
int r = i + (int) (u * (word.size()-1-i));
char t = word[r];
word[r] = word[i];
word[i] = t;
}

return word;

}

int main() {
    string text;
    cout<<"Input text: ";
    std::getline(std::cin, text);

    vector<string> t;
    for (int i = 0; i < text.size(); i++) {
        if(!(text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z')) {
            t.push_back(text.substr(0, i));
            text.erase(0, i+1);
            i = 0;
        }

        if(i==text.size()-1) t.push_back(text);
    }

    for(string s : t) {
        std::cout << scramble(s)<< " ";
    }
}