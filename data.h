//
// Created by User on 05.04.2021.
//

#ifndef LAB2_3_DATA_H
#define LAB2_3_DATA_H

struct Data{
    int health, possibleDamage, skill;

    Data(){
        health = rand() % 100 + 1;
        possibleDamage = rand() % 50 + 1;
        skill = rand() % 10 + 1;
    }

    Data(int a, int b, int c){
        health = a;
        possibleDamage = b;
        skill = c;
    }

    bool operator <(const Data aSecond) const{
        if (skill != aSecond.skill){
            return skill < aSecond.skill;
        }
        if (health != aSecond.health){
            return health < aSecond.health;
        }
        return possibleDamage < aSecond.possibleDamage;
    }

    bool operator ==(const Data aSecond) const{
        return health == aSecond.health && possibleDamage == aSecond.possibleDamage && skill == aSecond.skill;
    }
};


#endif //LAB2_3_DATA_H
