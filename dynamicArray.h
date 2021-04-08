//
// Created by User on 05.04.2021.
//

#ifndef LAB2_3_DYNAMICARRAY_H
#define LAB2_3_DYNAMICARRAY_H
using namespace std;
#include "data.h"

struct DynamicArray
{
    const int alpha = 2;

    int capacity;
    int realSize;
    Data* innerArray;

    DynamicArray(){
        capacity = 1;
        realSize = 0;
        innerArray = new Data[capacity];
    }

    ~DynamicArray(){
        delete[] innerArray;
    }

    void push_back(Data* aData)
    {
        if (realSize == capacity)
        {
            capacity *= alpha;
            Data* newArray = new Data[capacity];

            // copy old array
            for (int i = 0; i < realSize; i++)
            {
                newArray[i] = innerArray[i];
            }

            delete[] innerArray;

            innerArray = newArray;
        }

        //push_back
        innerArray[realSize] = *aData;
        realSize++;
    }

    void push_front(Data* aData)
    {
        if (realSize == capacity)
        {
            capacity *= alpha;
            Data* newArray = new Data[capacity];

            // copy and shift old array
            for (int i = 0; i < realSize; i++)
            {
                newArray[i+1] = innerArray[i];
            }

            delete[] innerArray;

            innerArray = newArray;
        }
        else
        {
            // shift elements to the right
            for (int i = realSize; i > 0 ; i--)
            {
                innerArray[i] = innerArray[i-1];
            }
        }

        //push_front
        innerArray[0] = *aData;
        realSize++;
    }

    void push(int n, Data* aData)
    {
        if (n > 0 && n <= realSize)
        {
            if (realSize == capacity)
            {
                capacity *= alpha;
                Data* newArray = new Data[capacity];

                // copy old array to insertion point
                for (int i = 0; i < n-1; i++)
                {
                    newArray[i] = innerArray[i];
                }

                // insert new element
                newArray[n-1] = *aData;

                // shift elements after insertion point to the right
                for (int i = n; i <= realSize ; i++)
                {
                    newArray[i] = innerArray[i-1];
                }

                delete[] innerArray;

                innerArray = newArray;
            }
            else
            {
                // shift elements after insertion point to the right
                for (int i = realSize; i >= n ; i--)
                {
                    innerArray[i] = innerArray[i-1];
                }

                // insert new element
                innerArray[n-1] = *aData;
            }
            realSize++;
        }
        else
        {
            cout << "Inappropriate index" << endl;
        }
    }

    Data pop_back()
    {
        if (realSize)
        {
            realSize--;
            return innerArray[realSize];
        }

        cout << "Array is already empty" << endl;
    }

    Data pop_front()
    {
        if (realSize == 1)
        {
            realSize--;
            return innerArray[0];
        }
        if (realSize > 1)
        {
            Data x = innerArray[0];

            // shift elements to the left
            for (int i = 0; i < realSize - 1; i++)
            {
                innerArray[i] = innerArray[i + 1];
            }

            realSize--;
            return x;
        }

        cout << "Array is already empty" << endl;
    }

    int size()
    {
        return realSize;
    }

    Data* get(int n)
    {
        // search only in valid indices
        if (n <= realSize && n > 0)
        {
            return &innerArray[n-1];
        }
        cout << "Can't return element, inappropriate index" << endl;
    }
};

#endif //LAB2_3_DYNAMICARRAY_H
