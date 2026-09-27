#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

User::User()
{
    username = "";
    password = "";

    ifstream file("user.txt");

    if (file.is_open())
    {
        getline(file, username);
        getline(file, password);

        file.close();
    }
}

void User::registerUser()
{
    cout << "\n--- User Registration ---" << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ofstream file("user.txt");

    if (file.is_open())
    {
        file << username << endl;
        file << password << endl;

        file.close();

        cout << "Registration successful!" << endl;
    }
    else
    {
        cout << "Unable to save user details!" << endl;
    }
}

bool User::login()
{
    string enteredUsername;
    string enteredPassword;

    cout << "\n--- Login ---" << endl;

    cout << "Enter username: ";
    cin >> enteredUsername;

    cout << "Enter password: ";
    cin >> enteredPassword;

    if (enteredUsername == username &&
        enteredPassword == password)
    {
        cout << "Login successful!" << endl;
        return true;
    }

    cout << "Invalid username or password!" << endl;

    return false;
}

void User::logout()
{
    cout << "User logged out successfully!" << endl;
}

string User::getUsername()
{
    return username;
}

string User::getPassword()
{
    return password;
}

bool User::isRegistered()
{
    return !username.empty() && !password.empty();
}