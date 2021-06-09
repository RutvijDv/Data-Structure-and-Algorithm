#include <bits/stdc++.h>
using namespace std;

//Naive approach ---> Sort the array

int kthSmallest(int arr[], int l, int r, int k)
{
    sort(arr, arr + r + 1);

    return arr[k - 1];
}

//Min-Max Heap

//Using QuickSort

int partition(int arr[], int l, int r)
{
    //Random Generation of number , this can be avoided
    int n = r - l + 1;
    int pivotIndex = l + rand() % n;
    swap(arr[pivotIndex], arr[r]);

    //General Partition
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[r]);

    return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
    int pos = partition(arr, l, r);

    if (pos + 1 == k)
        return arr[pos];
    else if (pos + 1 > k)
    {
        return kthSmallest(arr, l, pos - 1, k);
    }
    return kthSmallest(arr, pos + 1, r, k);
}