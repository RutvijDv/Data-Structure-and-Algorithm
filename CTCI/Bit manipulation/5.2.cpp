#include <bits/stdc++.h>
using namespace std;

string solve(double n)
{
    if (n > 1 || n < 0)
        return "ERROR";

    string s;
    while (n > 0)
    {
        if (s.length() >= 32)
            return "ERROR";

        n = n * 2;
        if (n >= 1)
        {
            s += '1';
            n = n - 1;
        }
        else
        {
            s += '0';
        }
    }

    return s;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double n = 0.72;

    string res = solve(n);

    cout << res << endl;
}