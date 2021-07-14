#include <bits/stdc++.h>
using namespace std;

vector<int> nearlySorted(int arr[], int num, int K)
{
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + K + 1);

    int i = K + 1;

    while (i < num)
    {

        int x = pq.top();
        pq.pop();

        res.push_back(x);

        pq.push(arr[i]);
        i++;
    }

    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        res.push_back(x);
    }

    return res;
}