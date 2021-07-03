#include <bits/stdc++.h>
using namespace std;

//Simple

int recur(int x, int temp)
{
    if (temp == 0 || x == 0)
        return 0;
    if (temp == 1)
        return x;

    int res;

    if (temp % 2 == 0)
    {
        res = recur(x, temp / 2);
        res += res;
    }
    else
    {
        res = recur(x, temp / 2) + recur(x, (temp / 2) + 1);
    }

    return res;
}

//DP

int recur(int x, int temp, vector<int> &dp)
{
    if (temp == 0 || x == 0)
        return 0;
    if (temp == 1)
        return x;
    if (dp[temp] > 0)
        return dp[temp];

    int res;

    if (temp % 2 == 0)
    {
        res = recur(x, temp / 2, dp);
        res += res;
    }
    else
    {
        res = recur(x, temp / 2, dp) + recur(x, (temp / 2) + 1, dp);
    }

    return res;
}

//Tactics

int recur(int x, int temp)
{
    if (temp == 0 || x == 0)
        return 0;
    if (temp == 1)
        return x;

    int res;

    if (temp % 2 == 0)
    {
        res = recur(x, temp / 2);
        res += res;
    }
    else
    {
        res = recur(x, temp / 2);
        res += res;
        res += x;
    }

    return res;
}