#include <iostream>
#include <ctime>
#include "testPriorityQueue.h"
#include "testHeapSort.h"
#include "data.h"
#include "dynamicArray.h"
#include "priorityQueue.h"
#include "binaryHeap.h"
using namespace std;

int main() {
    srand(time(nullptr));

    testPriorityQueue();

    testHeapSort();

    return 0;
}
