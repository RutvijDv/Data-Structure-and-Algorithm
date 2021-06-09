#include <bits/stdc++.h>
using namespace std;

//Naive Approach

int circularSubarraySum(int arr[], int n)
{

    int result = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            int idx = (i + j) % n;
            sum += arr[idx];

            result = max(result, sum);
        }
    }

    return result;
}

//Efficient Approach

int kadane(int arr[], int n)
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

int circularSubarraySum(int arr[], int n)
{

    int result = kadane(arr, n);
    if (result < 0)
        return result;

    int arrSum = 0;

    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
        arr[i] = -arr[i];
    }

    int circSum = arrSum + kadane(arr, n);
    result = max(result, circSum);

    return result;
}