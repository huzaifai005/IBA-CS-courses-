#include <iostream>
using namespace std;

int evenDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int digit = n % 10;
    int rem = evenDigits(n / 10);

    if (digit % 2 == 0)
    {
        if (rem == 0 && digit != 0)
        {
            return digit;
        }
        return rem * 10 + digit;
    }

    return rem;
}

int main()
{
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Result: " << evenDigits(n) << "\n";
}
