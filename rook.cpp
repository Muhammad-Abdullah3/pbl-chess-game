#include <iostream>
using namespace std;
bool isPathClear(int frRow, int frCol, int toRow, int toCol, char chessboard[8][8]) {
    // Check if there are any pieces in the path
    if (frRow == toRow) {
        // Move along the same rank
        int startFile = min (frCol, toCol) + 1;
        int endFile = max (frCol, toCol);
        for (int file = startFile; file < endFile; ++file) {
            if (chessboard[frRow - 1][file - 1] != ' ') {
                return false; // Path is not clear
            }
        }
    } else if (frCol == toCol)  {
        // Move along the same file
        int startRank = min(frRow, toRow) + 1;
        int endRank = max(frRow, toRow);
        for (int rank = startRank; rank < endRank; ++rank) {
            if (chessboard[rank - 1] [frCol - 1] != ' ') {
                return false; // Path is not clear
            }
        }
    }

    return true; // Path is clear
}

bool isValidWhiteRookMove(int frRow, int frCol, int toRow, int toCol, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (1 to 8 for ranks, 'A' to 'H' for files)
    if (frRow < 1 || frRow > 8 || toRow < 1 || toRow > 8 || frCol < 1 || frCol > 8 || toCol < 1 || toCol > 8) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is along a rank or a file
    if (frRow == toRow || frCol == toCol) {
        // Check if the path is clear
        if (isPathClear(frRow, frCol, toRow, toCol, chessboard)) {
            return true;
        } else {
            cout << "There is a piece in the rook's path." << endl;
        }
    } else {
        cout << "Invalid rook move." << endl;
    }

    return false;
}

int main() {
    // Example usage with an empty chessboard
    char chessboard[8][8] = {
        {'R', 'N', 'B', 'Q', 'K','B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p','p','p','p', 'p' , 'p' , 'p' , 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    int frRow = 1;
    int frCol = 1;
    int toRow = 5;
    int toCol = 1;

    if (isValidWhiteRookMove(frRow, frCol, toRow, toCol, chessboard)) {
        cout << "Valid move for the white rook." << endl;
    } else {
        cout << "Invalid move for the white rook." << endl;
    }

    return 0;
}
