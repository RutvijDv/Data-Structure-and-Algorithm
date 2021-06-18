#include <bits/stdc++.h>
using namespace std;

int toggleBits(int N, int L, int R)
{

    int a = (1 << (R)) - 1;
    int b = (1 << (L - 1)) - 1;
    int mask = a - b;

    return (N ^ mask);
}