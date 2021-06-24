#include <bits/stdc++.h>
using namespace std;

//Naive Solution
int maximizeTheCuts(int n, int x, int y, int z)
{
    int a = 0, b = 0, c = 0;

    if (n >= x)
        a = maximizeTheCuts(n - x, x, y, z);
    if (n >= y)
        b = maximizeTheCuts(n - y, x, y, z);
    if (n >= z)
        c = maximizeTheCuts(n - z, x, y, z);

    if (a)
        a++;
    if (b)
        b++;
    if (c)
        c++;

    int out = max(a, max(b, c));
    if (n == x || n == y || n == z)
        return max(out, 1);
    else
        return out;
}
//Efficient
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> v(n + 1, 0);
    int a, b, c;

    for (int i = 1; i <= n; i++)
    {

        a = 0;
        b = 0;
        c = 0;

        if (i == x || i == y || i == z)
        {
            v[i] = 1;
        }

        if (i >= x && v[i - x])
            a = 1 + v[i - x];
        if (i >= y && v[i - y])
            b = 1 + v[i - y];
        if (i >= z && v[i - z])
            c = 1 + v[i - z];

        int out = max(a, max(b, c));
        v[i] = max(v[i], out);
    }

    return v[n];
}
