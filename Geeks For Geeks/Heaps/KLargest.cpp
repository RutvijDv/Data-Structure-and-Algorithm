#include <bits/stdc++.h>
using namespace std;

int kLargest(int arr[], int n, int k)
{
    priority_queue<int> pq(arr, arr + n);

    k--;
    while (k--)
        pq.pop();

    return pq.top();
}