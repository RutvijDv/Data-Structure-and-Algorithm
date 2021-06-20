#include <bits/stdc++.h>
using namespace std;

//Recursive
int solve(int value)
{
    if (value == 0)
        return 1;
    if (value <= 0)
        return 0;

    int a, b, c;

    a = solve(value - 1);
    b = solve(value - 2);

    return (a + b) % 1000000007;
}

int countWays(int n)
{
    return (solve(n) % 1000000007);
}