#include "Document.h"
#include <iostream>

using namespace std;

Document::Document(int id, string title, string type,
                   string number, string desc)
    : Record(id, title)
{
    documentType = type;
    documentNumber = number;
    description = desc;
}

void Document::display()
{
    cout << "\n--- Document Details ---" << endl;

    cout << "Record ID: " << getRecordId() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Document Type: " << documentType << endl;
    cout << "Document Number: " << documentNumber << endl;
    cout << "Description: " << description << endl;
}

bool Document::search(string searchTitle)
{
    return getTitle() == searchTitle;
}

void Document::update()
{
    cout << "\n--- Update Document ---" << endl;

    cout << "Enter new document type: ";
    getline(cin >> ws, documentType);

    cout << "Enter new document number: ";
    getline(cin, documentNumber);

    cout << "Enter new description: ";
    getline(cin, description);

    cout << "\nDocument updated successfully!" << endl;
}

string Document::getDocumentType()
{
    return documentType;
}

string Document::getDocumentNumber()
{
    return documentNumber;
}

string Document::getDescription()
{
    return description;
}