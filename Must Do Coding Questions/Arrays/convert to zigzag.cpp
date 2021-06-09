#include <bits/stdc++.h>
using namespace std;

void zigZag(int arr[], int n)
{

    bool flag = true;

    for (int i = 0; i < n - 1; i++)
    {
        if (flag)
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
            flag = !flag;
        }
        else
        {
            if (arr[i] < arr[i + 1])
                swap(arr[i], arr[i + 1]);
            flag = !flag;
        }
    }

    return;
}