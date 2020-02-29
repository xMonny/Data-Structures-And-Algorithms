#include "GameCharacter.h"
#include "Guardian.h"

Guardian::Guardian():GameCharacter()
{
    name = "Guardian";
    hp = 40;
    mp = 25;
    ap = 1;
    dp = 3;
}

