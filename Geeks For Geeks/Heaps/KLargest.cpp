#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int> pq(arr, arr + n);
    vector<int> v;

    while (k--)
    {
        v.push_back(pq.top());
        pq.pop();
    }

    return v;
}