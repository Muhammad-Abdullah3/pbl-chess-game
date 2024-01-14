#include <iostream>
using namespace std;
bool checkWhiteKnight(int frRow, int frCol, int toRow, int toCol, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for rows, 'A' to 'H' for coloumns)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is an L-shape (two squares in one dimension and one square in other dimension)
    int rowDifference = abs(toRow - frRow);
    int colDifference = abs(toCol - frCol);

    if ((rowDifference == 2 && colDifference == 1) || (rowDifference == 1 && colDifference == 2)) {
        // Check if the destination square is empty or contains a black piece
        if (chessboard[toRow][toCol] == ' ' || (chessboard[toRow][toCol]>='a'&&chessboard[toRow][toCol]<='z') )
        {
            return true;
        } else 
        {
            cout << "Invalid knight move. Destination square is occupied by a white piece." << endl;
        }
    } else 
    {
        cout << "Invalid knight move." << endl;
        return false;
    }
}

int main() {
    // Example usage with an empty chessboard
    char chessboard[8][8] = {
        {'R', 'N', 'B', 'Q', 'K','B', 'N', 'R'},
        {' ', 'B', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'R',' ','p','p', 'p' , 'p' , 'p' , 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    int frRow = 0;
    int frCol = 1;
    int toRow = 2;
    int toCol = 2;

    if (checkWhiteKnight(frRow, frCol, toRow, toCol,  chessboard)) {
        cout << "Valid move for the white knight." << endl;
    } else {
        cout << "Invalid move for the white knight." << endl;
    }

    return 0;
}
