#include <bits/stdc++.h>
using namespace std;

//NAIVE APPROACH

int maxSubarraySumNaive(int arr[], int n)
{
    int res = arr[0];

    for (int i = 0; i < n; i++)
    {
        int curr = 0;

        for (int j = i; j < n; j++)
        {
            curr = curr + arr[j];

            res = max(res, curr);
        }
    }

    return res;
}

//Efficient Approach

int maxSubarraySum(int arr[], int n)
{

    int result = arr[0];
    int max_ending = arr[0];

    for (int i = 1; i < n; i++)
    {
        max_ending = max(max_ending + arr[i], arr[i]);
        result = max(max_ending, result);
    }

    return result;
}
