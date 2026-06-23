#include <iostream>

using namespace std;

int main() {
    int treasureMap[5][5] = {
        {34, 21, 32, 41, 25},
        {14, 42, 43, 14, 31},
        {54, 45, 52, 42, 23},
        {33, 15, 51, 31, 35},
        {21, 52, 33, 13, 23}
    };

    int currentRow = 0;
    int currentCol = 0;

    cout << "Visited cells: ";

    while (true) {
        cout << "(" << currentRow + 1 << ", " << currentCol + 1 << ") ";

        int clue = treasureMap[currentRow][currentCol];
        int nextRow = (clue / 10) - 1;
        int nextCol = (clue % 10) - 1;

        if (nextRow == currentRow && nextCol == currentCol) {
            cout << endl << "Treasure found at (" << nextRow + 1 << ", " << nextCol + 1 << ")" << endl;
            break;
        }

        currentRow = nextRow;
        currentCol = nextCol;
    }

    return 0;
}
