#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "Record.h"

class Document : public Record
{
private:
    string documentType;
    string documentNumber;
    string description;

public:
    Document(int id, string title, string type,
             string number, string desc);

    void display() override;

    bool search(string searchTitle);

    void update();

    string getDocumentType();
    string getDocumentNumber();
    string getDescription();
};

#endif