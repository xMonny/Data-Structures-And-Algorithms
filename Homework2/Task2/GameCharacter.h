#pragma once

class GameCharacter
{
protected:
    char* name;
    int hp;
    int mp;
    int ap;
    int dp;

    int errorStrength = 0;
    int error = 0;
    int correct = 0;

    GameCharacter();

public:
    GameCharacter(const GameCharacter&);
    GameCharacter& operator=(const GameCharacter&);

    char* getName() const;
    int getHP() const;
    int getMP() const;
    int getAP() const;
    int getDP() const;

    int getErrorStrength() const;
    int getError() const;
    int getCorrect() const;

    void getattacked(int);
    void print() const;

    ~GameCharacter();
};
