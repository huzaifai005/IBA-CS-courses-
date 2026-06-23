#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    if (m == 0)
    {
        return n;
    }
    else if (n == 0)
    {
        return m;
    }
    else if (m > n)
    {
        return gcd(n, m);
    }
    else
    {
        return gcd(n - m, m);
    }
}

int main()
{
    int m, n;

    cout << "Enter two positive integers (m < n): ";
    cin >> m >> n;

    int result = gcd(m, n);
    cout << "The greatest common divisor of " << m << " and " << n << " is " << result << "\n";
}
