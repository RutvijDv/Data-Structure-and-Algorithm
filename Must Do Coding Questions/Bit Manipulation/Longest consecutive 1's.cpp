#include <bits/stdc++.h>
using namespace std;

//Simple
int maxConsecutiveOnes(int N)
{
    int res = 0, count = 0;

    while (N)
    {
        if (N & 1)
            count++;
        else
        {
            res = max(res, count);
            count = 0;
        }

        N = N >> 1;
    }
    res = max(res, count);

    return res;
}

//Efficient
int maxConsecutiveOnes(int N)
{
    int res = 0;

    while (N)
    {
        N = N & (N << 1);
        res++;
    }

    return res;
}