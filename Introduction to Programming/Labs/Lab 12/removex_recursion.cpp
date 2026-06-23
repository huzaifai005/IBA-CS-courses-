#include <iostream>
using namespace std;

string removeX(const string &s)
{
    if (s.empty())
    {
        return "";
    }
    else if (s[0] == 'x')
    {
        return removeX(s.substr(1));
    }
    else
    {
        return s[0] + removeX(s.substr(1));
    }
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string result = removeX(input);
    cout << "String after removing 'x': " << result << "\n";
}
