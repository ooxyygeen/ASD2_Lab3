//
// Created by User on 05.04.2021.
//

#ifndef LAB2_3_BINARYHEAP_H
#define LAB2_3_BINARYHEAP_H

#include "dynamicArray.h"

struct BinaryHeap{
    DynamicArray arr = DynamicArray();

    int getParent(int aIndex);

    int getLeftChild(int aIndex);

    int getRightChild(int aIndex);

    void siftUp(int aIndex);

    void siftDown(int aIndex);
};

#endif //LAB2_3_BINARYHEAP_H
