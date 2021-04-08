//
// Created by User on 07.04.2021.
//

#ifndef LAB2_3_HEAPSORT_H
#define LAB2_3_HEAPSORT_H

struct Heap{
    int* arr;
    int size;

    Heap(int* a, int s){
        arr = a;
        size = s;
    }

    int getParent(int aIndex){
        if (aIndex == 0){
            return 0;
        }
        return (aIndex - 1) / 2;
    }

    int getLeftChild(int aIndex){
        if ((2*aIndex + 1) < size){
            return 2 * aIndex + 1;
        }
        return -1;
    }

    int getRightChild(int aIndex){
        if (2*aIndex + 2 < size){
            return 2 * aIndex + 2;
        }
        return -1;
    }

    void siftUp(int aIndex){
        while (arr[getParent(aIndex)] < arr[aIndex]){
            int temp = arr[aIndex];
            arr[aIndex] = arr[getParent(aIndex)];
            arr[getParent(aIndex)] = temp;
            aIndex = (aIndex-1)/2;
        }
    }

    void siftDown(int aIndex){
        while (getLeftChild(aIndex) < size && getLeftChild(aIndex) > 0){
            int left = getLeftChild(aIndex);
            int right = getRightChild(aIndex);
            int j = left;   //  index of swappable element
            if (right < size && right > 0 &&  arr[left] < arr[right]){
                j = right;
            }
            if (arr[aIndex] < arr[j]){
                int temp = arr[aIndex];
                arr[aIndex] = arr[j];
                arr[j] = temp;
                aIndex = j;
            } else{
                break;
            }
        }
    }
};

void heapsort(int* arr, int size){
    Heap heap = Heap(arr, size);
    for (int i = size/2 - 1; i >= 0; --i){
        heap.siftDown(i);
    }
    for (int i = size - 1; i > 0 ; --i) {
        int temp = heap.arr[i];
        heap.arr[i] = heap.arr[0];
        heap.arr[0] = temp;
        heap.size--;
        heap.siftDown(0);
    }
}

#endif //LAB2_3_HEAPSORT_H
