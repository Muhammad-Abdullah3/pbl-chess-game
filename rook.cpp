#include <iostream>
using namespace std;
bool checkLinearPath(int frRow, int frCol, int toRow, int toCol, char chessboard[8][8]) {
    // Check if there are any pieces in the path
    if (frRow == toRow) 
    {
        // Move along the same row
        if(frCol>toCol)
        {
            for (int col = frCol+1; col < toCol; ++col) 
            {
                if (chessboard[frRow][col] != ' ') 
                {
                return false; // Path is not clear
                }
            }
        }
        else
        {
            for (int col = frCol-1; col > toCol; --col) 
            {
                if (chessboard[frRow][col] != ' ') 
                {
                return false; // Path is not clear
                }
            }
        }
    } else if (frCol == toCol)  
    {
        // Move along the same column
        if(frRow>toRow)
        {
            for (int row = frRow+1; row < toRow; ++row) 
            {
                if (chessboard[row][frCol] != ' ') 
                {
                return false; // Path is not clear
                }
            }
        }
        else
        {
            for (int row = frRow-1; row > toRow; --row) 
            {
                if (chessboard[row][frRow] != ' ') 
                {
                return false; // Path is not clear
                }
            }
        }
    }

    return true; // Path is clear
}

bool isValidWhiteRookMove(int frRow, int frCol, int toRow, int toCol, char chessboard[8][8]) {
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for ranks, 'A' to 'H' for files)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is along a rank or a file
    if (frRow == toRow || frCol == toCol) {
        // Check if the path is clear
        if (checkLinearPath(frRow, frCol, toRow, toCol, chessboard)) {
            return true;
        } else {
            cout << "There is a piece in the rook's path." << endl;
        }
    } else {
        cout << "Invalid rook move." << endl;
    }

    return false;
}

int main() {
    // Example usage with an empty chessboard
    char chessboard[8][8] = {
        {'R', 'N', 'B', 'Q', 'K','B', 'N', 'R'},
        {' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'R',' ','p','p', 'p' , 'p' , 'p' , 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    int frRow = 0;
    int frCol = 0;
    int toRow = 6;
    int toCol = 0;

    if (isValidWhiteRookMove(frRow, frCol, toRow, toCol, chessboard)) {
        cout << "Valid move for the white rook." << endl;
    } else {
        cout << "Invalid move for the white rook." << endl;
    }

    return 0;
}
