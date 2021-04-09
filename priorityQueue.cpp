//
// Created by User on 09.04.2021.
//
#include "priorityQueue.h"

void PriorityQueue::push(Data data) {
    heap.arr.push_back(&data);
    heap.siftUp(size()-1);
}

Data PriorityQueue::top() {
    if (size() > 0){
        return heap.arr.innerArray[0];
    }
    return Data(0, 0, 0);
}

Data PriorityQueue::pop() {
    if (size() > 0){
        Data temp = heap.arr.innerArray[0];
        heap.arr.innerArray[0] = heap.arr.innerArray[size()-1];
        heap.arr.innerArray[size()-1] = temp;
        heap.arr.realSize--;
        heap.siftDown(0);
        return temp;
    }
    return Data(0, 0, 0);
}

int PriorityQueue::size() {
    return heap.arr.realSize;
}

bool PriorityQueue::empty() {
    return !size();
}