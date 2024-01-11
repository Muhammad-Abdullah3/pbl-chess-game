#include <iostream>

bool isValidWhiteKnightMove(int sourceRank, int sourceFile, int destRank, int destFile, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (1 to 8 for ranks, 'A' to 'H' for files)
    if (sourceRank < 1 || sourceRank > 8 || destRank < 1 || destRank > 8 || sourceFile < 1 || sourceFile > 8 || destFile < 1 || destFile > 8) {
        std::cout << "Invalid chessboard position." << std::endl;
        return false;
    }

    // Check if the move is an L-shape (two squares in one direction and one square perpendicular)
    int rankDifference = std::abs(destRank - sourceRank);
    int fileDifference = std::abs(destFile - sourceFile);

    if ((rankDifference == 2 && fileDifference == 1) || (rankDifference == 1 && fileDifference == 2)) {
        // Check if the destination square is empty or contains a black piece
        if (chessboard[destRank - 1][destFile - 1] == ' ' || islower(chessboard[destRank - 1][destFile - 1])) {
            return true;
        } else {
            std::cout << "Invalid knight move. Destination square is occupied by a white piece." << std::endl;
        }
    } else {
        std::cout << "Invalid knight move." << std::endl;
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
    int destRank = 3;
    int destFile = 2;

    if (isValidWhiteKnightMove(sourceRank, sourceFile, destRank, destFile, chessboard)) {
        std::cout << "Valid move for the white knight." << std::endl;
    } else {
        std::cout << "Invalid move for the white knight." << std::endl;
    }

    return 0;
}
