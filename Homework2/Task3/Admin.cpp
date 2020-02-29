#include <iostream>
#include "Admin.h"

Admin::Admin(const char* newIP, const char* newUsername, const char* newPassword, const char* newTitle):Vip(newIP, newUsername, newPassword, newTitle), PowerUser(newIP, newUsername, newPassword, newTitle), User(newIP, newUsername, newPassword, newTitle)
{

}

void Admin::setUsername(const char* newUsername)
{
    if (newUsername == nullptr)
    {
        delete[] Username;
        Username = nullptr;
        return;
    }

    int sizeUsername = strLen(newUsername);
    delete[] Username;
    Username = new char[sizeUsername + 1];
    strCoppy(Username, newUsername);
}

void Admin::changeUsername(User &user, char* newUsername)
{
    int sizeUsername = strLen(newUsername);
    delete[] user.Username;
    user.Username = new char[sizeUsername + 1];
    strCoppy(user.Username, newUsername);
}

void Admin::print() const
{
    PowerUser::print();
}
