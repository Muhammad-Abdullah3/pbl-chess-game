#include <iostream>
using namespace std;

bool isSquareUnderAttack(int rank, int file, char attackingColor, char chessboard[8][8]) {
    // Check if the square is attacked by a pawn
    if (attackingColor == 'b') 
    {
        if (rank - 1 >= 1 && (file - 1 >= 1 && chessboard[rank - 1][file - 1] == 'p') || (file + 1 <= 8 && chessboard[rank - 1][file + 1] == 'p')) {
            return true;
        }
    }

    // Check if the square is attacked by a knight
    int knightMoves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    for (int i = 0; i < 8; ++i) {
        int newRow = rank + knightMoves[i][0];
        int newCol = file + knightMoves[i][1];
        if (newRow >= 1 && newRow <= 8 && newCol >= 1 && newCol <= 8 && chessboard[newRow - 1][newCol - 1] == 'n') {
            return true;
        }
    }

    // Check if the square is attacked along ranks, files, or diagonals by a queen or a rook
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j <= 8; ++j) {
            int newRow = rank + j * directions[i][0];
            int newCol = file + j * directions[i][1];

            if (newRow < 1 || newRow > 8 || newCol < 1 || newCol > 8) {
                break; // Out of the board
            }

            char piece = chessboard[newRow - 1][newCol - 1];
            if (piece == 'q' || piece == 'r') {
                return true; // The square is attacked by a queen or a rook
            } else if (piece != ' ') {
                break; // There is a piece in the way
            }
        }
    }

    // Check if the square is attacked along diagonals by a queen or a bishop
    int diagonalDirections[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}}; // NE, NW, SW, SE
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j <= 8; ++j) {
            int newRow = rank + j * diagonalDirections[i][0];
            int newCol = file + j * diagonalDirections[i][1];

            if (newRow < 1 || newRow > 8 || newCol < 1 || newCol > 8) {
                break; // Out of the board
            }

            char piece = chessboard[newRow - 1][newCol - 1];
            if (piece == 'q' || piece == 'b') {
                return true; // The square is attacked by a queen or a bishop
            } else if (piece != ' ') {
                break; // There is a piece in the way
            }
        }
    }

    // Check if the square is attacked by a king
    int kingMoves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 8; ++i) {
        int newRow = rank + kingMoves[i][0];
        int newCol = file + kingMoves[i][1];
        if (newRow >= 1 && newRow <= 8 && newCol >= 1 && newCol <= 8 && chessboard[newRow - 1][newCol - 1] == 'k') {
            return true;
        }
    }

    return false; // The square is not attacked
}

bool isWhiteKingInCheck(char chessboard[8][8]) {
    int kingRank = -1;
    int kingFile = -1;

    // Find the position of the white king
    for (int rank = 1; rank <= 8; ++rank) {
        for (int file = 1; file <= 8; ++file) 
        {
            if (chessboard[rank - 1][file - 1] == 'K') {
                kingRank = rank;
                kingFile = file;
                break;
            }
        }
        if (kingRank != -1) 
        {
            break;
        }
    }

    // Check if the white king is in check
    if (kingRank != -1 && kingFile != -1) 
    {
        return isSquareUnderAttack(kingRank, kingFile, 'b', chessboard);
    }
    return false; // White king not found
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
        {' ', ' ', ' ', 'K', ' ', ' ', ' ', ' '}
    };

    if (isWhiteKingInCheck(chessboard)) {
        cout << "White king is in check." << endl;
    } else {
        cout << "White king is not in check." << endl;
    }

    return 0;
}
