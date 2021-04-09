//
// Created by User on 05.04.2021.
//

#ifndef LAB2_3_PRIORITYQUEUE_H
#define LAB2_3_PRIORITYQUEUE_H
#include "binaryHeap.h"

struct PriorityQueue{
    BinaryHeap heap;

    void push(Data data);

    Data top();

    Data pop();

    int size();

    bool empty();
};

#endif //LAB2_3_PRIORITYQUEUE_H
