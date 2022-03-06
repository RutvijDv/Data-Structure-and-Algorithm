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
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<char, int> mp;

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    string out;

    for (auto x : mp)
    {
        int c = x.first;
        int cnt = x.second;

        if (cnt % n == 0)
        {
            cnt = cnt / n;
        }
        else
        {
            cout << "-1"
                 << "\n";
            return;
        }

        while (cnt--)
        {
            out += c;
        }
    }

    n--;
    while (n--)
    {
        out += out;
    }

    cout << out << endl;
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