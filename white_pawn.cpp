#include <iostream>
using namespace std;
bool isValidWhitePawnMove(int frRow, int frCol, int toRow, int toCol) {
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for ranks, 'A' to 'H' for files)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
    cout << "Invalid chessboard position." <<endl;
        return false;
    }

    // Check if the destination is one square forward
    if (toRow == frRow + 1 && toCol == frCol) {
        return true;
    }

    // Check if the destination is two squares forward (only allowed if the pawn is in its starting position)
    if (frRow == 1 && toRow == frRow + 1 && toCol == frCol) {
        return true;
    }

    // Check if the destination is one square diagonally forward to capture an opponent's piece
    if (toRow == frRow + 1 && (toCol == frCol + 1 || toCol == frCol - 1)) {
        return true;
    }

    // If none of the above conditions are met, the move is invalid
    cout << "Invalid pawn move." << endl;
    return false;
}

int main() {
    // Example usage with an empty chessboard
    char chessboard[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p','p','p','p', 'p' , 'p' , 'p' , 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
    // Example usage
    int frRow = 2;
    int frCol = 3;
    int toRow = 3;
    int toCol = 3;

    if (isValidWhitePawnMove(frRow, frCol, toRow, toCol)) {
        cout << "Valid move for the white pawn." << endl;
    } else {
        cout << "Invalid move for the white pawn." << endl;
    }

    return 0;
}
