#include <bits/stdc++.h>
using namespace std;

//Naive Solution
int maximizeTheCuts(int n, int x, int y, int z)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;

    int a = maximizeTheCuts(n - x, x, y, z);
    int b = maximizeTheCuts(n - y, x, y, z);
    int c = maximizeTheCuts(n - z, x, y, z);

    int res = max(a, max(b, c));

    if (res == -1)
        return res;
    else
        return res + 1;
}
//Efficient
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> v(n + 1, -1);
    v[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i >= x)
            v[i] = max(v[i], v[i - x]);
        if (i >= y)
            v[i] = max(v[i], v[i - y]);
        if (i >= z)
            v[i] = max(v[i], v[i - z]);

        if (v[i] != -1)
            v[i]++;
    }

    if (v[n] == -1)
        return 0;
    else
        return v[n];
}
