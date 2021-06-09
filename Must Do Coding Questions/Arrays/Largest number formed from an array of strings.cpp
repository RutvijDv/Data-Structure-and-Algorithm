#include <bits/stdc++.h>
using namespace std;



bool mycompare(string a, string b)
{
    string s1 = a + b, s2 = b + a;

    if (s1 > s2)
        return true;
    return false;
}

string printLargest(vector<string> &arr)
{

    string res;

    sort(arr.begin(), arr.end(), mycompare);

    for (int i = 0; i < arr.size(); i++)
        res += arr[i];

    return res;
}