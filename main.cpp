#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
char chess_board[8][8] = {' '};
void home_menu();
void new_game();
//moving a piece
void move_piece(string);
void board_set();
void instr();
void add_profile();
void del_profile();
void chck_stats();
void display_board(string,string);
bool checkWhitePawn(int, int, int, int);
bool checkBlackPawn(int, int, int, int);
bool checkDiagnolPath(int,int,int,int);
bool checkLinearPath(int,int,int,int);
bool checkWhiteRook(int,int,int,int);
bool checkBlackRook(int,int,int,int);
bool checkWhiteBishop(int,int,int,int);
bool checkBlackBishop(int,int,int,int);
bool checkWhiteQueen(int,int,int,int);
bool checkBlackQueen(int,int,int,int);
int main()
{
	home_menu();
    return 0;
}
void new_game()
{
	system("CLS");
	//variable to count the player turn
	int tot_mov = 0;
	//variable to count black and white's turn individually
	int white_mov = 0, black_mov = 0;
	/*
	cout<<"Chose player 1:";
	cout<<"Chose Player 2:";
	
	
	Player chosing code
	
	*/
	//calling board set function
	board_set();
}
//Setting board pieces for the first time in array
void board_set()
{
    //White pawns
    for(int i=1;i==1;i++)
    {
        for(int j=0;j<8;j++)
        {
            chess_board[i][j]='P';
        }
    }
    //Black Pawns
    for(int i=6;i==6;i++)
    {
        for(int j=0;j<8;j++)
        {
            chess_board[i][j]='p';
        }
    }
    //white rook
    for (int i=0;i==0;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==0||j==7)
			{
    		 chess_board[i][j]='R';
			}

		}
	}
	//Black rook.
    for (int i=7;i==7;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==0||j==7)
			{
    		    chess_board[i][j]='r';
			}

		}
	}
	//white Knight.
	for (int i=0;i==0;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==1||j==6)
			{
    		    chess_board[i][j]='N';
			}

		}
	}
	//Black knight
	for (int i=7;i==7;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==1||j==6)
			{
    		    chess_board[i][j]='n';
			}

		}
	}
	//White Bishop.
	for (int i=0;i==0;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==2||j==5)
			{
    		    chess_board[i][j]='B';
			}

		}
	}
	//Black bishop
	  for (int i=7;i==7;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==2||j==5)
			{
    		    chess_board[i][j]='b';
			}

		}
	}
	//White Queen
	for (int i=0;i==0;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==3)
			{
    		    chess_board[i][j]='Q';
			}

		}
	}
	//Black queen
	for (int i=7;i==7;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==3)
			{
    		    chess_board[i][j]='q';
			}

		}
	}
	//White king
	for (int i=0;i==0;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==4)
			{
    		    chess_board[i][j]='K';
			}

		}
	}
	//black King
	  for (int i=7;i==7;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if (j==4)
			{
    		    chess_board[i][j]='k';
			}

		}
	}
}
//Function to show instructions
void instr()
{
    system("CLS");
	cout<<"Instructions:";
	cout<<"1- Player 1 will play as white, and player 2 will play as black. \n2- Players will be chosen from already added player profiles.";
	cout<<"\n3- White pieces are in uppercase alphabets.\n4-Black pieces are in lowercase alphabets.";
	cout<<"\n5- Alphabet 'p/P' is used to for Pawns.\n6- Alphabet 'r/R' is used to for Rooks.";
	cout<<"\n7- Alphabet 'n/N' is used to for Knights.\n8- Alphabet 'b/B' is used to for Bishops.";
	cout<<"\n9- Alphabet 'q/Q' is used to for Queens.\n10- Alphabet 'k/K' is used to for Kings.";
	cout<<"\n11- The last move will be shown in a sidebar.\n12-Every time a check takes place, an alarm will be given to the checked player.";
	cout<<"\n13- At checkmate, the game will come to an end. \n 13- The stats are stored in a text file of both players in their profile.";
}
// Function to add a new player profile
void add_profile()
{

}
// Function to delete a players profile
void del_profile()
{

}
// Function to check players stats
void chck_stats()
{

}
void home_menu()
{
	int entr_num=0;
	cout<<"Welcome to the Game:"<<endl;
	cout<<"Press '1' to start a new game:"<<endl;
	cout<<"Press '2' to open instructions:"<<endl;
	cout<<"Press '3' to add a new player profile:"<<endl;
	cout<<"Press '4' to delete player profile:"<<endl;
	cout<<"press '5' to check stats:"<<endl;
	cout<<"Press '6' to exit the game:"<<endl;
    cin>>entr_num;
	if (entr_num==1)
{
    new_game();
}
else if(entr_num==2)
{
	instr();
}
else if (entr_num==3)
{
	add_profile();
}
else if (entr_num==4)
{
	del_profile();
}

else if (entr_num==5)
{
	chck_stats();
}
else if (entr_num==6)
{
	system("CLS");
	cout<<"You have successfully exited the game.";
	exit(0);
}
else
{
	system("CLS");
	cout<<"Your choice is invalid. Press any key to go back to home menu: ";
	getch();
	system("CLS");
	home_menu();
}
}
//Displaying the board
void display_board(string a,string b)
{
	//displaying array by each index.
    for(int k=0;k<=7;k++)
    {   //Displaying the Row Borders
        cout<<"--------------------------------"<<endl;
        //Displaying the Content of each box
        for(int l=0;l<=7;l++)
        {
            cout<<" "<<chess_board[k][l]<<" |";
        }
        cout<<endl;
	}
}
void move_piece(string a)
{
//converting all characters in upper case
a.at(0)=toupper(a.at(0));
a.at(2)=toupper(a.at(2));
//converting notation from string to integer array indices
int fr_row = a[0]-'A';
int fr_col = a[1]-'0';
int to_row = a[2]-'A';
int to_col = a[3]-'0';
}
bool checkWhitePawn(int frRow, int frCol, int toRow, int toCol) {
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
bool checkBlackPawn(int frRow, int frCol, int toRow, int toCol) 
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
bool checkWhiteRook(int frRow, int frCol, int toRow, int toCol) 
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
bool checkBlackRook(int frRow, int frCol, int toRow, int toCol) 
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
bool checkWhiteBishop(int frRow, int frCol, int toRow, int toCol) 
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
bool checkBlackBishop(int frRow, int frCol, int toRow, int toCol) 
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
bool checkWhiteQueen(int frRow, int frCol, int toRow, int toCol) {
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
bool checkBlackQueen(int frRow, int frCol, int toRow, int toCol) 
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