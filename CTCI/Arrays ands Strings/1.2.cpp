#include <bits/stdc++.h>
using namespace std;

//sort the string and compare them to be equal

//Use count array

bool isAnagram(string a, string b)
{

    int n1 = a.length();
    int n2 = b.length();

    if (n1 != n2)
        return false;

    int count[128] = {0};

    for (int i = 0; i < n1; i++)
    {
        int x = a[i];
        count[x]++;
    }

    for (int i = 0; i < n2; i++)
    {
        int x = b[i];
        count[x]--;
        if (count[x] < 0)
            return false;
    }

    return true;
}