#include <bits/stdc++.h>
using namespace std;

//Using Self-built Function
bool isSubString(string s1, string s2)
{

    int i = 0, j = 0;

    while (i < s1.length() && j < s2.length())
    {
        if (s1[i] == s2[j])
        {

            i++;
            j++;
        }
        else
        {
            i++;
            if (j != 0)
            {
                j = 0;
                i--;
            }
        }
    }
    if (j == s2.length())
        return true;
    return false;
}

bool areRotations(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 != len2)
        return false;

    string s = s1 + s1;
    if (isSubString(s, s2))
        return true;
    return false;
}

//Use STL
bool areRotations(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 != len2)
        return false;

    string s = s1 + s1;
    if (s.find(s2) != string::npos)
        return true;
    return false;
}
