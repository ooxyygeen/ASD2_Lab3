//
// Created by User on 05.04.2021.
//

#ifndef LAB2_3_DYNAMICARRAY_H
#define LAB2_3_DYNAMICARRAY_H
#include <iostream>
using namespace std;
#include "data.h"

struct DynamicArray
{
    const int alpha = 2;

    int capacity;
    int realSize;
    Data* innerArray;

    DynamicArray();

    ~DynamicArray();

    void push_back(Data* aData);

    void push_front(Data* aData);

    void push(int n, Data* aData);

    Data pop_back();

    Data pop_front();

    int size();

    Data get(int n);
};

#endif //LAB2_3_DYNAMICARRAY_H
