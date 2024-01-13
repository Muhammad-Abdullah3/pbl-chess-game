#include <iostream>
using namespace std;
bool isPathClear(int frRow, int sourceFile, int destRank, int destFile, char chessboard[8][8]) {
    // Check if there are any pieces in the path
    if (frRow == destRank) {
        // Move along the same rank
        int startFile = min(sourceFile, destFile) + 1;
        int endFile = max(sourceFile, destFile);
        for (int file = startFile; file < endFile; ++file) {
            if (chessboard[frRow - 1][file - 1] != ' ') {
                return false; // Path is not clear
            }
        }
    } else if (sourceFile == destFile) {
        // Move along the same file
        int startRank = min(frRow, destRank) + 1;
        int endRank = max(frRow, destRank);
        for (int rank = startRank; rank < endRank; ++rank) {
            if (chessboard[rank - 1][sourceFile - 1] != ' ') {
                return false; // Path is not clear
            }
        }
    }

    return true; // Path is clear
}

bool isValidWhiteRookMove(int frRow, int sourceFile, int destRank, int destFile, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (1 to 8 for ranks, 'A' to 'H' for files)
    if (frRow < 1 || frRow > 8 || destRank < 1 || destRank > 8 || sourceFile < 1 || sourceFile > 8 || destFile < 1 || destFile > 8) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is along a rank or a file
    if (frRow == destRank || sourceFile == destFile) {
        // Check if the path is clear
        if (isPathClear(frRow, sourceFile, destRank, destFile, chessboard)) {
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
    int sourceFile = 1;
    int destRank = 5;
    int destFile = 1;

    if (isValidWhiteRookMove(frRow, sourceFile, destRank, destFile, chessboard)) {
        cout << "Valid move for the white rook." << endl;
    } else {
        cout << "Invalid move for the white rook." << endl;
    }

    return 0;
}
