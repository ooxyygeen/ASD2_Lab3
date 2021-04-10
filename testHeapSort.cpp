//
// Created by User on 09.04.2021.
//
#include "testHeapSort.h"

void bubbleSort(int* aArray, int aArraySize)
{
    for(int i = 0; i < aArraySize - 1; i++)
    {
        int swaps = 0;

        for(int j = 0; j < aArraySize - 1 - i; j++)
        {
            if(aArray[j] > aArray[j+1])
            {
                int temp = aArray[j+1];
                aArray[j+1] = aArray[j];
                aArray[j] = temp;
                swaps++;
            }
        }

        if(swaps == 0)
        {
            break;
        }
    }
}

void insertionSort(int* aArray, int aArraySize)
{
    for (int i = 1; i < aArraySize; i++)
    {
        int key = aArray[i];
        int j = i - 1;
        while (j >= 0 && (aArray[j]) >= (key))
        {
            if ((aArray[j]) > (key))
            {
                int temp = aArray[j];
                aArray[j] = aArray[j+1];
                aArray[j+1] = temp;
            }
            j = j - 1;
        }
    }
}

bool testHeapSort(){
    int arr1[N];    //  for heapSort
    int arr2[N];    //  for STL heapSort
    int arr3[N];    //  for bubbleSort
    int arr4[N];    //  for insertionSort

    for (int i = 0; i < N; ++i) {
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = rand();
    }

    clock_t start1 = clock();
    heapsort(arr1, N);
    clock_t finish1 = clock();

    clock_t start2 = clock();
    make_heap(arr2, arr2 + N);
    sort_heap(arr2, arr2 + N);
    clock_t finish2 = clock();

    clock_t start3 = clock();
    bubbleSort(arr3, N);
    clock_t finish3 = clock();

    clock_t start4 = clock();
    insertionSort(arr4, N);
    clock_t finish4 = clock();

    for (int i = 0; i < N; ++i) {
        if (arr1[i] != arr2[i] || arr2[i] != arr3[i] || arr3[i] != arr4[i]){
            cout << "error1" << endl;
            return false;
        }
    }

    clock_t start5 = clock();
    heapsort(arr1, N);
    clock_t finish5 = clock();

    clock_t start6 = clock();
    make_heap(arr2, arr2 + N);
    sort_heap(arr2, arr2 + N);
    clock_t finish6 = clock();

    clock_t start7 = clock();
    bubbleSort(arr3, N);
    clock_t finish7 = clock();

    clock_t start8 = clock();
    insertionSort(arr4, N);
    clock_t finish8 = clock();

    for (int i = 0; i < N; ++i) {
        if (arr1[i] != arr2[i] || arr2[i] != arr3[i] || arr3[i] != arr4[i]){
            cout << "error2" << endl;
            return false;
        }
    }

    reverse(arr1, arr1 + N);
    reverse(arr2, arr2 + N);
    reverse(arr3, arr3 + N);
    reverse(arr4, arr4 + N);

    clock_t start9 = clock();
    heapsort(arr1, N);
    clock_t finish9 = clock();

    clock_t start10 = clock();
    make_heap(arr2, arr2 + N);
    sort_heap(arr2, arr2 + N);
    clock_t finish10 = clock();

    clock_t start11 = clock();
    bubbleSort(arr3, N);
    clock_t finish11 = clock();

    clock_t start12 = clock();
    insertionSort(arr4, N);
    clock_t finish12 = clock();

    for (int i = 0; i < N; ++i) {
        if (arr1[i] != arr2[i] || arr2[i] != arr3[i] || arr3[i] != arr4[i]){
            cout << "error3" << endl;
            return false;
        }
    }

    cout << "Time of sorting arrays for the first time" << endl;
    float time1 = (float(finish1 - start1)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "heapSort: " << left << setw(6) << fixed <<
         setprecision(3) << time1 << right << "seconds" << endl;
    float time2 = (float(finish2 - start2)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "STL heapSort: " << left << setw(6) << fixed <<
         setprecision(3) << time2 << right << "seconds"  << endl;
    float time3 = (float(finish3 - start3)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "bubbleSort: " << left << setw(6) << fixed <<
         setprecision(3) << time3 << right << "seconds"  << endl;
    float time4 = (float(finish4 - start4)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "insertionSort: " << left << setw(6) << fixed <<
         setprecision(3) << time4 << right << "seconds" << endl << endl;

    cout << "Time of sorting already sorted arrays" << endl;
    float time5 = (float(finish5 - start5)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "heapSort: " << left << setw(6) << fixed <<
         setprecision(3) << time5 << right << "seconds" << endl;
    float time6 = (float(finish6 - start6)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "STL heapSort: " << left << setw(6) << fixed <<
         setprecision(3) << time6 << right << "seconds"  << endl;
    float time7 = (float(finish7 - start7)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "bubbleSort: " << left << setw(6) << fixed <<
         setprecision(3) << time7 << right << "seconds"  << endl;
    float time8 = (float(finish8 - start8)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "insertionSort: " << left << setw(6) << fixed <<
         setprecision(3) << time8 << right << "seconds" << endl << endl;

    cout << left << setw(20) << "Time of sorting reversed sorted arrays" << endl;
    float time9 = (float(finish9 - start9)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "heapSort: " << left << setw(6) << fixed <<
         setprecision(3) << time9 << right << "seconds" << endl;
    float time10 = (float(finish10 - start10)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "STL heapSort: " << left << setw(6) << fixed <<
         setprecision(3) << time10 << right << "seconds"  << endl;
    float time11 = (float(finish11 - start11)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "bubbleSort: " << left << setw(6) << fixed <<
         setprecision(3) << time11 << right  << "seconds"  << endl;
    float time12 = (float(finish12 - start12)) / CLOCKS_PER_SEC;
    cout << left << setw(20) << "insertionSort: " << left << setw(6) << fixed <<
         setprecision(3) << time12 << right << "seconds" << endl << endl;

    return true;
}