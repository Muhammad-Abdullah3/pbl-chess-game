#include <iostream>

bool checkDiagnolPath(int frRow, int frCol, int toRow, int toCol, char chessboard[8][8]) {
    int rankChange = toRow - frRow;
    int fileChange = toCol - frCol;

    int rankDirection = (rankChange > 0) ? 1 : -1;
    int fileDirection = (fileChange > 0) ? 1 : -1;

    int rank = frRow + rankDirection;
    int file = frCol + fileDirection;

    while (rank != toRow && file != toCol) {
        if (chessboard[rank - 1][file - 1] != ' ') {
            return false; // Path is not clear
        }

        rank += rankDirection;
        file += fileDirection;
    }

    return true; // Path is clear
}

bool isValidWhiteBishopMove(int frRow, int frCol, int toRow, int toCol, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (1 to 8 for ranks, 'A' to 'H' for files)
    if (frRow < 1 || frRow > 8 || toRow < 1 || toRow > 8 || frCol < 1 || frCol > 8 || toCol < 1 || toCol > 8) {
        std::cout << "Invalid chessboard position." << std::endl;
        return false;
    }

    // Check if the move is along a diagonal
    int rankDifference = (toRow > frRow) ? (toRow - frRow) : (frRow - toRow);
    int fileDifference = (toCol > frCol) ? (toCol - frCol) : (frCol - toCol);

    if (rankDifference == fileDifference) {
        // Check if the path is clear
        if (checkDiagnolPath(frRow, frCol, toRow, toCol, chessboard)) {
            // Check if the destination square is empty or contains a black piece
            if (chessboard[toRow - 1][toCol - 1] == ' ' || islower(chessboard[toRow - 1][toCol - 1])) {
                return true;
            } else {
                std::cout << "Invalid bishop move. Destination square is occupied by a white piece." << std::endl;
            }
        } else {
            std::cout << "There is a piece in the bishop's path." << std::endl;
        }
    } else {
        std::cout << "Invalid bishop move." << std::endl;
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
    int toRow = 4;
    int toCol = 4;

    if (isValidWhiteBishopMove(frRow, frCol, toRow, toCol, chessboard)) {
        std::cout << "Valid move for the white bishop." << std::endl;
    } else {
        std::cout << "Invalid move for the white bishop." << std::endl;
    }

    return 0;
}
