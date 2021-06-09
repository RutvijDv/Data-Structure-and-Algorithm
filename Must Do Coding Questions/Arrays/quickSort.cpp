#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[high], arr[i]);

    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pos = partition(arr, low, high);

        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }

    return;
}