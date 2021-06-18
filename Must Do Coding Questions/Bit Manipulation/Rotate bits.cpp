#include <bits/stdc++.h>
using namespace std;

vector<int> rotate(int n, int d)
{
    vector<int> ans;
    d = d % 16;

    unsigned short int resLeft = (n << d) | (n >> (16 - d));
    ans.push_back(resLeft);

    unsigned short int resRight = (n >> d) | (n << (16 - d));
    ans.push_back(resRight);

    return ans;
}