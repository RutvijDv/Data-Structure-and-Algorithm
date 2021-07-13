#include <bits/stdc++.h>
using namespace std;

void kthLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        if (i < k - 1)
        {
            cout << -1 << " ";
            pq.push(arr[i]);
        }
        else if (i == k - 1)
        {
            pq.push(arr[i]);
            cout << pq.top() << " ";
        }
        else
        {
            if (arr[i] > pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
            cout << pq.top() << " ";
        }
    }
    return;
}