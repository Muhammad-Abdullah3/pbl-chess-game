#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
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
            chess_board[i][j]='P';
        }
    }
    //Displaying each index of the array in 8 by 8 form
    for(int k=0;k<=7;k++)
    {
        for(int l=0;l<=7;l++)
        {
            cout<<setw(7)<<chess_board[k][l];
        }
        cout<<endl;
        cout<<setw(4);
    }
    return 0;
}