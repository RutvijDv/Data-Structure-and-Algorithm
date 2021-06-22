#include <bits/stdc++.h>
using namespace std;

//Recursive
int util(int n)
{
    if (n == 0 || n == 1)
        return 1;

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        res += (util(i - 1) * util(n - i)) % 1000000007;
    }

    return res;
}

int numTrees(int N)
{
    int res = util(N);
    return res;
}

//Using DP
int numTrees(int N)
{
    vector<long long> dp(N + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += (dp[j - 1] * dp[i - j]) % 1000000007;
            dp[i] = dp[i] % 1000000007;
        }
    }

    return dp[N];
}