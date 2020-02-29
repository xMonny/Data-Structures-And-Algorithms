#include <iostream>
#include "Vip.h"

Vip::Vip(const char* newIP, const char* newUsername, const char* newPassword, const char* newTitle):User(newIP, newUsername, newPassword, newTitle)
{

}

void Vip::setTitle(const char* newTitle)
{
    if (newTitle == nullptr)
    {
        delete[] newTitle;
        Title = nullptr;
        return;
    }

    int sizeTitle = strLen(newTitle);
    delete[] Title;
    Title = new char[sizeTitle + 1];
    strCoppy(Title, newTitle);
}

void Vip::print() const
{
    User::print();
}
