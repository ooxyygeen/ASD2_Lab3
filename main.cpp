#include <iostream>
#include <ctime>
#include "testPriorityQueue.h"
#include "testHeapSort.h"
using namespace std;

int main() {
    srand(time(nullptr));

    testPriorityQueue();

    testHeapSort();

    return 0;
}
