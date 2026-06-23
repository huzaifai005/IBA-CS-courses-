#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int N;
    cout << "Enter the upper limit for prime numbers: ";
    cin >> N;

    bool prime[N+1];
    int count = 0;

   
    for (int i = 2; i <= N; i++) {
        prime[i] = true;
    }

   
    for (int p = 2; p * p <= N; p++) {
        if (prime[p]) {
   
            for (int i = p * p; i <= N; i += p) {
                prime[i] = false;
            }
        }
    }

   
    cout << "Prime numbers less than " << N << ":\n";
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            cout << i << " ";
            count++;
        }
    }
    cout << endl;

    cout << "Number of primes less than " << N << ": " << count << endl;

    return 0;
}

