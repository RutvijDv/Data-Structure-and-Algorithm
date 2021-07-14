#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);

    long long res = 0;
    long long x, y;

    while (pq.size() > 1)
    {

        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();

        res += x + y;

        pq.push(x + y);
    }

    return res;
}