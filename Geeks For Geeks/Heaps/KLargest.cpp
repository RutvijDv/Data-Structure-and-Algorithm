#include <bits/stdc++.h>
using namespace std;

//Sorting -> Naive

//Use Max Heap -> not Efficient

//Use Min Heap -> Efficient
vector<int> kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v(k, 0);

    for (int i = 0; i < n; i++)
    {

        if (i < k)
            pq.push(arr[i]);
        else if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    for (int i = k - 1; i >= 0; i--)
    {
        v[i] = pq.top();
        pq.pop();
    }

    return v;
}