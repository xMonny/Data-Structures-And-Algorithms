#pragma once

class Guest
{
private:
    char* IpAddress;

public:
    Guest(const char*);
    Guest(const Guest&);
    Guest& operator=(const Guest&);

    void print() const;

    ~Guest();
};
