#include<iostream>
#include<string>
using namespace std;
void inMove(string &,int &);
void convertString(int &,int &,int &,int &,string);
int main()
{
    int frRow,frCol,toRow,toCol;
    int moveNo =2;
    string move;
    inMove(move,moveNo);
    convertString(frRow,frCol,toRow,toCol,move);
    cout<<frRow<<frCol<<toRow<<toCol;
    return 0;
}
void inMove(string & move,int & moveNo)
{
    if(moveNo%2==1)
    {
        cout<<"White please enter your Move: ";
		cin>>move;
        //
        if(move.length()!=4)//not including the null character
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
        cout<<"Black please enter your Move: ";
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
//convertString
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