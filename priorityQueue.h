//
// Created by User on 05.04.2021.
//

#ifndef LAB2_3_PRIORITYQUEUE_H
#define LAB2_3_PRIORITYQUEUE_H
#include "binaryHeap.h"

struct PriorityQueue{
    BinaryHeap heap;

    void push(Data data){
        heap.arr.push_back(&data);
        heap.siftUp(heap.arr.realSize-1);
    }

    Data top(){
        if (size() > 0){
            return heap.arr.innerArray[0];
        }
        return heap.arr.innerArray[0] = Data(0, 0, 0);
    }

    Data pop(){
        if (size() > 0){
            Data temp = heap.arr.innerArray[0];
            heap.arr.innerArray[0] = heap.arr.innerArray[heap.arr.realSize-1];
            heap.arr.innerArray[heap.arr.realSize-1] = temp;
            heap.arr.realSize--;
            heap.siftDown(0);
            return temp;
        }
        return heap.arr.innerArray[0] = Data(0, 0, 0);
    }

    int size(){
        return heap.arr.realSize;
    }

    bool empty(){
        if (size() > 0){
            return false;
        }
        return true;
    }
};

#endif //LAB2_3_PRIORITYQUEUE_H
