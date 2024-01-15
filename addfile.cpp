#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include<conio.h>
using namespace std;
void addProfile();
void createStatFile(string &);
int main()
{
    addProfile();
    return 0;
}
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
//function to create a stats file
void createStatFile(string &a)
{
    ofstream statFile(a);
    statFile<<setw(30)<<right<<"Total Games"<<setw(15)<<right<<"Won"<<setw(15)<<right<<"Lost"<<setw(15)<<right<<"Draws";
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