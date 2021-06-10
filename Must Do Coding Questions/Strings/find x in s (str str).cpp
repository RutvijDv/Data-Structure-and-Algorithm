#include <bits/stdc++.h>
using namespace std;

int strstr(string s, string x)
{
    int i = 0, j = 0;
    int n1 = s.length();
    int n2 = x.length();
    int res = -1;

    while (i < n1)
    {
        if (s[i] == x[j])
        {
            res = i;
            while (s[i] == x[j])
            {
                i++;
                j++;
                if (j == n2)
                    return res;
            }
        }
        else
        {
            i++;
            j = 0;
        }
    }

    return -1;
}