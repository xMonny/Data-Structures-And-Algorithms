#include <iostream>
#include <limits>
#include "GameCharacter.h"
#include "GameCharacter.cpp"
#include "Warrior.h"
#include "Warrior.cpp"
#include "Guardian.h"
#include "Guardian.cpp"
#include "Wizzard.h"
#include "Wizzard.cpp"

using namespace std;

int main()
{
    Warrior warrior;

    Guardian guardian;

    Wizzard wizzard;

    int strength;
    char* s = new char[1];

    do
    {
        cout << "Choose a character: " << endl;
        cout << "(1) Warrior " << endl;
        cout << "(2) Guardian " << endl;
        cout << "(3) Wizzard " << endl;
        cout << "(Q) Quit " << endl;

        cin >> s;

        if (s[0] == '1')
        {
            warrior.print();
            cout << "Do you want to attack him?(y/n) ";
            cin >> s;
            if (s[0] == 'y' || s[0] == 'Y')
            {
                cout << "Choose your strength: ";
                cin >> strength;
                while (cin.fail())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Invalid damage." << endl;
					cout<<"Choose your strength: ";
					cin >> strength;
				}
                warrior.getattacked(strength);

                if (warrior.getErrorStrength() > 0)
                {
                    std::cout << "Your strength can't be below 0!" << std::endl;
                    std::cout << std::endl;
                }

                if (warrior.getError() > 0)
                {
                    std::cout << "The HP will be under 0. You can't kill " << warrior.getName() << "! His HP now is " << warrior.getHP() << "." << std::endl;
                    std::cout << std::endl;
                }

                if (warrior.getCorrect() > 0)
                {
                    std::cout << "Hello! I am " << warrior.getName() << " and I was attacked with " << strength << " damage but my defense power is " << warrior.getDP() << ". My current HP is " << warrior.getHP() << "." <<std::endl;
                    std::cout << std::endl;
                }

                cin.clear();
				cin.ignore();
            }
        }

        if (s[0] == '2')
        {
            guardian.print();
            cout << "Do you want to attack him?(y/n) ";
            cin >> s[0];
            if (s[0] == 'y' || s[0] == 'Y')
            {
                cout << "Choose your strength: ";
                cin >> strength;
                while (cin.fail())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Invalid damage." << endl;
					cout<<"Choose your strength: ";
					cin >> strength;
				}
				guardian.getattacked(strength);

				if (guardian.getErrorStrength() > 0)
                {
                    std::cout << "Your strength can't be below 0!" << std::endl;
                    std::cout << std::endl;
                }

                if (guardian.getError() > 0)
                {
                    std::cout << "The HP will be under 0. You can't kill " << guardian.getName() << "! His HP now is " << guardian.getHP() << "." << std::endl;
                    std::cout << std::endl;
                }

                if (guardian.getCorrect() > 0)
                {
                    std::cout << "Hello! I am " << guardian.getName() << " and I was attacked with " << strength << " damage but my defense power is " << guardian.getDP() << ". My current HP is " << guardian.getHP() << "." <<std::endl;
                    std::cout << std::endl;
                }

                cin.clear();
				cin.ignore();
            }
        }

        if (s[0] == '3')
        {
            wizzard.print();
            cout << "Do you want to attack him?(y/n) ";
            cin >> s;
            if (s[0] == 'y' || s[0] == 'Y')
            {
                cout << "Choose your strength: ";
                cin >> strength;
                while (cin.fail())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Invalid damage." << endl;
					cout<<"Choose your strength: ";
					cin >> strength;
				}
				wizzard.getattacked(strength);

				if (wizzard.getErrorStrength() > 0)
                {
                    std::cout << "Your strength can't be below 0!" << std::endl;
                    std::cout << std::endl;
                }

                if (wizzard.getError() > 0)
                {
                    std::cout << "The HP will be under 0. You can't kill " << wizzard.getName() << "! His HP now is " << wizzard.getHP() << "." << std::endl;
                    std::cout << std::endl;
                }

                if (wizzard.getCorrect() > 0)
                {
                    std::cout << "Hello! I am " << wizzard.getName() << " and I was attacked with " << strength << " damage but my defense power is " << wizzard.getDP() << ". My current HP is " << wizzard.getHP() << "." <<std::endl;
                    std::cout << std::endl;
                }

                cin.clear();
				cin.ignore();
            }
        }

        if (s[0] == 'q' || s[0] == 'Q')
        {
            break;
        }
    }
    while (true);

    return 0;
}
