#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <string>

using namespace std;

class PersonalInfo
{
private:
    string name;
    string email;
    string phone;
    string address;

public:
    PersonalInfo();

    void input();
    void display();
    void update();

    string getName();
    string getEmail();
    string getPhone();
    string getAddress();

    void setData(string n, string e, string p, string a);
};

#endif