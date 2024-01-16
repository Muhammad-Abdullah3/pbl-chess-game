#include <iostream>
#include <string>
using namespace std;
char chess_board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K','B', 'N', 'R'},
        {' ', 'B', 'P', 'P', 'P', ' ', ' ', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'R', ' ', ' ', 'p', ' ' , 'p' , 'p' , 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
bool legalWhitePawn(int, int, int, int);
bool legalBlackPawn(int, int, int, int);
bool checkDiagnolPath(int,int,int,int);
bool checkLinearPath(int,int,int,int);
bool legalWhiteRook(int,int,int,int);
bool legalBlackRook(int,int,int,int);
bool legalWhiteBishop(int,int,int,int);
bool legalBlackBishop(int,int,int,int);
bool legalWhiteQueen(int,int,int,int);
bool legalBlackQueen(int,int,int,int);
bool legalWhiteKnight(int,int,int,int);
bool legalBlackKnight(int,int,int,int);
bool legalWhiteKing(int,int,int,int,int &, int &,int &,int &,int &);
bool legalBlackKing(int,int,int,int,int &,int &, int &,int &,int &);
void convertString(int &,int &,int &,int &,string);
void inMove(string &, int &);
void movePiece(string &,int &,int &,int &,int &,int &);
bool whiteKingCheck(int &,int &,int &,int &,int & );
bool checkUnderAttackWhite(int &,int &,int &,int &,int &);
bool blackKingCheck(int &,int &,int &,int &,int &);
bool checkUnderAttackBlack(int &,int &,int &,int &,int &);
bool checkmate(int &,int &, int &, int &, int &, int &);

int main() 
{
    string move;
    int moveNo=2;
    int whiteKingRow=0,whiteKingCol=4,blackKingRow=7,blackKingCol=4;
    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
    return 0;
}
//checkmate for white king
/*bool checkmate(int & whiteKingRow,int &whiteKingCol,int & blackKingRow,int & blackKingCol, int & moveNo) 
{
    if(moveNo%2==0)
    {
        int temKingRow = 0,temKingCol=0;
        if(whiteKingCheck(whiteKingRow,whiteKingCol,moveNo))
        {//Check for every legal move of king to avoid check
            int tempCase = 1;
            switch (tempCase)
            {
            case 1:
            {
                temKingRow=whiteKingRow,temKingCol = whiteKingCol+1;
                if(legalWhiteKing(whiteKingRow,whiteKingCol,temKingRow,temKingCol,temKingRow,temKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    return false;
                    break;
                }
                else
                {
                    tempCase ++;
                }
            }
            case 2:
            {
                temKingRow=whiteKingRow,temKingCol = whiteKingCol-1;
                if(legalWhiteKing(whiteKingRow,whiteKingCol,temKingRow,temKingCol,temKingRow,temKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    return false;
                    break;
                }
                else
                {
                    tempCase ++;
                }
            }
            case 3:
            {
                temKingRow=whiteKingRow+1,temKingCol = whiteKingCol;
                if(legalWhiteKing(whiteKingRow,whiteKingCol,temKingRow,temKingCol,temKingRow,temKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    return false;
                    break;
                }
                else
                {
                    tempCase ++;
                }
            }
            case 4:
            {
                temKingRow=whiteKingRow-1,temKingCol = whiteKingCol;
                if(legalWhiteKing(whiteKingRow,whiteKingCol,temKingRow,temKingCol,temKingRow,temKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    return false;
                    break;
                }
                else
                {
                    tempCase ++;
                }
            }
            case 5:
            {
                temKingRow=whiteKingRow+1,temKingCol = whiteKingCol+1;
                if(legalWhiteKing(whiteKingRow,whiteKingCol,temKingRow,temKingCol,temKingRow,temKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    return false;
                    break;
                }
                else
                {
                    tempCase ++;
                }
            }
            case 6:
            {
                temKingRow=whiteKingRow+1,temKingCol = whiteKingCol-1;
                if(legalWhiteKing(whiteKingRow,whiteKingCol,temKingRow,temKingCol,temKingRow,temKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    return false;
                    break;
                }
                else
                {
                    tempCase ++;
                }
            }
            case 7:
            {
                temKingRow=whiteKingRow-1,temKingCol = whiteKingCol+1;
                if(legalWhiteKing(whiteKingRow,whiteKingCol,temKingRow,temKingCol,temKingRow,temKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    return false;
                    break;
                }
                else
                {
                    tempCase ++;
                }
            }
            case 8:
            {
                temKingRow=whiteKingRow-1,temKingCol = whiteKingCol-1;
                if(legalWhiteKing(whiteKingRow,whiteKingCol,temKingRow,temKingCol,temKingRow,temKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    return false;
                    break;
                }
            }    
            }
        }
    }
    /*else
    {
        blackKingCheck(blackKingRow,blackKingCol,moveNo);
        //Check for every legal move of king to avoid check
    }
}*/
bool legalWhitePawn(int frRow, int frCol, int toRow, int toCol) {
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for ranks, 'A' to 'H' for files)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
    cout << "Invalid chessboard position." <<endl;
        return false;
    }

    // Check if the destination is one square forward
    if ((toRow == frRow + 1 && toCol == frCol)&&(chess_board[toRow][toCol]==' ')) 
	{
        return true;
    }

    // Check if the destination is two squares forward (only allowed if the pawn is in its starting position)
    else if ((frRow == 1 && (toRow == frRow + 2 && toCol == frCol)) &&(chess_board[toRow][toCol]==' ') ) 
	{
        return true;
    }

    // Check if the destination is one square diagonally forward to capture an opponent's piece
    else if ((toRow == frRow + 1 && (toCol == frCol + 1 || toCol == frCol - 1))&&(chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z')) 
	{
        return true;
    }
    // If none of the above conditions are met, the move is invalid
    else
    {
        cout << "Invalid move." << endl;
        return false;
    }
}
bool legalBlackPawn(int frRow, int frCol, int toRow, int toCol) 
{
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for ranks, 'A' to 'H' for files)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
    cout << "Invalid chessboard position." <<endl;
        return false;
    }

    // Check if the destination is one square forward
    if ((toRow == frRow - 1 && toCol == frCol)&&(chess_board[toRow][toCol]=' ')) 
	{
        return true;
    }

    // Check if the destination is two squares forward (only allowed if the pawn is in its starting position)
    else if ((frRow == 6 && toRow == frRow - 2 && toCol == frCol)&&(chess_board[toRow][toCol]=' ')) 
	{
        return true;
    }

    // Check if the destination is one square diagonally forward to capture an opponent's piece
    else if ((toRow == frRow - 1 && (toCol == frCol + 1 || toCol == frCol - 1))&&(chess_board[toRow][toCol]>='A'&&chess_board[toRow][toCol]<='Z')) 
	{
        return true;
    }
    // If none of the above conditions are met, the move is invalid
    else
    {
        cout << "Invalid move." << endl;
        return false;
    }
}
//Function to check diagnol Path of the piece
bool checkDiagnolPath(int frRow, int frCol, int toRow, int toCol) 
{
    // Check if there are any pieces in the path
    if (frRow<toRow&&frCol<toCol) 
    {
        int row = frRow+1;
        int col = frCol+1;
        while (row<toRow&&col<toCol) 
        {
            if (chess_board[row][col] != ' ') 
            {
            return false; // Path is not clear
            }
            ++row;
            ++col;
        }
    } else if (frRow<toRow&&frCol>toCol) 
    {
        int row = frRow+1;
        int col = frCol-1;
        while (row<toRow&&col<toCol) 
        {
            if (chess_board[row][col] != ' ') 
            {
            return false; // Path is not clear
            }
            ++row;
            --col;
        }
    } else if (frRow>toRow&&frCol>toCol) 
    {
        int row = frRow-1;
        int col = frCol-1;
        while (row<toRow&&col<toCol) 
        {
            if (chess_board[row][col] != ' ') 
            {
            return false; // Path is not clear
            }
            --row;
            --col;
        }
    } else if (frRow>toRow&&frCol<toCol) 
    {
        int row = frRow-1;
        int col = frCol+1;
        while (row<toRow&&col<toCol) 
        {
            if (chess_board[row][col] != ' ') 
            {
            return false; // Path is not clear
            }
            --row;
            ++col;
        }
    } else
    {   return true; // Path is clear
    }
}
//Checking Linear Path
bool checkLinearPath(int frRow, int frCol, int toRow, int toCol) 
{
    // Check if there are any pieces in the path
    if (frRow == toRow) 
    {
        // Move along the same row
        if(frCol>toCol)
        {
            for (int col = frCol+1; col < toCol; ++col) 
            {
                if (chess_board[frRow][col] != ' ') 
                {
                return false; // Path is not clear
                }
            }
        }
        else
        {
            for (int col = frCol-1; col > toCol; --col) 
            {
                if (chess_board[frRow][col] != ' ') 
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
                if (chess_board[row][frCol] != ' ') 
                {
                return false; // Path is not clear
                }
            }
        }
        else
        {
            for (int row = frRow-1; row > toRow; --row) 
            {
                if (chess_board[row][frRow] != ' ') 
                {
                return false; // Path is not clear
                }
            }
        }
    }

    return true; // Path is clear
}
//Checking White Rook move
bool legalWhiteRook(int frRow, int frCol, int toRow, int toCol) 
{
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for rowss, 'A' to 'H' for columns)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is along a row or a coloumn and destination is either free or an oponent piece is there
    if ((frRow == toRow || frCol == toCol)&&(chess_board[toRow][toCol]==' '||(chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z'))) 
	{
        // Check if the path is clear
        if (checkLinearPath(frRow, frCol, toRow, toCol)) 
		{
            return true;
        } else 
		{
            cout << "There is a piece in the rook's path." << endl;
        }
    } else 
	{
        cout << "Invalid rook move." << endl;
    }
    return false;
}
//Checking Black Rook Move
bool legalBlackRook(int frRow, int frCol, int toRow, int toCol) 
{
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for rows, 'A' to 'H' for columns)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is along a row or a coloumn and destination is either free or an oponent piece is there
    if ((frRow == toRow || frCol == toCol)&&(chess_board[toRow][toCol]==' '||(chess_board[toRow][toCol]>='A'&&chess_board[toRow][toCol]<='Z'))) 
	{
        // Check if the path is clear
        if (checkLinearPath(frRow, frCol, toRow, toCol)) 
		{
            return true;
        } else 
		{
            cout << "There is a piece in the rook's path." << endl;
        }
    } else 
	{
        cout << "Invalid rook move." << endl;
    }
    return false;
}
//Checking White Bishop Move
bool legalWhiteBishop(int frRow, int frCol, int toRow, int toCol) 
{
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for rows, 'A' to 'H' for coloumns)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is along a diagonal
    int rowDifference = frRow-toRow;
    int colDifference = frCol-toCol;

    if (rowDifference == colDifference) {
        // Check if the path is clear
        if (checkDiagnolPath(frRow, frCol, toRow, toCol)) 
        {
            // Check if the destination square is empty or contains a black piece
            if (chess_board[toRow][toCol] == ' ' || (chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z')) 
            {
                return true;
            } else 
            {
                cout << "Invalid bishop move. Destination square is occupied by a white piece." << endl;
            }
        } else 
        {
            cout << "There is a piece in the bishop's path." << endl;
        }
    } else 
    {
        cout << "Invalid bishop move." << endl;
    }
    return false;
}
//Checking Black Bishop Move
bool legalBlackBishop(int frRow, int frCol, int toRow, int toCol) 
{
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for rows, 'A' to 'H' for coloumns)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }

    // Check if the move is along a diagonal
    int rowDifference = frRow-toRow;
    int colDifference = frCol-toCol;

    if (rowDifference == colDifference) {
        // Check if the path is clear
        if (checkDiagnolPath(frRow, frCol, toRow, toCol)) 
        {
            // Check if the destination square is empty or contains a black piece
            if (chess_board[toRow][toCol] == ' ' || (chess_board[toRow][toCol]>='A'&&chess_board[toRow][toCol]<='Z')) 
            {
                return true;
            } else 
            {
                cout << "Invalid bishop move. Destination square is occupied by a white piece." << endl;
            }
        } else 
        {
            cout << "There is a piece in the bishop's path." << endl;
        }
    } else 
    {
        cout << "Invalid bishop move." << endl;
    }
    return false;
}
//Checking white queen
bool legalWhiteQueen(int frRow, int frCol, int toRow, int toCol) {
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for rows, 'A' to 'H' for coloumns)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }
    // row and coloumn difference for diagnol checking
    int rowDifference = frRow - toRow;
    int colDifference = frCol - toCol;
    // Check if the move is along a row or a coloumn
    if (frRow == toRow || frCol == toCol) {
        // Check if the path is clear
        if (checkLinearPath(frRow, frCol, toRow, toCol)) {
            // Check if the destination square is empty or contains a black piece
            if (chess_board[toRow][toCol] == ' ' ||(chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z') ) 
            {
                return true;
            } else 
            {
                cout << "Invalid queen move. Destination square is occupied by a white piece." << endl;
            }
        } else 
        {
            cout << "There is a piece in the queen's path." << endl;
        }
    }else if(rowDifference==colDifference)//Checking if the move is along the diagnol
    {
        // Check if the path is clear
        if (checkDiagnolPath(frRow, frCol, toRow, toCol)) {
            // Check if the destination square is empty or contains a black piece
            if (chess_board[toRow][toCol] == ' ' ||(chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z') ) 
            {
                return true;
            } else 
            {
                cout << "Invalid queen move. Destination square is occupied by a white piece." << endl;
            }
        } else 
        {
            cout << "There is a piece in the queen's path." << endl;
        }        
    } else 
    {
        cout << "Invalid queen move." << endl;
    }

    return false;
}
//Check Black Queen
bool legalBlackQueen(int frRow, int frCol, int toRow, int toCol) 
{
    // Ensure the source and destination are within the chessboard boundaries (0 to 7 for rows, 'A' to 'H' for coloumns)
    if (frRow < 0 || frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) {
        cout << "Invalid chessboard position." << endl;
        return false;
    }
    // row and coloumn difference for diagnol checking
    int rowDifference = frRow - toRow;
    int colDifference = frCol - toCol;
    // Check if the move is along a row or a coloumn
    if (frRow == toRow || frCol == toCol) {
        // Check if the path is clear
        if (checkLinearPath(frRow, frCol, toRow, toCol)) 
		{
            // Check if the destination square is empty or contains a black piece
            if (chess_board[toRow][toCol] == ' ' ||(chess_board[toRow][toCol]>='A'&&chess_board[toRow][toCol]<='Z') ) 
            {
                return true;
            } else 
            {
                cout << "Invalid queen move. Destination square is occupied by a white piece." << endl;
            }
        } else 
        {
            cout << "There is a piece in the queen's path." << endl;
        }
    }else if(rowDifference==colDifference)//Checking if the move is along the diagnol
    {
        // Check if the path is clear
        if (checkDiagnolPath(frRow, frCol, toRow, toCol)) 
		{
            // Check if the destination square is empty or contains a black piece
            if (chess_board[toRow][toCol] == ' ' || (chess_board[toRow][toCol]>='A'&&chess_board[toRow][toCol]<='Z') ) 
            {
                return true;
            } else 
            {
                cout << "Invalid queen move. Destination square is occupied by a white piece." << endl;
            }
        } else 
        {
            cout << "There is a piece in the queen's path." << endl;
        }        
    } else 
    {
        cout << "Invalid queen move." << endl;
    }

    return false;
}
//White Knight Move Function
bool legalWhiteKnight(int frRow, int frCol, int toRow, int toCol) {
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
        if (chess_board[toRow][toCol] == ' ' || (chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z') )
        {
            return true;
        } else 
        {
            cout << "Destination square is occupied by a white piece." << endl;
        }
    } else 
    {
        cout << "Invalid knight move." << endl;
        return false;
    }
}
//Black Knight Function
bool legalBlackKnight(int frRow, int frCol, int toRow, int toCol) {
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
        if (chess_board[toRow][toCol] == ' ' || (chess_board[toRow][toCol]>='A'&&chess_board[toRow][toCol]<='Z') )
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
//White King
bool legalWhiteKing(int frRow, int frCol, int toRow, int toCol,int & whiteKingRow,int & whiteKingCol, int & blackKingRow,int & blackKingCol,int & moveNo) 
{
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
        if (chess_board[toRow][toCol] == ' ' || (chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z')) 
        {
            if(!(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo)))
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
//Black King
bool legalBlackKing(int frRow, int frCol, int toRow, int toCol,int & blackKingRow,int & blackKingCol,int &whiteKingRow,int &whiteKingCol,int & moveNo) {
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
        if (chess_board[toRow][toCol] == ' ' || (chess_board[toRow][toCol]>='A'&&chess_board[toRow][toCol]<='Z')) 
        {
            if(!blackKingCheck(blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,moveNo))
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
//White King Check function
bool whiteKingCheck(int & whiteKingRow ,int & whiteKingCol,int &blackKingRow,int &blackKingCol,int &moveNo)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(chess_board[i][j]=='K')
            {
                whiteKingRow = i;
                whiteKingCol = j;
                break;
            }
        }
    }
    checkUnderAttackWhite(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo);
}
bool checkUnderAttackWhite(int & whiteKingRow,int & whiteKingCol,int & blackKingRow,int &blackKingCol,int &moveNo) 
{
    // legal move generation for each piece
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (chess_board[i][j] == 'p') 
            {
                if (legalBlackPawn(i, j,whiteKingRow,whiteKingCol)) 
                {
                    return true;
                }
            } else if (chess_board[i][j] == 'n') 
            {
                if (legalBlackKnight(i, j,whiteKingRow,whiteKingRow)) 
                {
                    return true;
                }
            } else if (chess_board[i][j] == 'r') 
            {
                if (legalBlackRook(i, j,whiteKingRow,whiteKingCol)) 
                {
                    return true;
                }
            } else if (chess_board[i][j] == 'b')
            {
                if (legalBlackBishop(i, j,whiteKingCol,whiteKingRow)) {
                    return true;
                }
            } else if (chess_board[i][j] == 'q') 
            {
                if (legalBlackQueen(i, j,whiteKingRow,whiteKingCol)) 
                {
                    return true;
                }
            } else if (chess_board[i][j] == 'q') 
            {
                if(moveNo%2==1)
                {    
                    if (legalBlackKing(i, j,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,moveNo)) 
                    {
                        return true;
                    }
                }
        }
    }
}
}
//Black King Under Check
bool blackKingCheck(int & blackKingRow ,int & blackKingCol,int & whiteKingRow,int & whiteKingCol,int & moveNo)
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(chess_board[i][j]=='k')
            {
                blackKingRow = i;
                blackKingCol = j;
                break;
            }
        }
    }
    checkUnderAttackBlack(blackKingRow,blackKingCol,moveNo,whiteKingRow,whiteKingCol);
}
//Under Attack Square Validation
bool checkUnderAttackBlack(int & blackKingRow,int & blackKingCol,int & whiteKingRow, int & whiteKingCol,int & moveNo) 
{
    // legal move generation for each piece
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            if (chess_board[i][j] == 'P') 
            {
                if (legalWhitePawn(i, j,blackKingRow,blackKingCol)) 
                {
                    return true;
                }
            } else if (chess_board[i][j] == 'N') 
            {
                if (legalWhiteKnight(i, j,blackKingRow,blackKingRow)) 
                {
                    return true;
                }
            } else if (chess_board[i][j] == 'R') 
            {
                if (legalWhiteRook(i, j,blackKingRow,blackKingCol)) 
                {
                    return true;
                }
            } else if (chess_board[i][j] == 'B')
            {
                if (legalWhiteBishop(i, j,blackKingCol,blackKingRow)) {
                    return true;
                }
            } else if (chess_board[i][j] == 'Q') 
            {
                if (legalWhiteQueen(i, j,blackKingRow,blackKingCol)) 
                {
                    return true;
                }
            } else if (chess_board[i][j] == 'K') 
            {
                if(moveNo%2==0)
                {    
                    if (legalWhiteKing(i, j,blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo)) 
                    {
                        return true;
                    }
                }
        }
    }
}
}
//Taking input from The User
void inMove(string & move,int & moveNo)
{
    if(moveNo%2==1)
    {
        cout<<"White please enter your Move: ";
        cin>>move;
        if(move.size()!=4);//including the null character
        {//calling the function again
            inMove(move,moveNo);
        }
        for(int i=0;i<4;i+2)
        {
            if(move.at(i)<'A'||move.at(i)>'H'||move.at(i)<'a'||move.at(i)>'h')
                inMove(move,moveNo);
        }
        for(int i=1;i<4;i+2)
        {
            if(move.at(i)<'1'||move.at(i)>'8')
                inMove(move,moveNo);
        }
    }
    else
    {
        cout<<"Black please enter your Move: ";
        cin>>move;
        if(move.length()!=5);//not including the null character
        {//calling the function again
            inMove(move,moveNo);
        }
        for(int i=0;i==0||i==2;i+=2)
        {
            if((move.at(i)>='A'&&move.at(i)<='H')||(move.at(i)>='a'&&move.at(i)<='h'))
                inMove(move,moveNo);
        }
        for(int i=1;i==1||i==3;i+=2)
        {
            if(move.at(i)<'1'||move.at(i)>'8')
                inMove(move,moveNo);
        }
    }
}
//Moving Piece
void movePiece(string & move, int & moveNo, int & whiteKingRow,int & whiteKingCol,int & blackKingRow, int & blackKingCol)
{
    int frRow,frCol,toRow,toCol;
    char destinationValue;
    inMove(move,moveNo);
    convertString(frRow,frCol,toRow,toCol,move);
    if(moveNo%2==1)
    {
        if(chess_board[frRow][frCol]<'A'||chess_board[frRow][frCol]>'Z')
        {
            movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
        }
        else if (chess_board[frRow][frCol]=='P')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhitePawn(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='R')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhiteRook(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='Q')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhiteQueen(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    cout<<"Illegal Move.";
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='B')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhiteBishop(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    cout<<"Illegal Move.";
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='N')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhiteKnight(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    cout<<"Illegal Move.";
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='K')
        {
            if(legalWhiteKing(frRow,frCol,toRow,toCol,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else
        {
            cout<<"Illegal Move.";
            
            movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
        }
    }
    else
    {
        if(chess_board[frRow][frCol]<'A'||chess_board[frRow][frCol]>'Z')
        {
            
            movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
        }
        else if (chess_board[frRow][frCol]=='P')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhitePawn(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='R')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhiteRook(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='Q')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhiteQueen(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    cout<<"Illegal Move.";
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='B')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhiteBishop(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    cout<<"Illegal Move.";
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='N')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhiteKnight(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    cout<<"Illegal Move.";
                    chess_board[toRow][toCol] = chess_board[frRow][frCol];
                    chess_board[frRow][frCol] =  destinationValue;
                    
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='k')
        {
            if(legalBlackKing(frRow,frCol,toRow,toCol,whiteKingRow,whiteKingCol,whiteKingRow,whiteKingCol,moveNo))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else
        {
            cout<<"Illegal Move.";
        
            movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
        }
    }
    moveNo++;
}
//Converting String into int variables
void convertString(int & frRow,int & frCol,int & toRow,int & toCol,string input)
{//converting all characters in upper case
input.at(0)=toupper(input.at(0));
input.at(2)=toupper(input.at(2));
//converting notation from string to integer array indices
frRow = input.at(1)-'1';
frCol = input.at(0)-'A';
toRow = input.at(3)-'1';
toCol = input.at(2)-'A';
}

