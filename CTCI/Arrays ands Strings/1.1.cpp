#include <bits/stdc++.h>
using namespace std;

//O(n^2) solution is possible with O(1) space

//sort the string and check with neighbours

//space-->O(n) time-->O(n)
bool isUnique(string s)
{

    int n = s.length();

    if (n > 256)
        return false;

    bool arr[256] = {false};

    for (int i = 0; i < n; i++)
    {
        int x = s[i];
        if (arr[x] == true)
            return false;
        arr[x] = true;
    }
    return true;
}

//using bit vector (assuming string consist of only small case alphabets)
bool isUnique(string s)
{

    int n = s.length();

    if (n > 256)
        return false;

    int checker = 0;

    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'a';

        if (checker & 1 << x)
            return false;

        checker = checker | 1 << x;
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s = "helsxs";

    if (isUnique(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
