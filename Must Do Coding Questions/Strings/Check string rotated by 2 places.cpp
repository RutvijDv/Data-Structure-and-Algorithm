#include <bits/stdc++.h>
using namespace std;

bool isRotated(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    int n = str1.length();

    if (n <= 2)
    {
        if (str1 == str2)
            return true;
        else
            return false;
    }

    string temp = str1.substr(2, n) + str1.substr(0, 2);
    if (temp == str2)
        return true;

    temp.clear();

    temp = str1.substr(n - 2, n) + str1.substr(0, n - 2);
    if (temp == str2)
        return true;

    return false;
}