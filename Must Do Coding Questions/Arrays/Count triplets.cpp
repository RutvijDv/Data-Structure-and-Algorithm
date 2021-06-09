#include <bits/stdc++.h>
using namespace std;

int countTriplet(int arr[], int n)
{
    sort(arr, arr + n);
    int x, y, z, p1, p2, result = 0;

    for (int i = n - 1; i >= 2; i--)
    {
        int sum = arr[i];
        p1 = 0;
        p2 = i - 1;

        while (p1 < p2)
        {
            if (arr[p1] + arr[p2] == sum)
            {
                result++;
                p1++;
                p2--;
            }
            else if (arr[p1] + arr[p2] > sum)
                p2--;
            else
                p1++;
        }
    }

    return result;
}