#include <iostream>

bool isSquareUnderAttack(int rank, int file, char attackingColor, char chessboard[8][8]) {
    // ... (Same as before)
    // The function remains the same as in the previous response
}

bool isWhiteKingInCheck(char chessboard[8][8]) {
    // ... (Same as before)
    // The function remains the same as in the previous response
}

bool isMoveLegal(int sourceRank, int sourceFile, int destRank, int destFile, char chessboard[8][8]) {
    char piece = chessboard[sourceRank - 1][sourceFile - 1];

    // Check if the move is within the chessboard boundaries
    if (destRank < 1 || destRank > 8 || destFile < 1 || destFile > 8) {
        return false;
    }

    // Check if the destination square is empty or contains an opponent's piece
    if (chessboard[destRank - 1][destFile - 1] == ' ' || (islower(piece) && isupper(chessboard[destRank - 1][destFile - 1]))) {
        return true;
    }

    return false;
}

bool isWhiteKingInCheckmate(char chessboard[8][8]) {
    int kingRank = -1;
    int kingFile = -1;

    // Find the position of the white king
    for (int rank = 1; rank <= 8; ++rank) {
        for (int file = 1; file <= 8; ++file) {
            if (chessboard[rank - 1][file - 1] == 'K') {
                kingRank = rank;
                kingFile = file;
                break;
            }
        }
        if (kingRank != -1) {
            break;
        }
    }

    // Check if the white king is in check
    if (kingRank != -1 && kingFile != -1 && isSquareUnderAttack(kingRank, kingFile, 'b', chessboard)) {
        // Check if there are any legal moves to get out of check
        for (int destRank = 1; destRank <= 8; ++destRank) {
            for (int destFile = 1; destFile <= 8; ++destFile) {
                if (isMoveLegal(kingRank, kingFile, destRank, destFile, chessboard) &&
                    !isSquareUnderAttack(destRank, destFile, 'b', chessboard)) {
                    return false; // There is at least one legal move to escape check
                }
            }
        }
        return true; // No legal moves to escape check (checkmate)
    }

    return false; // White king not in check or not found
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
        {' ', ' ', ' ', 'K', ' ', ' ', ' ', ' '}
    };

    if (isWhiteKingInCheckmate(chessboard)) {
        std::cout << "White king is in checkmate." << std::endl;
    } else {
        std::cout << "White king is not in checkmate." << std::endl;
    }

    return 0;
}
