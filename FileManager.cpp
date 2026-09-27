#include "FileManager.h"
#include <fstream>

using namespace std;

// SAVE RAW DATA
void FileManager::saveData(string filename, string data)
{
    ofstream file(filename);

    if (file.is_open())
    {
        file << data;
        file.close();
    }
}

// LOAD RAW DATA
string FileManager::loadData(string filename)
{
    ifstream file(filename);

    string data;
    string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            data += line + "\n";
        }

        file.close();
    }

    return data;
}

// SAVE PERSONAL INFORMATION
void FileManager::savePersonalInfo(
    string filename,
    PersonalInfo &info)
{
    string data = "";

    data += "Name: ";
    data += info.getName();
    data += "\n";

    data += "Email: ";
    data += info.getEmail();
    data += "\n";

    data += "Phone: ";
    data += info.getPhone();
    data += "\n";

    data += "Address: ";
    data += info.getAddress();
    data += "\n";

    saveData(filename, data);
}

// SAVE DOCUMENTS
void FileManager::saveDocuments(
    string filename,
    vector<Document> &documents)
{
    string data = "";

    for (Document &doc : documents)
    {
        data += "ID: ";
        data += to_string(doc.getRecordId());
        data += "\n";

        data += "Title: ";
        data += doc.getTitle();
        data += "\n";

        data += "Type: ";
        data += doc.getDocumentType();
        data += "\n";

        data += "Number: ";
        data += doc.getDocumentNumber();
        data += "\n";

        data += "Description: ";
        data += doc.getDescription();
        data += "\n";

        data += "----------------------\n";
    }

    saveData(filename, data);
}

// SAVE CONTACTS
void FileManager::saveContacts(
    string filename,
    vector<Contact> &contacts)
{
    string data = "";

    for (Contact &contact : contacts)
    {
        data += "ID: ";
        data += to_string(contact.getRecordId());
        data += "\n";

        data += "Name: ";
        data += contact.getTitle();
        data += "\n";

        data += "Phone: ";
        data += contact.getPhone();
        data += "\n";

        data += "Relationship: ";
        data += contact.getRelationship();
        data += "\n";

        data += "----------------------\n";
    }

    saveData(filename, data);
}

// SAVE NOTES
void FileManager::saveNotes(
    string filename,
    vector<Note> &notes)
{
    string data = "";

    for (Note &note : notes)
    {
        data += "ID: ";
        data += to_string(note.getRecordId());
        data += "\n";

        data += "Title: ";
        data += note.getTitle();
        data += "\n";

        data += "Content: ";
        data += note.getContent();
        data += "\n";

        data += "----------------------\n";
    }

    saveData(filename, data);
}

// LOAD PERSONAL INFORMATION
void FileManager::loadPersonalInfo(
    string filename,
    PersonalInfo &info)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        return;
    }

    string line;

    string name = "";
    string email = "";
    string phone = "";
    string address = "";

    while (getline(file, line))
    {
        if (line.find("Name: ") == 0)
        {
            name = line.substr(6);
        }
        else if (line.find("Email: ") == 0)
        {
            email = line.substr(7);
        }
        else if (line.find("Phone: ") == 0)
        {
            phone = line.substr(7);
        }
        else if (line.find("Address: ") == 0)
        {
            address = line.substr(9);
        }
    }

    info.setData(
        name,
        email,
        phone,
        address
    );

    file.close();
}

// LOAD DOCUMENTS
void FileManager::loadDocuments(
    string filename,
    vector<Document> &documents)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        return;
    }

    string line;

    int id = 0;

    string title = "";
    string type = "";
    string number = "";
    string description = "";

    while (getline(file, line))
    {
        if (line.find("ID: ") == 0)
        {
            id = stoi(line.substr(4));
        }
        else if (line.find("Title: ") == 0)
        {
            title = line.substr(7);
        }
        else if (line.find("Type: ") == 0)
        {
            type = line.substr(6);
        }
        else if (line.find("Number: ") == 0)
        {
            number = line.substr(8);
        }
        else if (line.find("Description: ") == 0)
        {
            description = line.substr(13);

            documents.emplace_back(
                id,
                title,
                type,
                number,
                description
            );
        }
    }

    file.close();
}

// LOAD CONTACTS
void FileManager::loadContacts(
    string filename,
    vector<Contact> &contacts)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        return;
    }

    string line;

    int id = 0;

    string name = "";
    string phone = "";
    string relationship = "";

    while (getline(file, line))
    {
        if (line.find("ID: ") == 0)
        {
            id = stoi(line.substr(4));
        }
        else if (line.find("Name: ") == 0)
        {
            name = line.substr(6);
        }
        else if (line.find("Phone: ") == 0)
        {
            phone = line.substr(7);
        }
        else if (line.find("Relationship: ") == 0)
        {
            relationship = line.substr(14);

            contacts.emplace_back(
                id,
                name,
                phone,
                relationship
            );
        }
    }

    file.close();
}

// LOAD NOTES
void FileManager::loadNotes(
    string filename,
    vector<Note> &notes)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        return;
    }

    string line;

    int id = 0;

    string title = "";
    string content = "";

    while (getline(file, line))
    {
        if (line.find("ID: ") == 0)
        {
            id = stoi(line.substr(4));
        }
        else if (line.find("Title: ") == 0)
        {
            title = line.substr(7);
        }
        else if (line.find("Content: ") == 0)
        {
            content = line.substr(9);

            notes.emplace_back(
                id,
                title,
                content
            );
        }
    }

    file.close();
}