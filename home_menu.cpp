#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
int main()
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
	cout<<"Chose player 1:";
	cout<<"Chose Player 2:";
}
else if(entr_num==2)
{
	cout<<"Instructions:";
	cout<<"1- Player 1 will play as white, and player 2 will play as black. \n2- Players will be chosen from already added player profiles.";
	cout<<"\n3- The last move will be shown in a sidebar.\n4-Every time a check takes place, an alarm will be given to the checked player.";
	cout<<"\n5- At checkmate, the game will come to an end. \n 6- The stats are stored in a text file of both players in their profile.";
}
else if (entr_num==6)
{
	cout<<"You have successfully exited the game.";
	exit(0);
}
return 0;	
}