#include <bits/stdc++.h>
using namespace std;

bool isNumeric(char s)
{
    return (s >= '0' && s <= '9') ? true : false;
}

int atoi(string str)
{
    int n = str.length();
    int res = 0;
    int i = 0;
    bool flag = false;

    if (str[i] == '-')
    {
        flag = true;
        i++;
    }

    while (i < n)
    {

        int x = str[i] - '0';

        if (isNumeric(str[i]))
        {
            res = res * 10 + x;
        }
        else
        {
            return -1;
        }

        i++;
    }

    if (flag)
        return -res;
    else
        return res;
}