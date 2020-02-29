#include <iostream>
#include "User.h"

void User::crypting()
{
    for (int i = 0; i < strLen(Password); i++)
    {
        Password[i]++;
    }
}

void User::encrypting()
{
    for (int i = 0; i < strLen(Password); i++)
    {
        Password[i]--;
    }
}

User::User(const char* newIP, const char* newUsername, const char* newPassword, const char* newTitle):Guest(newIP)
{
    int sizeUsername = strLen(newUsername);
    Username = new char[sizeUsername + 1];
    strCoppy(Username, newUsername);

    int sizePassword = strLen(newPassword);
    Password = new char[sizePassword + 1];
    strCoppy(Password, newPassword);

    int sizeTitle = strLen(newTitle);
    Title = new char[sizeTitle + 1];
    strCoppy(Title, newTitle);

    crypting();
}

User::User(const User& user):Guest(user)
{
    int sizeUsername = strLen(user.Username);
    Username = new char[sizeUsername + 1];
    strCoppy(Username, user.Username);

    int sizePassword = strLen(user.Password);
    Password = new char[sizePassword + 1];
    strCoppy(Password, user.Password);

    int sizeTitle = strLen(user.Title);
    Title = new char[sizeTitle + 1];
    strCoppy(Title, user.Title);
}

User& User::operator=(const User &user)
{
    if (this != &user)
    {
        Guest::operator=(user);
        delete[] Username;
        delete[] Password;
        delete[] Title;

        int sizeUsername = strLen(user.Username);
        Username = new char[sizeUsername + 1];
        strCoppy(Username, user.Username);

        int sizePassword = strLen(user.Password);
        Password = new char[sizePassword + 1];
        strCoppy(Password, user.Password);

        int sizeTitle = strLen(user.Title);
        Title = new char[sizeTitle + 1];
        strCoppy(Title, user.Title);
    }
    return *this;
}

int error = 0;
int correct = 0;
void User::changePassword(char* oldPassword, const char* newPassword)
{
    encrypting();

    int cnt = 0;

    if (strLen(oldPassword) != strLen(Password))
    {
        correct = 0;
        error++;
    }

    else
    {
        for (int i = 0; i < strLen(Password); i++)
        {
            if (Password[i] == oldPassword[i])
            {
                cnt++;
            }

            else
            {
                cnt = 0;
                break;
            }
        }

        if (cnt == strLen(Password))
        {
            int sizePassword = strLen(newPassword);
            delete[] Password;
            Password = new char[sizePassword + 1];
            strCoppy(Password, newPassword);
            correct++;
            error = 0;
        }

        else
        {
            correct = 0;
            error++;
        }
    }

    crypting();
}

void User::print() const
{
    std::cout << std::endl;
    Guest::print();
    std::cout << "Username: " << Username << std::endl;
    if (correct > 0)
    {
        std::cout << "Successfully changed password!" << std::endl;
        correct = 0;
    }
    if (error > 0)
    {
        std::cout << "Incorrect old password!" << std::endl;
        error = 0;
    }
    std::cout << "Title: " << Title << std::endl;
}

User::~User()
{
    delete[] Username;
    delete[] Password;
    delete[] Title;
}
