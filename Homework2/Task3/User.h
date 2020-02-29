#include "Guest.h"
#pragma once

class User:public Guest
{
protected:
    char* Username;
    char* Password;
    char* Title;

    void crypting();
    void encrypting();

    friend class Admin;

public:
    User(const char*, const char*, const char*, const char*);
    User(const User&);
    User& operator=(const User&);

    void changePassword(char*, const char*); //old, new
    void print() const;

    ~User();
};

