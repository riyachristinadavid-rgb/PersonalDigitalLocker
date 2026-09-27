#include "Contact.h"
#include <iostream>

using namespace std;

Contact::Contact(int id, string title, string phoneNumber,
                 string relation)
    : Record(id, title)
{
    phone = phoneNumber;
    relationship = relation;
}

void Contact::display()
{
    cout << "\n--- Contact Details ---" << endl;
    cout << "Record ID: " << getRecordId() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Phone: " << phone << endl;
    cout << "Relationship: " << relationship << endl;
}

bool Contact::search(string searchName)
{
    return getTitle() == searchName;
}

void Contact::update()
{
    cout << "\n--- Update Contact ---" << endl;

    cout << "Enter new phone number: ";
    getline(cin >> ws, phone);

    cout << "Enter new relationship: ";
    getline(cin, relationship);

    cout << "\nContact updated successfully!" << endl;
}
string Contact::getPhone()
{
    return phone;
}

string Contact::getRelationship()
{
    return relationship;
}