#include <bits/stdc++.h>
using namespace std;

#define ll long long

//Recursive

//Using Dp
ll count(ll n)
{
    vector<ll> dp(n + 1, 0);

    dp[0] = 1;
    vector<ll> score;
    score.push_back(3);
    score.push_back(5);
    score.push_back(10);

    for (ll i = 0; i < 3; i++)
    {
        for (ll j = score[i]; j <= n; j++)
        {
            dp[j] = (dp[j] + dp[j - score[i]]);
        }
    }

    return dp[n];
}

//OR
ll count(ll n)
{
    vector<ll> table(n + 1, 0);
    ll i;

    table[0] = 1;

    for (i = 3; i <= n; i++)
        table[i] += table[i - 3];
    for (i = 5; i <= n; i++)
        table[i] += table[i - 5];
    for (i = 10; i <= n; i++)
        table[i] += table[i - 10];

    return table[n];
}