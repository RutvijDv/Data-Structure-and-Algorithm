#include <bits/stdc++.h>
using namespace std;

//O(n) ---> store all words in array in traverse the array in reverse order

//O(1) solution ---> manipulate string itself
string reverseWords(string S)
{
    int l = S.length();
    reverse(S.begin(), S.end());

    int start = 0;
    for (int i = 0; i < l; i++)
    {
        if (S[i] == '.')
        {
            reverse(S.begin() + start, S.begin() + i);
            start = i + 1;
        }
    }
    reverse(S.begin() + start, S.end());

    return S;
}