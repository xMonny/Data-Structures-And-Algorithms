#include "GameCharacter.h"
#include <cstring>

GameCharacter::GameCharacter()
{
    name = new char[1];
    name[0] = '\0';

    hp = 0;
    mp = 0;
    ap = 0;
    dp = 0;
}

GameCharacter::GameCharacter(const GameCharacter &game)
{
    int sizeName = strlen(game.name);
    name = new char[sizeName + 1];
    strcpy(name, game.name);

    hp = game.hp;
    mp = game.mp;
    ap = game.ap;
    dp = game.ap;
}

GameCharacter& GameCharacter::operator=(const GameCharacter &game)
{
    if (this != &game)
    {
        delete[] name;

        int sizeName = strlen(game.name);
        name = new char[sizeName + 1];
        strcpy(name, game.name);

        hp = game.hp;
        mp = game.mp;
        ap = game.ap;
        dp = game.dp;
    }
    return *this;
}

char* GameCharacter::getName() const
{
    return name;
}

int GameCharacter::getHP() const
{
    return hp;
}

int GameCharacter::getMP() const
{
    return mp;
}

int GameCharacter::getAP() const
{
    return ap;
}

int GameCharacter::getDP() const
{
    return dp;
}

void GameCharacter::getattacked(int damage)
{
    int currentHP = hp;

    if (damage < 0)
    {
        errorStrength++;
        error = 0;
        correct = 0;
    }

    else
    {
        if (damage != 0 && hp != 0)
        {
            hp = (hp + dp) - damage;
        }

        if (hp < 0)
        {
            hp = currentHP;

            error++;
            errorStrength = 0;
            correct = 0;
        }

        else
        {
            correct++;
            errorStrength = 0;
            error = 0;
        }
    }
}

int GameCharacter::getErrorStrength() const
{
    return errorStrength;
}

int GameCharacter::getError() const
{
    return error;
}

int GameCharacter::getCorrect() const
{
    return correct;
}

void GameCharacter::print() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "MP: " << mp << std::endl;
    std::cout << "AP: " << ap << std::endl;
    std::cout << "DP: " << dp << std::endl;
}

GameCharacter::~GameCharacter()
{
    delete[] name;
}
