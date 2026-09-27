#ifndef NOTE_H
#define NOTE_H

#include "Record.h"

class Note : public Record
{
private:
    string content;

public:
    Note(int id, string title, string noteContent);

    void display() override;

    bool search(string searchTitle);

    void update();

    string getContent();
};

#endif