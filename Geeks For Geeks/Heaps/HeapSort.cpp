#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int maxi = i;
    int left = (2 * i + 1);
    int right = (2 * i + 2);

    if (left < n && arr[left] > arr[maxi])
        maxi = left;
    if (right < n && arr[right] > arr[maxi])
        maxi = right;

    if (maxi != i)
    {
        swap(arr[i], arr[maxi]);
        heapify(arr, n, maxi);
    }
    return;
}

// Main function to do heap sort
void HeapSort(int arr[], int n)
{
    // Build max heap
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    return;
}