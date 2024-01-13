#include <iostream>
using namespace std;
bool isValidWhitePawnMove(int sourceRank, int sourceFile, int destRank, int destFile) {
    // Ensure the source and destination are within the chessboard boundaries (1 to 8 for ranks, 'A' to 'H' for files)
    if (sourceRank < 1 || sourceRank > 8 || destRank < 1 || destRank > 8 || sourceFile < 1 || sourceFile > 8 || destFile < 1 || destFile > 8) {
    cout << "Invalid chessboard position." <<endl;
        return false;
    }

    // Check if the destination is one square forward
    if (destRank == sourceRank + 1 && destFile == sourceFile) {
        return true;
    }

    // Check if the destination is two squares forward (only allowed if the pawn is in its starting position)
    if (sourceRank == 2 && destRank == sourceRank + 2 && destFile == sourceFile) {
        return true;
    }

    // Check if the destination is one square diagonally forward to capture an opponent's piece
    if (destRank == sourceRank + 1 && (destFile == sourceFile + 1 || destFile == sourceFile - 1)) {
        return true;
    }

    // If none of the above conditions are met, the move is invalid
    cout << "Invalid pawn move." << endl;
    return false;
}

int main() {
    // Example usage
    int sourceRank = 2;
    int sourceFile = 3;
    int destRank = 3;
    int destFile = 3;

    if (isValidWhitePawnMove(sourceRank, sourceFile, destRank, destFile)) {
        cout << "Valid move for the white pawn." << endl;
    } else {
        cout << "Invalid move for the white pawn." << endl;
    }

    return 0;
}
