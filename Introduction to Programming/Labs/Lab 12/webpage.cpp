#include <iostream>
#include <vector>
#include <string>

using std::string, std::vector, std::cout;

vector<string> split(const string &s)
{
    vector<string> words = {};
    string web = s;
    int slashInd = web.find('/');
    web.erase(0, slashInd + 2);

    for (int i = 0; i < web.size(); i++)
    {
        if (web[i] == '.')
        {
            words.push_back(web.substr(0, i));
            web.erase(0, i+1);
            i = 0;
        }

        if(i==web.size()-1) words.push_back(web);
    }
    return words;
}

int main()
{
    string web = "http://www.cs.princeton.edu";
    vector<string> pieces = split(web);
        for (int i = 0; i <pieces.size(); i++ ) {
            cout<<pieces[i]<<" ";
        }
}