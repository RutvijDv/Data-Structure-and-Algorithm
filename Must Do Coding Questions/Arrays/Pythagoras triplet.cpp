#include <bits/stdc++.h>
using namespace std;

//Naive Solution ---> run 3 for loops

//Better Solution ---> use Sorting

bool checkTriplet(int arr[], int n)
{

    for (int i = 0; i < n; i++)
        arr[i] = arr[i] * arr[i];

    sort(arr, arr + n);

    for (int i = n - 1; i >= 2; i--)
    {
        int target = arr[i];
        int x = 0, y = i - 1;

        while (x < y)
        {
            if (arr[x] + arr[y] == target)
                return true;

            if (arr[x] + arr[y] > target)
                y--;
            else
                x++;
        }
    }

    return false;
}

//Better Solution ---> use hashing

bool checkTriplet(int arr[], int n)
{

    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
        arr[i] = arr[i] * arr[i];

    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (map[arr[i] + arr[j]])
                return true;
        }
    }

    return false;
}

//Better Solution ---> use hashing ---> this solution can also be used for getting pythagoras triplets in a given range

bool checkTriplet(int arr[], int n)
{

    unordered_map<int, int> map;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
        maxi = max(arr[i], maxi);
    }

    for (int i = 1; i < maxi + 1; i++)
    {
        if (!map[i])
            continue;

        for (int j = 1; j < maxi + 1; j++)
        {
            if (i == j || !map[j])
                continue;

            int val = sqrt(i * i + j * j);

            if (val * val != i * i + j * j)
                continue;

            if (map[val])
                return true;
        }
    }
    return false;
}