#include <iostream>
using namespace std;

bool checkWhiteKing(int frRow, int frCol, int toRow, int toCol, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for rows, 'A' to 'H' for columns)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is one square in any direction
    int rowDifference = abs(toRow - frRow);
    int colDifference = abs(toCol - frCol);

    if ((rowDifference == 1 && colDifference == 0) || (rowDifference == 0 && colDifference == 1) || (rowDifference == 1 && colDifference == 1)) 
    {
        // Check if the destination square is empty or contains a black piece
        if (chessboard[toRow][toCol] == ' ' || (chessboard[toRow][toCol]>='a'&&chessboard[toRow][toCol]<='z')) 
        {
            return true;
        } else 
        {
            cout << "Invalid king move. Destination square is occupied by a white piece." << endl;
        }
    } else 
    {
        cout << "Invalid king move." << endl;
    }

    return false;
}

int main() {
    // Example usage with an empty chessboard
    char chessboard[8][8] = {
        {'R', 'N', 'B', ' ', 'K','q', 'N', 'R'},
        {' ', 'B', 'P', ' ', 'p', 'n', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'R',' ','p','p', 'p' , 'p' , 'p' , 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    int frRow = 0;
    int frCol = 4;
    int toRow = 1;
    int toCol = 5;

    if (checkWhiteKing(frRow, frCol, toRow, toCol, chessboard)) {
        cout << "Valid move for the white king." << endl;
    } else {
        cout << "Invalid move for the white king." << endl;
    }

    return 0;
}
