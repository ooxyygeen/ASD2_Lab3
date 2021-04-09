//
// Created by User on 05.04.2021.
//

#ifndef LAB2_3_DATA_H
#define LAB2_3_DATA_H

struct Data{
    int health, possibleDamage, skill;

    Data();

    Data(int a, int b, int c);

    bool operator <(const Data& aSecond) const;

    bool operator ==(const Data& aSecond) const;
};


#endif //LAB2_3_DATA_H
