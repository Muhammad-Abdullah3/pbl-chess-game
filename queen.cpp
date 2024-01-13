#include <iostream>

bool isPathClearQueen(int sourceRank, int sourceFile, int destRank, int destFile, char chessboard[8][8]) {
    int rankChange = destRank - sourceRank;
    int fileChange = destFile - sourceFile;

    int rankDirection = (rankChange > 0) ? 1 : (rankChange < 0) ? -1 : 0;
    int fileDirection = (fileChange > 0) ? 1 : (fileChange < 0) ? -1 : 0;

    int rank = sourceRank + rankDirection;
    int file = sourceFile + fileDirection;

    while (rank != destRank || file != destFile) {
        if (chessboard[rank - 1][file - 1] != ' ') {
            return false; // Path is not clear
        }

        rank += rankDirection;
        file += fileDirection;
    }

    return true; // Path is clear
}

bool isValidWhiteQueenMove(int sourceRank, int sourceFile, int destRank, int destFile, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (1 to 8 for ranks, 'A' to 'H' for files)
    if (sourceRank < 1 || sourceRank > 8 || destRank < 1 || destRank > 8 || sourceFile < 1 || sourceFile > 8 || destFile < 1 || destFile > 8) {
        std::cout << "Invalid chessboard position." << std::endl;
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
                std::cout << "Invalid queen move. Destination square is occupied by a white piece." << std::endl;
            }
        } else {
            std::cout << "There is a piece in the queen's path." << std::endl;
        }
    } else {
        std::cout << "Invalid queen move." << std::endl;
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
        std::cout << "Valid move for the white queen." << std::endl;
    } else {
        std::cout << "Invalid move for the white queen." << std::endl;
    }

    return 0;
}