#include <iostream>
#include "Point2D.h"
#include "Point2D.cpp"
#include "Point3D.h"
#include "Point3D.cpp"
#include "Enum.h"
#include "Entity.h"
#include "Entity.cpp"
#include "Player.h"
#include "Player.cpp"
#include "NPC.h"
#include "NPC.cpp"
#include "Mob.h"
#include "Mob.cpp"
#include "Environment.h"
#include "Environment.cpp"

using namespace std;

int main()
{
    Environment environment;

    Point2D p1(2, 3);
    Point3D p2(3, 3, -5);
    Point3D p3(0, -4, 10);
    Point3D p4;
    Point2D newPoint1(5, -6);
    Point2D newPoint2(0, -4);
    Point3D newPoint3(1, 1, 9);
    Point3D newPoint4(4, 0, -2);
    Point3D newPoint5(1, 0, -1);

    Player player1("Simona", newPoint1, 15, 350);
    Mob mob5("Alisiq", newPoint1, 35, 1400);
    Mob mob1("Mimi", newPoint1, 50, 200);
    Mob mob2("Lesli", p3, 35, 1400);
    Mob mob3("Alf", newPoint4, 90, 100);
    Mob mob4("Mario", newPoint5, 10, 100);
    NPC npc1("Kiki", p2);

    player1.print();

    cout << endl;

    environment.add(player1);
    environment.add(mob5);
    environment.add(mob1);
    environment.add(mob2);
    environment.add(mob3);
    environment.add(mob4);
    environment.add(npc1);
    environment.print();

    cout << endl << "Alisiq and Alf: " << mob5.getDistanceTo(mob3) << endl;
    cout << "Alisiq and Lesli: " << mob5.getDistanceTo(mob2) << endl;
    environment.getClosestAliveEntity(player1, EntityType::Mob)->print();

    environment.generateEntities();

    cout << endl << endl << endl;

    environment.print();
    cout << endl << endl << "Simona and Mario: " << player1.getDistanceTo(mob4) << endl;
    cout << endl << "Simona and Mimi: " << player1.getDistanceTo(mob1) << endl;
    environment.getClosestAliveEntity(player1, EntityType::Mob)->print();

    cout << endl << endl << endl;

    player1.attack(mob5);
    mob5.print();

    cout << endl;
    mob5.attack(mob1);
    mob1.print();

    cout << endl;
    mob5.attack(player1);
    player1.print();

    return 0;
}
