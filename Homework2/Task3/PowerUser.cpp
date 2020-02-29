#include <iostream>
#include "PowerUser.h"

PowerUser::PowerUser(const char* newIP, const char* newUsername, const char* newPassword, const char* newTitle):User(newIP, newUsername, newPassword, newTitle)
{
    Reputation = 0;

}

int points = 0;
void PowerUser::giveReputation(PowerUser &given)
{
    int size1 = strLen(Username);
    int size2 = strLen(given.Username);

    int cnt = 0;

    if (size1 <= size2)
    {
        for (int i = 0; i < size2; i++)
        {
            if (given.Username[i] == Username[i])
            {
                cnt++;
            }

            else
            {
                cnt = 0;
                break;
            }
        }

        if (cnt == size2)
        {
            points++;
        }

        else
        {
            given.Reputation++;
            points = 0;
        }
    }

    else
    {
        for (int i = 0; i < size1; i++)
        {
            if (Username[i] == given.Username[i])
            {
                cnt++;
            }

            else
            {
                cnt = 0;
                break;
            }
        }

        if (cnt == size2)
        {
            points++;
        }

        else
        {
            given.Reputation++;
            points = 0;
        }
    }
}

void PowerUser::print() const
{
    User::print();
    std::cout << "Reputation: " << Reputation << std::endl;
    if (points > 0)
    {
        std::cout << "You can't give reputation to yourself!" << std::endl;
        points = 0;
    }
}
