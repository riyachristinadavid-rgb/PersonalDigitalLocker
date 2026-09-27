#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

#include "Document.h"
#include "Contact.h"
#include "Note.h"
#include "PersonalInfo.h"

using namespace std;

class FileManager
{
public:
static void savePersonalInfo(
    string filename,
    PersonalInfo &info
);

static void saveDocuments(
    string filename,
    vector<Document> &documents
);

static void saveContacts(
    string filename,
    vector<Contact> &contacts
);

static void saveNotes(
    string filename,
    vector<Note> &notes
);
    static void saveData(string filename, string data);

    static string loadData(string filename);

    static void loadPersonalInfo(
        string filename,
        PersonalInfo &info
    );

    static void loadDocuments(
        string filename,
        vector<Document> &documents
    );

    static void loadContacts(
        string filename,
        vector<Contact> &contacts
    );

    static void loadNotes(
        string filename,
        vector<Note> &notes
    );
};

#endif