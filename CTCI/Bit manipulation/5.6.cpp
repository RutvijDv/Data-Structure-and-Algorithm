#include <bits/stdc++.h>
using namespace std;

//O(n) simple Solution
int countBitsFlip(int a, int b)
{

    int res = 0;

    while (a && b)
    {
        if ((a & 1) != (b & 1))
            res++;
        a = a >> 1;
        b = b >> 1;
    }

    while (a)
    {
        if ((a & 1) == 1)
            res++;
        a = a >> 1;
    }

    while (b)
    {
        if ((b & 1) == 1)
            res++;
        b = b >> 1;
    }

    return res;
}

//Efficient Solution
int countBitsFlip(int a, int b)
{
    int res = 0;
    int temp = a ^ b;

    while (temp)
    {
        res++;
        temp = (temp & (temp - 1));
    }

    return res;
}