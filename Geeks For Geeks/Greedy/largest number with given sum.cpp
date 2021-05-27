#include <bits/stdc++.h>
using namespace std;

string largestNumber(int n, int sum)
{
    string output;

    for (int i = 0; i < n; i++)
    {
        int val = 0;
        if (sum > 9)
        {
            val = 9;
            sum -= 9;
        }
        else
        {
            val = sum;
            sum = 0;
        }

        output += val + '0';
    }

    if (sum > 0)
    {
        return "-1";
    }

    return output;
}