#ifndef RECORD_H
#define RECORD_H

#include <string>

using namespace std;

class Record
{
private:
    int recordId;
    string title;

public:
    Record(int id, string t);

    int getRecordId();
    string getTitle();

    virtual void display() = 0;

    virtual ~Record();
};

#endif