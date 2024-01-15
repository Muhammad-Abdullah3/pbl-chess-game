#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void adProfile();
bool searchProfile(string& name);
void deleteProfile(string& name);

string name;
string line;

int main()
{
    cout << "Enter your name:" << endl;
    getline(cin, name);

    if (searchProfile(name))
    {
        cout << "Player with name: " << name << " already exists. Do you want to delete the profile? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            deleteProfile(name);
            cout << "Profile deleted successfully" << endl;
        }
        else
        {
            cout << "Profile not deleted" << endl;
        }
    }
    else
    {
        adProfile();
        cout << "Profile added successfully" << endl;
    }

    return 0;
}

void adProfile()
{
    ofstream out("profiles.txt", ios::app);
    out << "Name : " << name << endl;
    out.close(); 
}

bool searchProfile(string& name)
{
    ifstream in("profiles.txt");

    while (getline(in, line))
    {
        if (line.find("Name : " + name) != string::npos)
        {
            // Name found
            in.close();
            return true;
        }
    }
    in.close();
    return false;
}

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
