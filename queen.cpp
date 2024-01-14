#include <iostream>
using namespace std;

bool isValidWhiteQueenMove(int sourceRank, int sourceFile, int destRank, int destFile, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (1 to 8 for ranks, 'A' to 'H' for files)
    if (sourceRank < 1 || sourceRank > 8 || destRank < 1 || destRank > 8 || sourceFile < 1 || sourceFile > 8 || destFile < 1 || destFile > 8) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is along a rank, a file, or a diagonal
    int rankDifference = (destRank > sourceRank) ? (destRank - sourceRank) : (sourceRank - destRank);
    int fileDifference = (destFile > sourceFile) ? (destFile - sourceFile) : (sourceFile - destFile);

    if (sourceRank == destRank || sourceFile == destFile || rankDifference == fileDifference) {
        // Check if the path is clear
        if (isPathClearQueen(sourceRank, sourceFile, destRank, destFile, chessboard)) {
            // Check if the destination square is empty or contains a black piece
            if (chessboard[destRank - 1][destFile - 1] == ' ' || islower(chessboard[destRank - 1][destFile - 1])) {
                return true;
            } else {
                cout << "Invalid queen move. Destination square is occupied by a white piece." << endl;
            }
        } else {
            cout << "There is a piece in the queen's path." << endl;
        }
    } else {
        cout << "Invalid queen move." << endl;
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

    int sourceRank = 1;
    int sourceFile = 1;
    int destRank = 4;
    int destFile = 4;

    if (isValidWhiteQueenMove(sourceRank, sourceFile, destRank, destFile, chessboard)) {
        cout << "Valid move for the white queen." << endl;
    } else {
        cout << "Invalid move for the white queen." << endl;
    }

    return 0;
}
