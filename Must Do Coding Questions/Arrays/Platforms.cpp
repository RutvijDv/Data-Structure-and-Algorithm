#include <bits/stdc++.h>
using namespace std;

//Solution 1

static bool customSort(const pair<int, char> &a, const pair<int, char> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, char>> order;

    for (int i = 0; i < n; i++)
    {
        order.push_back({arr[i], 'a'});
        order.push_back({dep[i], 'd'});
    }

    sort(order.begin(), order.end(), customSort);

    int platforms = 0, result = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        if (order[i].second == 'a')
            platforms++;
        else
            platforms--;

        result = max(result, platforms);
    }

    return result;
}

//Solution 2

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int result = 0, i = 0, j = 0, platforms = 0;

    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }

        result = max(platforms, result);
    }

    return result;
}