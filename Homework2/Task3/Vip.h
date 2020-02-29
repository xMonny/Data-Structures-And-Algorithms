#include "User.h"
#pragma once

class Vip:public virtual User
{
public:
    Vip(const char*, const char*, const char*, const char*);

    void setTitle(const char*);

    void print() const;
};
