#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int i, int j)
{
    int mask1 = (1 << (j + 1)) - 1;
    int mask2 = ~((1 << i) - 1);
    int mask = ~(mask1 & mask2);

    n = n & mask;
    n = n | (m << i);

    return n;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 1024;
    int m = 19;
    int i = 2;
    int j = 6;

    int res = solve(n, m, i, j);

    cout << res << endl;
}