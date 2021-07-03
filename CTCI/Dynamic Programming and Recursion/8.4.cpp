#include <bits/stdc++.h>
using namespace std;

//Simple
void solve(vector<int> arr, int i, int n, vector<int> res)
{
    if (i == n)
    {
        for (int j = 0; j < res.size(); j++)
            cout << res[j] << " ";
        cout << endl;

        return;
    }

    solve(arr, i + 1, n, res);
    res.push_back(arr[i]);
    solve(arr, i + 1, n, res);

    return;
}

//Using Bit logic
void solve(vector<int> arr)
{
    int s = arr.size();

    int x = pow(2, s);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
