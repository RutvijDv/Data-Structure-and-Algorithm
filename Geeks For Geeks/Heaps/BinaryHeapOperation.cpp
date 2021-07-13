#include <bits/stdc++.h>
using namespace std;

struct MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

    // Constructor for Min Heap
    MinHeap(int c)
    {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int); // Implemented in user editor
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

int MinHeap::extractMin()
{
    if (heap_size == 0)
        return -1;
    int res = harr[0];

    swap(harr[0], harr[heap_size - 1]);
    heap_size--;

    MinHeapify(0);

    return res;
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    if (i >= heap_size)
        return;
    decreaseKey(i, INT_MIN);

    extractMin();

    return;
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k)
{
    if (heap_size != capacity)
    {

        harr[heap_size] = k;
        heap_size++;
        int i = heap_size - 1;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }

    return;
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
    return;
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}