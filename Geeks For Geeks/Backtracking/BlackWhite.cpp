#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}

long long solve(int x, int y, int n, int m)
{
    long long count = 0;

    if (isSafe(x - 1, y + 2, n, m))
        count++;
    if (isSafe(x + 1, y + 2, n, m))
        count++;
    if (isSafe(x + 2, y + 1, n, m))
        count++;
    if (isSafe(x + 2, y - 1, n, m))
        count++;
    if (isSafe(x + 1, y - 2, n, m))
        count++;
    if (isSafe(x - 1, y - 2, n, m))
        count++;
    if (isSafe(x - 2, y + 1, n, m))
        count++;
    if (isSafe(x - 2, y - 1, n, m))
        count++;

    return count;
}

long long solve(int N, int M)
{
    long long res = 0, total = (long long)(N * M) * (N * M - 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            res += solve(i, j, N, M);
        }
    }
    // cout<<total<<endl;
    return (total - res) % (1000000007);
}