#include <iostream>
using namespace std;

bool checkWhiteKing(int frRow, int frCol, int toRow, int toCol, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for rows, 'A' to 'H' for columns)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is one square in any direction
    int rankDifference = abs(toRow - frRow);
    int fileDifference = abs(toCol - frCol);

    if ((rankDifference == 1 && fileDifference == 0) || (rankDifference == 0 && fileDifference == 1) || (rankDifference == 1 && fileDifference == 1)) {
        // Check if the destination square is empty or contains a black piece
        if (chessboard[toRow][toCol] == ' ' || islower(chessboard[toRow][toCol])) {
            return true;
        } else {
            cout << "Invalid king move. Destination square is occupied by a white piece." << endl;
        }
    } else {
        cout << "Invalid king move." << endl;
    }

    return false;
}

int main() {
    // Example usage with an empty chessboard
    char chessboard[8][8] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    int frRow = 1;
    int frCol = 1;
    int toRow = 2;
    int toCol = 1;

    if (checkWhiteKing(frRow, frCol, toRow, toCol, chessboard)) {
        cout << "Valid move for the white king." << endl;
    } else {
        cout << "Invalid move for the white king." << endl;
    }

    return 0;
}
