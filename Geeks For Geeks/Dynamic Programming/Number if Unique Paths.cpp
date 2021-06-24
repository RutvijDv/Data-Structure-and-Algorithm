#include <bits/stdc++.h>
using namespace std;

//Simple Solution
int NumberOfPath(int a, int b)
{
    if (a == 1 && b == 1)
        return 0;
    if (a == 1 || b == 1)
        return 1;

    int x = NumberOfPath(a - 1, b);
    int y = NumberOfPath(a, b - 1);

    return x + y;
}

//Efficient Solution
int NumberOfPath(int a, int b)
{
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == 1 || j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[a][b];
}