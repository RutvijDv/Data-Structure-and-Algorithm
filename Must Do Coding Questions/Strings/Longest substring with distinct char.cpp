#include <bits/stdc++.h>
using namespace std;

int longestSubstrDitinctChars(string S)
{
    int n = S.length();
    int start = 0;
    int end = 1;
    int res = 1;

    vector<int> v(26, 0);
    v[S[0] - 'a'] += 1;

    while (end < n)
    {
        v[S[end] - 'a'] += 1;

        if (v[S[end] - 'a'] > 1)
        {
            while (v[S[end] - 'a'] > 1)
            {
                v[S[start] - 'a'] -= 1;
                start++;
            }
            end++;
        }
        else
        {
            res = max(res, end - start + 1);
            end++;
        }
    }

    return res;
}