#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    User();

    void registerUser();
    bool login();
    void logout();

    string getUsername();
    string getPassword();

    bool isRegistered();
};

#endif