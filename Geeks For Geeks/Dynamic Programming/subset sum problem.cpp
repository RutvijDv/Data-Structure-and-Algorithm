#include <bits/stdc++.h>
using namespace std;

//Brute force -> Recursive
bool solve(int a[], int i, int grp1, int grp2)
{
    if (i == 0)
    {
        if (grp1 == grp2)
            return true;
        else
            return false;
    }

    int x = a[i - 1];

    return (solve(a, i - 1, grp1 + x, grp2) || solve(a, i - 1, grp1, grp2 + x));
}

bool findPartition(int a[], int n)
{
    int grp1 = 0, grp2 = 0;
    return solve(a, n, grp1, grp2);
}

//Dp Solution -> Memoisation