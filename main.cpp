#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
char chess_board[8][8] = {'.'};
void home_menu();
void new_game();
void board_set();
void instr();
void add_profile();
void del_profile();
void chck_stats();
void display_board(string,string);
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
            cout<<setw(4)<<chess_board[k][l]<<"";
        }
        cout<<endl;
	}
}
void move_piece(int fr_ro,int fr_col,int to_ro,int to_col)
{
		
}