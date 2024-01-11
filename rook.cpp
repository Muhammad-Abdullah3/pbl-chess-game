#include <iostream>

bool isPathClear(int sourceRank, int sourceFile, int destRank, int destFile, char chessboard[8][8]) {
    // Check if there are any pieces in the path
    if (sourceRank == destRank) {
        // Move along the same rank
        int startFile = std::min(sourceFile, destFile) + 1;
        int endFile = std::max(sourceFile, destFile);
        for (int file = startFile; file < endFile; ++file) {
            if (chessboard[sourceRank - 1][file - 1] != ' ') {
                return false; // Path is not clear
            }
        }
    } else if (sourceFile == destFile) {
        // Move along the same file
        int startRank = std::min(sourceRank, destRank) + 1;
        int endRank = std::max(sourceRank, destRank);
        for (int rank = startRank; rank < endRank; ++rank) {
            if (chessboard[rank - 1][sourceFile - 1] != ' ') {
                return false; // Path is not clear
            }
        }
    }

    return true; // Path is clear
}

bool isValidWhiteRookMove(int sourceRank, int sourceFile, int destRank, int destFile, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (1 to 8 for ranks, 'A' to 'H' for files)
    if (sourceRank < 1 || sourceRank > 8 || destRank < 1 || destRank > 8 || sourceFile < 1 || sourceFile > 8 || destFile < 1 || destFile > 8) {
        std::cout << "Invalid chessboard position." << std::endl;
        return false;
    }

    // Check if the move is along a rank or a file
    if (sourceRank == destRank || sourceFile == destFile) {
        // Check if the path is clear
        if (isPathClear(sourceRank, sourceFile, destRank, destFile, chessboard)) {
            return true;
        } else {
            std::cout << "There is a piece in the rook's path." << std::endl;
        }
    } else {
        std::cout << "Invalid rook move." << std::endl;
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
    int destRank = 5;
    int destFile = 1;

    if (isValidWhiteRookMove(sourceRank, sourceFile, destRank, destFile, chessboard)) {
        std::cout << "Valid move for the white rook." << std::endl;
    } else {
        std::cout << "Invalid move for the white rook." << std::endl;
    }

    return 0;
}
