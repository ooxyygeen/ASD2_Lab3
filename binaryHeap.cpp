//
// Created by User on 08.04.2021.
//
#include "binaryHeap.h"

int BinaryHeap::getParent(int aIndex) {
    if (aIndex == 0){
        return 0;
    }
    return (aIndex - 1) / 2;
}

int BinaryHeap::getLeftChild(int aIndex) {
    if ((2*aIndex + 1) < arr.realSize){
        return 2 * aIndex + 1;
    }
    return -1;
}

int BinaryHeap::getRightChild(int aIndex) {
    if (2*aIndex + 2 < arr.realSize){
        return 2 * aIndex + 2;
    }
    return -1;
}

void BinaryHeap::siftUp(int aIndex) {
    while (arr.innerArray[getParent(aIndex)] < arr.innerArray[aIndex]){
        Data temp = arr.innerArray[aIndex];
        arr.innerArray[aIndex] = arr.innerArray[getParent(aIndex)];
        arr.innerArray[getParent(aIndex)] = temp;
        aIndex = (aIndex-1)/2;
    }
}

void BinaryHeap::siftDown(int aIndex) {
    while (getLeftChild(aIndex) < arr.realSize && getLeftChild(aIndex) > 0){
        int left = getLeftChild(aIndex);
        int right = getRightChild(aIndex);
        int j = left;   //  index of swappable element
        if (right < arr.realSize && right > 0 &&  arr.innerArray[left] < arr.innerArray[right]){
            j = right;
        }
        if (arr.innerArray[aIndex] < arr.innerArray[j]){
            Data temp = arr.innerArray[aIndex];
            arr.innerArray[aIndex] = arr.innerArray[j];
            arr.innerArray[j] = temp;
            aIndex = j;
        } else{
            break;
        }
    }
}