#include "Note.h"
#include <iostream>

using namespace std;

Note::Note(int id, string title, string noteContent)
    : Record(id, title)
{
    content = noteContent;
}

void Note::display()
{
    cout << "\n--- Note Details ---" << endl;

    cout << "Record ID: " << getRecordId() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Content: " << content << endl;
}

bool Note::search(string searchTitle)
{
    return getTitle() == searchTitle;
}

void Note::update()
{
    cout << "\n--- Update Note ---" << endl;

    cout << "Enter new note content: ";
    getline(cin >> ws, content);

    cout << "\nNote updated successfully!" << endl;
}

string Note::getContent()
{
    return content;
}