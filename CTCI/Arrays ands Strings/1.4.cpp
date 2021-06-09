#include <bits/stdc++.h>
using namespace std;

//straight way method

bool check(int table[])
{
    bool foundOdd = false;

    for (int i = 0; i < 26; i++)
    {
        // cout << table[i] << endl;
        if (table[i] % 2 == 1)
        {
            if (foundOdd)
                return false;
            foundOdd = true;
        }
    }
    return true;
}

int *createTable(string s, int table[])
{

    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            table[s[i] - 'a']++;
        if (s[i] >= 'A' && s[i] <= 'Z')
            table[s[i] - 'A']++;
    }

    return table;
}

bool palindrome(string s)
{
    int table[26] = {0};
    createTable(s, table);
    return check(table);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    if (palindrome("aRccz"))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

//Single pass

bool palindrome(string s)
{
    int countOdd = 0;
    int table[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        int idx;
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            idx = s[i] - 'a';
            table[s[i] - 'a']++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            idx = s[i] - 'A';
            table[s[i] - 'A']++;
        }

        if (table[idx] % 2 == 1)
            countOdd++;
        else
            countOdd--;
    }

    if (countOdd >= 1)
        return false;
    else
        return true;
}

//bitVector

bool palindrome(string s)
{
    int bitVector = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int idx;
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            idx = s[i] - 'a';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            idx = s[i] - 'A';
        }

        idx = 1 << idx;

        if (bitVector & idx)
            bitVector &= ~idx;
        else
            bitVector |= idx;
    }
    if ((bitVector & (bitVector - 1)) == 0)
        return true;
    else
        return false;
}
