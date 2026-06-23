#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    srand(time(0));

    int permutation[N];

    for (int i = 0; i < N; i++) {
        permutation[i] = i;
    }

    for (int i = N - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        std::swap(permutation[i], permutation[j]);
    }

    cout << "Random permutation: ";
    for (int i = 0; i < N; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;

    cout << "Checkerboard visualization:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (permutation[j] == i) {
                cout << "Q ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }

    return 0;
}
