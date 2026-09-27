#include "Record.h"

Record::Record(int id, string t)
{
    recordId = id;
    title = t;
}

int Record::getRecordId()
{
    return recordId;
}

string Record::getTitle()
{
    return title;
}

Record::~Record()
{
}