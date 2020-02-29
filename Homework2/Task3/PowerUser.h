#include "User.h"
#pragma once

class PowerUser:public virtual User
{
protected:
    int Reputation;

public:
    PowerUser(const char*, const char*, const char*, const char*);

    void giveReputation(PowerUser&);

    void print() const;
};
