#include <bits/stdc++.h>
using namespace std;

//Simple approach ---> keep dividing by 2 and get 1

//Effecient
unsigned int getFirstSetBit(int n)
{
    if (n == 0)
        return 0;

    int a = n & (n - 1);
    int b = n - a;

    return log2(b) + 1;
}

//Efficient
unsigned int getFirstSetBit(int n)
{
    if (n == 0)
        return 0;

    return log2(n & (~(n - 1))) + 1; // Simply log2(a&(-a)) // 2's compliment
}