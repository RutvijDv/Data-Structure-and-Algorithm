#include <bits/stdc++.h>
using namespace std;

//Naive Solution ---> Go through every element and count its set bits

//Efficient Solution
int countSetBits(int n)
{
    n++;
    int temp = 2;
    int res = 0;

    while (n / temp > 0)
    {
        int x = n / temp;
        res += x * (temp / 2);
        res += max(0, (n % temp - (temp / 2)));
        temp = temp * 2;
    }

    res += n - (temp / 2);

    return res;
}
