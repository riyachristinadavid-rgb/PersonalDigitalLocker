#ifndef CONTACT_H
#define CONTACT_H

#include "Record.h"

class Contact : public Record
{
private:
    string phone;
    string relationship;

public:
    Contact(int id, string title, string phoneNumber,
            string relation);

    void display() override;

    bool search(string searchName);

    void update();

    string getPhone();
    string getRelationship();
};

#endif