#include <bits/stdc++.h>
using namespace std;

//Simple ---> generate all substring and add them

//Using Dp
long long sumSubstrings(string s)
{
    int n = s.length();
    long long res = 0;
    vector<long long> dp(n, 0);

    dp[0] = (s[0] - '0');
    res = dp[0] % 1000000007;

    for (int i = 1; i < n; i++)
    {
        dp[i] = ((i + 1) * (s[i] - '0') + dp[i - 1] * 10) % 1000000007;
        res += dp[i] % 1000000007;
        res = res % 1000000007;
    }

    return res;
}