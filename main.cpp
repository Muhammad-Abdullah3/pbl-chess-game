#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;
char chess_board[8][8] = {{'R', 'N', 'B', 'Q', 'K','B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
;
void homeMenu();
void newGame();
void instr();
void addProfile();
void createStatFile(string &);
bool searchProfile(string &);
void deleteProfile(string & name);
void checkStats();
void displayBoard();
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
bool checkMate(int &,int &, int &, int &, int &);
string name;
string line;
//Main Function Start
int main()
{
	homeMenu();
    return 0;
}
//Main Function Ends

//New Game Function
void newGame()
{
	system("CLS");
	//variable to count the move Number
	int moveNo = 1;
    string move;
    int whiteKingRow = 0,whiteKingCol = 4,blackKingRow = 7,blackKingCol = 4;
    /*string player1,player2;
	cout<<"Chose player 1:";
	cout<<"Chose Player 2:";*/
    while(!(checkMate(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo)))
    {
        movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
    }
}
//Function to show instructions
void instr()
{
    system("CLS");
	cout<<"Instructions:";
	cout<<"1- Player 1 will play as white, and player 2 will play as black. \n2- Players will be chosen from already";
	cout<<"\n3- White pieces are in uppercase alphabets.\n4-Black pieces are in lowercase alphabets.";
	cout<<"\n5- Alphabet 'p/P' is used to for Pawns.\n6- Alphabet 'r/R' is used to for Rooks.";
	cout<<"\n7- Alphabet 'n/N' is used to for Knights.\n8- Alphabet 'b/B' is used to for Bishops.";
	cout<<"\n9- Alphabet 'q/Q' is used to for Queens.\n10- Alphabet 'k/K' is used to for Kings.";
	cout<<"\n11-Every time a check takes place, an alarm will be given to the checked player.";
	cout<<"\n13- At checkmate, the game will come to an end. \n 13- The stats are stored in a text file of both players in their profile.";
    cout<<"\nPress any key to go back to home Menu.";
    getch();
    homeMenu();
}
// Function to add a new player profile
void addProfile() {
    string newProfile;

    // Ask the user to add the new Profile
    cout << "Enter the new profile name: ";
    getline(cin, newProfile);
    //Appending the new Profile in the Profiles.txt file
    fstream profFile("Profiles.txt",ios::app);
    profFile<<endl<<newProfile;
    // Append ".txt" to the entered name to create the file name
    newProfile += ".txt";
    // Create a stats file for new Profile
    createStatFile(newProfile);
    //Ask the user for his choice if user wants to add a new profile or not
    system("cls");
    int choice;
    cout<<"To add another Profile please press 1:\nTo go back to home menu Press any other key\nEnter your Choice:";
    cin>>choice;
    switch (choice)
    {
    case 1:
        addProfile();
        break;
    default:
        break;
    }
}
//Create Stat File
void createStatFile(string &a)
{
    ofstream statFile(a);
    statFile<<setw(25)<<left<<"Total Games"<<setw(15)<<left<<"Won"<<setw(15)<<left<<"Lost"<<setw(15)<<left<<"Draws";
    // Check if the file is successfully created
    if (statFile.is_open()) {
        cout << "Stat file \"" << a << "\" created successfully." << endl;
        statFile.close();
        getch();
    } else {
        cerr << "Error creating the text file." << endl;
        createStatFile(a);
        getch();
    }
    statFile.close();
}
//Function to search for a profile
bool searchProfile(string & name)
{
	ifstream in("Profiles.txt");
	
	while (getline(in , line))
	{
		if (line.find("Name : " + name) != string::npos)
		{
			//name found
			in.close();
			return true;
		}
	}
	in.close();
	return false;
}
// Function to delete a players profile
void deleteProfile(string& name)
{
    ifstream in("profile.txt");
    ofstream temp("temp.txt");

    while (getline(in, line))
    {
        if (line.find("Name : " + name) == string::npos)
        {
            // Copy lines to temp file, except the line with the specified name
            temp << line << endl;
        }
    }

    in.close();
    temp.close();

    // Rename temp file to the original file
    remove("profiles.txt");
    rename("temp.txt", "profiles.txt");
}
// Function to check players stats
void checkStats()
{

}
void homeMenu()
{
	int entr_num;
	cout<<"Welcome to the Game:"<<endl;
	cout<<"Press '1' to start a new game:"<<endl;
	cout<<"Press '2' to open instructions:"<<endl;
	cout<<"Press '3' to add a new player profile:"<<endl;
	cout<<"Press '4' to delete player profile:"<<endl;
	cout<<"press '5' to check stats:"<<endl;
	cout<<"Press '6' to exit the game:"<<endl;
    cin>>entr_num;
    switch(entr_num)
{
    case 1:
{
    newGame();
    break;
}
case 2:
{
	instr();
    break;
}
case 3:
{
	addProfile();
    break;
}
case 4:
{
	deleteProfile(name);
    break;
}
case 5:
    {
	checkStats();
    break;
    }
case 6:
    {
	system("CLS");
	cout<<"You have successfully exited the game.";
	exit(0);
    }
default:
    {
	system("CLS");
	cout<<"Your choice is invalid. Press any key to go back to home menu: ";
	getch();
	system("CLS");
	homeMenu();
    }
}
}
//Displaying the board
void displayBoard()
{
    cout<<"------Player 1: White-------"<<endl;
	//displaying array by each index.
    for(int k=0;k<=7;k++)
    {   
        //Displaying the Row Borders
        if(k==0)
            cout<<"    A     B     C     D     E     F     G     H   "<<endl;
        cout<<" -------------------------------------------------"<<endl;
        //Displaying the Content of each box
        for(int l=0;l<=7;l++)
        {
            if(l==0)
                cout<<k+1;
            if(l==0)
                cout<<"|";
            if(chess_board[k][l]!=' ')
                cout<<"  "<<chess_board[k][l]<<"  |";
            else
                cout<<"   "<<chess_board[k][l]<<" |";
            if(l==7)
                cout<<k+1;
        }
        cout<<endl;
        if(k==7)
            cout<<" -------------------------------------------------"<<endl;
        if(k==7)
            cout<<"    A     B     C     D     E     F     G     H   "<<endl;
	}
    cout<<"------Player 2: Black-------";
}
//checkmate for white king
bool checkMate(int & whiteKingRow,int &whiteKingCol,int & blackKingRow,int & blackKingCol, int & moveNo) 
{
    //White provides Check Mate
    if(moveNo%2==1)
    {
        int temKingRow = 0,temKingCol=0;
        if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
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
            default:
                return true;
            }
        }
    }
    //Black Provides check mate
    else
    {
        int temKingRow = 0,temKingCol=0;
        if(blackKingCheck(blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,moveNo))
        {//Check for every legal move of king to avoid check
            int tempCase = 1;
            switch (tempCase)
            {
            case 1:
            {
                temKingRow=blackKingRow,temKingCol = blackKingCol+1;
                if(legalBlackKing(blackKingRow,blackKingCol,temKingRow,temKingCol,temKingRow,temKingCol,whiteKingRow,whiteKingCol,moveNo))
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
                temKingRow=blackKingRow,temKingCol = blackKingCol-1;
                if(legalBlackKing(blackKingRow,blackKingCol,temKingRow,temKingCol,temKingRow,temKingCol,whiteKingRow,whiteKingCol,moveNo))
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
                temKingRow=blackKingRow+1,temKingCol = blackKingCol;
                if(legalBlackKing(blackKingRow,blackKingCol,temKingRow,temKingCol,temKingRow,temKingCol,whiteKingRow,whiteKingCol,moveNo))
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
                temKingRow=blackKingRow-1,temKingCol = blackKingCol;
                if(legalBlackKing(blackKingRow,blackKingCol,temKingRow,temKingCol,temKingRow,temKingCol,whiteKingRow,whiteKingCol,moveNo))
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
                temKingRow=blackKingRow+1,temKingCol = blackKingCol+1;
                if(legalBlackKing(blackKingRow,blackKingCol,temKingRow,temKingCol,temKingRow,temKingCol,whiteKingRow,whiteKingCol,moveNo))
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
                temKingRow=blackKingRow+1,temKingCol = blackKingCol-1;
                if(legalBlackKing(blackKingRow,blackKingCol,temKingRow,temKingCol,temKingRow,temKingCol,whiteKingRow,whiteKingCol,moveNo))
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
                temKingRow=blackKingRow-1,temKingCol = blackKingCol+1;
                if(legalBlackKing(blackKingRow,blackKingCol,temKingRow,temKingCol,temKingRow,temKingCol,whiteKingRow,whiteKingCol,moveNo))
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
                temKingRow=blackKingRow-1,temKingCol = blackKingCol-1;
                if(legalBlackKing(blackKingRow,blackKingCol,temKingRow,temKingCol,temKingRow,temKingCol,whiteKingRow,whiteKingCol,moveNo))
                {
                    return false;
                    break;
                }
            }    
            default:
                return true;
            }
        }
    }
}
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
    else if ((frRow == 1 && (toRow == frRow + 2 && toCol == frCol)) &&(chess_board[toRow][toCol]==' ')) 
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
    if (frRow<0||frRow > 7 || toRow < 0 || toRow > 7 || frCol < 0 || frCol > 7 || toCol < 0 || toCol > 7) 
    {
    cout << "Invalid chessboard position." <<endl;
        return false;
    }

    // Check if the destination is one square forward
    if ((toRow == frRow - 1 && toCol == frCol)&&(chess_board[toRow][toCol]==' ')) 
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
    if(frRow<toRow&&frCol<toCol) 
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
        cout << "Invalid Rook move." << endl;
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
    int rowDifference = abs(frRow-toRow);
    int colDifference = abs(frCol-toCol);
    if ((rowDifference==1&&colDifference==1)&&(chess_board[toRow][toCol] == ' ' ||(chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z')))
    {
        return true;
    }
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
    int rowDifference = abs(frRow-toRow);
    int colDifference = abs(frCol-toCol);
    if ((rowDifference==1&&colDifference==1)&&(chess_board[toRow][toCol] == ' ' ||(chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z')))
    {
        return true;
    }
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
        cout << "Invalid Bishop move." << endl;
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
    int rowDifference = abs(frRow - toRow);
    int colDifference = abs(frCol - toCol);
    if ((rowDifference==1&&colDifference==1)&&(chess_board[toRow][toCol] == ' ' ||(chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z')))
    {
        return true;
    }
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
    int rowDifference = abs(frRow - toRow);
    int colDifference = abs(frCol - toCol);
    if ((rowDifference==1&&colDifference==1)&&(chess_board[toRow][toCol] == ' ' ||(chess_board[toRow][toCol]>='a'&&chess_board[toRow][toCol]<='z')))
    {
        return true;
    }
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
        cout << "Invalid Queen move." << endl;
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
            cout << "Invalid Knight move. Destination square is occupied by a white piece." << endl;
        }
    } else 
    {
        cout << "Invalid Knight move." << endl;
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
        return false;
    }
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
        cout << "Invalid King move." << endl;
        return false;
    }
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
    if(checkUnderAttackWhite(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
    {
        return true;
    }
}
bool checkUnderAttackWhite(int & whiteKingRow,int & whiteKingCol,int & blackKingRow,int &blackKingCol,int &moveNo) 
{
    // legal move generation for each piece
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            if (chess_board[i][j] == 'p') 
            {
                if ((whiteKingRow == i - 1 && (whiteKingCol == j + 1 || whiteKingCol == j - 1))&&(chess_board[whiteKingRow][whiteKingCol]=='K')) 
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
            } else if (chess_board[i][j] == 'k') 
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
    return false;
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
    if(checkUnderAttackBlack(blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,moveNo))
    {
        return true;
    }
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
                if ((blackKingRow == i - 1 && (blackKingCol == j + 1 || blackKingCol == j - 1))&&(chess_board[blackKingRow][blackKingCol]=='k')) 
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
                if (legalWhiteBishop(i, j,blackKingCol,blackKingRow)) 
                {
                    cout<<"King is in Check";
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
    return false;
}
//Taking input from The User
void inMove(string & move,int & moveNo)
{
    if(moveNo%2==1)
    {
        cout<<endl<<"White please enter your Move: ";
		cin>>move;
        //
        if(move.length()!=4)//including the null character
        {//calling the function again
            cout<<endl<<"Wrong Notation.Enter Your move again:";
            inMove(move,moveNo);
        }
        for(int i=0;i<4;i+=2)
        {
            if(!((move.at(i)>='A'&&move.at(i)<='H')||(move.at(i)>='a'&&move.at(i)<='h')))
            {
                cout<<endl<<"Wrong Notation.Enter Yourmove again:";
                inMove(move,moveNo);
            }
        }
        for(int i=1;i<4;i+=2)
        {
            if(!(move.at(i)>='1'&&move.at(i)<='8'))
            {
                cout<<endl<<"Wrong Notation.Enter Yourmove again:";
                inMove(move,moveNo);
            }
        }
    }
    else
    {
        cout<<endl<<"Black please enter your Move: ";
        cin>>move;
        if(move.length()!=4)//including the null character
        {//calling the function again
            cout<<endl<<"Wrong Notation.Enter Yourmove again:";
            inMove(move,moveNo);
        }
        for(int i=0;i<4;i+=2)
        {
            if(!((move.at(i)>='A'&&move.at(i)<='H')||(move.at(i)>='a'&&move.at(i)<='h')))
            {
                cout<<endl<<"Wrong Notation.Enter Yourmove again:";
                inMove(move,moveNo);
            }
        }
        for(int i=1;i<4;i+=2)
        {
            if(!(move.at(i)>='1'&&move.at(i)<='8'))
            {
                cout<<endl<<"Wrong Notation.Enter Yourmove again:";
                inMove(move,moveNo);
            }
        }
    }
}
//Moving Piece
void movePiece(string & move, int & moveNo, int & whiteKingRow,int & whiteKingCol,int & blackKingRow, int & blackKingCol)
{
    displayBoard();
    int frRow,frCol,toRow,toCol;
    char destinationValue;
    inMove(move,moveNo);
    convertString(frRow,frCol,toRow,toCol,move);
    //Start of outermost if
    if(moveNo%2==1)
    {
        if(!(chess_board[frRow][frCol]>='A'&&chess_board[frRow][frCol]<='Z'))
        {
            movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
        }
        if (chess_board[frRow][frCol]=='P')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalWhitePawn(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(whiteKingCheck(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
                {
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;
                    cout<<"Illegal Move";
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
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;
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
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;
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
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;
                    
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
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;
                    
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
        if(checkMate(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
        {
            cout<<"White Won by Checkmate.\nPress any key.........";
            getch();
            system("cls");
            char ch;
            cout<<"To Play again press [y/Y]:\n Press any other key to go back to Home menu:";
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                newGame();
            }
            else
            {
                homeMenu();
            }
        }
    }
    //End of outermost if
    else
    {
        if(!(chess_board[frRow][frCol]>='a'&&chess_board[frRow][frCol]<='z'))
        {
            cout<<"Illegal Move";
            movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
        }
        else if (chess_board[frRow][frCol]=='p')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalBlackPawn(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(blackKingCheck(blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,moveNo))
                {
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;
                    cout<<"Illegal Move";
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='r')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalBlackRook(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(blackKingCheck(blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,moveNo))
                {
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";    
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='q')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalBlackQueen(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(blackKingCheck(blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,moveNo))
                {
                    cout<<"Illegal Move.";
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='b')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalBlackBishop(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(blackKingCheck(blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,moveNo))
                {
                    cout<<"Illegal Move.";
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;
                    movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
                }
            }
            else
            {
                cout<<"Illegal move.";
                movePiece(move,moveNo,whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);
            }
        }
        else if (chess_board[frRow][frCol]=='n')
        {
            destinationValue = chess_board[toRow][toCol];
            if(legalBlackKnight(frRow,frCol,toRow,toCol))
            {
                chess_board[toRow][toCol] = chess_board[frRow][frCol];
                chess_board[frRow][frCol] =  ' ';
                if(blackKingCheck(blackKingRow,blackKingCol,whiteKingRow,whiteKingCol,moveNo))
                {
                    cout<<"Illegal Move.";
                    chess_board[frRow][frCol] = chess_board[toRow][toCol];
                    chess_board[toRow][toCol] =  destinationValue;    
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
    if(checkMate(whiteKingRow,whiteKingCol,blackKingRow,blackKingCol,moveNo))
    {
        cout<<"Black Won by Checkmate.\nPress any key.........";
        getch();
        system("cls");
        cout<<"To Play again press y:\n Press any other key to go back to Home menu:";
    }
    moveNo++;
}
//Converting String into integers
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