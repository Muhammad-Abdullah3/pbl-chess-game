#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int boardSize = 8;

    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            // Print top boundary line of the square
            cout << "----";

            // Print vertical boundary line if not in the last column
            if (col < boardSize - 1) {
                cout << "|";
            }
        }
        cout << "\n"; // Move to the next line after each row

        // Print content of the square and bottom boundary line
        for (int col = 0; col < boardSize; ++col) {
            cout << ""; // Content of the square

            // Print vertical boundary line if not in the last column
            if (col == boardSize) {
                cout << "|";
            }
        }
        cout << "\n";
    }

    // Print the last row's bottom boundary line 
    for (int col = 0; col < boardSize; ++col) {
        cout << "-----";
    }
    cout << "-\n";
    return 0;
}
