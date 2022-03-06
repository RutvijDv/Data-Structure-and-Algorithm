#include <bits/stdc++.h>

using namespace std;

#define read(type) readInt<type>() // Fast read
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vii;
#define umap unordered_map;
#define uset unordered_set;
ll MOD = 100000007;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    string s;
    cin >> s;

    vector<char> arr;

    bool flag = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (flag)
        {
            arr.push_back(s[i]);
        }
        flag = !flag;
    }

    sort(arr.begin(), arr.end());

    flag = true;
    int j = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (flag)
        {
            cout << arr[j];
            j++;
        }
        else
        {
            cout << "+";
        }
        flag = !flag;
    }
}

int main()
{
    fast_cin();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    return 0;
}