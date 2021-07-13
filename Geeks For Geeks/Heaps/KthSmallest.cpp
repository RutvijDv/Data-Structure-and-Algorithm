#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {

        if (i < k)
        {
            pq.push(arr[i]);
        }
        else
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }

    return pq.top();
}