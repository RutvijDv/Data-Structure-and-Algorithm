#include <bits/stdc++.h>
using namespace std;

//Naive approach ---> use 2 for loops

//Efficient approach

vector<int> leaders(int a[], int n)
{

    int maxEle = INT_MIN;
    vector<int> res;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= maxEle)
        {
            res.push_back(a[i]);
            maxEle = a[i];
        }
    }

    reverse(res.begin(), res.end());
    return res;
}