#include "PersonalInfo.h"
#include <iostream>

using namespace std;

PersonalInfo::PersonalInfo()
{
    name = "";
    email = "";
    phone = "";
    address = "";
}

void PersonalInfo::input()
{
    cout << "\n--- Enter Personal Information ---" << endl;

    cout << "Enter name: ";
    getline(cin >> ws, name);

    cout << "Enter email: ";
    getline(cin, email);

    cout << "Enter phone: ";
    getline(cin, phone);

    cout << "Enter address: ";
    getline(cin, address);
}

void PersonalInfo::display()
{
    cout << "\n--- Personal Information ---" << endl;

    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "Address: " << address << endl;
}

void PersonalInfo::update()
{
    cout << "\n--- Update Personal Information ---" << endl;

    cout << "Enter new name: ";
    getline(cin >> ws, name);

    cout << "Enter new email: ";
    getline(cin, email);

    cout << "Enter new phone: ";
    getline(cin, phone);

    cout << "Enter new address: ";
    getline(cin, address);

    cout << "Personal information updated successfully!" << endl;
}

string PersonalInfo::getName()
{
    return name;
}

string PersonalInfo::getEmail()
{
    return email;
}

string PersonalInfo::getPhone()
{
    return phone;
}

string PersonalInfo::getAddress()
{
    return address;
}

void PersonalInfo::setData(
    string n,
    string e,
    string p,
    string a)
{
    name = n;
    email = e;
    phone = p;
    address = a;
}