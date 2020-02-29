#include "PowerUser.h"
#include "Vip.h"
#pragma once

class Admin:public PowerUser, public Vip
{
public:
    Admin(const char*, const char*, const char*, const char*);

    void setUsername(const char*);

    void changeUsername(User&, char*);

    void print() const;
};
