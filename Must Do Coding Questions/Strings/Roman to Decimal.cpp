#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str)
{

    unordered_map<char, int> mp;
    int n = str.length();
    int res = 0;
    int curr, temp;

    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    for (int i = 0; i < n - 1; i++)
    {
        curr = mp[str[i]];
        temp = mp[str[i + 1]];

        if (curr < temp)
            res -= curr;
        else
            res += curr;
    }
    curr = mp[str[n - 1]];
    res += curr;

    return res;
}