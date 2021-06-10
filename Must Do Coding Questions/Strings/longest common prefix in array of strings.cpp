#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(string arr[], int n)
{
    string res = "";
    char x;
    int i = 0, j = 0;

    while (j < arr[0].length())
    {
        x = arr[0][j];

        for (int i = 1; i < n; i++)
        {
            if (j >= arr[i].length() || arr[i][j] != x)
            {
                goto fuck;
            }
        }

        j++;
        res += x;
    }

fuck:

    return (res == "") ? "-1" : res;
}