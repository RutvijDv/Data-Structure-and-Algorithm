#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int capacity;

public:
    MinHeap(int c)
    {
        size = 0;
        capacity = c;
        arr = new int[c];
    }

    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int parent(int i) { return (i - 1) / 2; }

    void minHeapify(int i)
    {
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if (lt < size && arr[lt] < arr[i])
            smallest = lt;
        if (rt < size && arr[rt] < arr[smallest])
            smallest = rt;
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int extractMin()
    {
        if (size <= 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);

        return arr[size];
    }
};
