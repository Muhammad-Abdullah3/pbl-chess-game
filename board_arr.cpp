#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
//Creating a function for moving pieces
int move_piec(int&,int,int);
int main()
{
    char chess_board[8][8]={' '};
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
	//displaying array by each index.
    for(int k=0;k<=7;k++)
    {   //Displaying the Row Borders
        cout<<"--------------------------------"<<endl;
        //Displaying the Content of each box
        for(int l=0;l<=7;l++)
        {
            cout<<setw(4)<<chess_board[k][l];
        }
        cout<<endl;
    }
    return 0;
}
