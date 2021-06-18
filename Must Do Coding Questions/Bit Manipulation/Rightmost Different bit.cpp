#include <bits/stdc++.h>
using namespace std;

//Simple approach ---> keep searching bit by bit and find different

//Effecient
int posOfRightMostDiffBit(int m, int n)
{
    int a = abs(m - n);

    if (a == 0)
        return 0;

    int b = a & (a - 1);
    int c = a - b;

    return log2(c) + 1;
}

//Efficient
int posOfRightMostDiffBit(int m, int n)
{
    int a = m ^ n;

    if (a == 0)
        return 0;

    return log2(a & (~(a - 1))) + 1; // Simply log2(a&(-a)) // 2's compliment
}
