//
// Created by User on 08.04.2021.
//
#include "data.h"
#include <cstdlib>

Data::Data() {
    health = rand() % 100 + 1;
    possibleDamage = rand() % 50 + 1;
    skill = rand() % 10 + 1;
}

Data::Data(int a, int b, int c) {
    health = a;
    possibleDamage = b;
    skill = c;
}

bool Data::operator<(const Data &aSecond) const {
    if (skill != aSecond.skill){
        return skill < aSecond.skill;
    }
    if (health != aSecond.health){
        return health < aSecond.health;
    }
    return possibleDamage < aSecond.possibleDamage;
}

bool Data::operator==(const Data &aSecond) const {
    return health == aSecond.health && possibleDamage == aSecond.possibleDamage && skill == aSecond.skill;

}

