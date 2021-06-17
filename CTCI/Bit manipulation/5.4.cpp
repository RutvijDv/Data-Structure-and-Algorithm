#include <bits/stdc++.h>
using namespace std;

//Brute Force ---> Iterate through number on left and right side and check

//Efficient Solution
int getSmaller(int num)
{
    int res = num;
    int c0 = 0;
    int c1 = 0;

    while ((num & 1) == 1 && num != 0)
    {
        c1++;
        num = num >> 1;
    }

    if (num == 0)
        return -1;

    while ((num & 1) == 0 && num != 0)
    {
        c0++;
        num = num >> 1;
    }

    int p = c0 + c1;

    res &= (~(1 << p));
    res |= ((1 << p) - 1);
    res &= ~((1 << (c0 - 1)) - 1);

    return res;
}

int getBig(int num)
{
    int res = num;
    int c0 = 0;
    int c1 = 0;

    while ((num & 1) == 0 && num != 0)
    {
        c0++;
        num = num >> 1;
    }

    while ((num & 1) == 1 && num != 0)
    {
        c1++;
        num = num >> 1;
    }

    if (c0 + c1 == 31 || c0 + c1 == 0)
        return -1;

    int p = c0 + c1;

    res |= (1 << p);
    res &= ~((1 << p) - 1);
    res |= ((1 << (c1 - 1)) - 1);

    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 35;

    bitset<15> bit(n);
    cout << bit << endl;

    int small = getSmaller(n);
    int large = getBig(n);

    bitset<15> bitsmall(small);
    bitset<15> bitbig(large);

    cout << bitsmall << " " << small << endl;
    cout << bitbig << " " << large << endl;

    return 0;
}