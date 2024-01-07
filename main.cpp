#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
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
//Function to exit the game 
void exit_game()
{
    system("CLS");
	cout<<"You have successfully exited the game.";
	exit(0);
}
//Home menu Function
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
	system("CLS");
	cout<<"Chose player 1:";
	cout<<"Chose Player 2:";
}
else if(entr_num==2)
{
	instr();
}
else if (entr_num==6)
{
    exit_game();
}
}
//Main Game Function
int main()
{
    home_menu();
    return 0;
}