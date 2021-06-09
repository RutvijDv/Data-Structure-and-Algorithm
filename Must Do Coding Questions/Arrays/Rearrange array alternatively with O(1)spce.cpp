#include <bits/stdc++.h>
using namespace std;

void rearrange(long long *arr, int n)
{
    long long max_ele = arr[n - 1] + 1;
    int maxi = n - 1;
    int mini = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i] + (arr[maxi] % max_ele) * max_ele;
            maxi--;
        }
        else
        {
            arr[i] = arr[i] + (arr[mini] % max_ele) * max_ele;
            mini++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / max_ele;
    }

    return;
}

//IDEA

// to store 2 elements a and b at single place use the given formula

// stored_element = a + (b % maxElement) * max_element

// to get a ---> a = stored_element % maxElement

// to get b ---> b = stored_element / maxElement