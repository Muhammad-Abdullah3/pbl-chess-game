#include<iostream>
#include<string>
using namespace std;
void inMove(string &,int &);
int main()
{
    int moveNo =1;
    string move;
    inMove(move,moveNo);
    return 0;
}
void inMove(string & move,int & moveNo)
{
    if(moveNo%2==1)
    {
        cout<<"White please enter your Move: ";
		cin>>move;
        //
        if(move.length()!=4)//including the null character
        {//calling the function again
            cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<move;
            inMove(move,moveNo);
        }
        for(int i=0;i<4;i+=2)
        {
            if((move.at(i)>='A'&&move.at(i)<='H')||(move.at(i)>='a'&&move.at(i)<='h'))
            {
                cout<<"Wrong Notation 2";
                inMove(move,moveNo);
            }
        }
        for(int i=1;i<4;i+=2)
        {
            if(move.at(i)>='1'&&move.at(i)<='8')
            {
                cout<<"Wrong Notation 3";
                inMove(move,moveNo);
            }
        }
        cout<<"Right Notation";
    }
    else
    {
        cout<<"Black please enter your Move: ";
        cin>>move;
        int moveLength = move.length();
        if(moveLength!=4)//not including the null character
        {//calling the function again
            cout<<"Wrong Notation";
            inMove(move,moveNo);
        }
        for(int i=0;i==0||i==2;i+=2)
        {
            if((move.at(i)<'A'&&move.at(i)>'H')||(move.at(i)<'a'&&move.at(i)>'h'))
                {
                    cout<<"Wrong Notation";
                    inMove(move,moveNo);
                }
        }
        for(int i=1;i==1||i==3;i+=2)
        {
            if(move.at(i)<'1'||move.at(i)>'8')
                {
                    cout<<"Wrong Notation";
                    inMove(move,moveNo);
                }
            else
            {
                cout<<"Right Notation";
            }
        }
    }
}