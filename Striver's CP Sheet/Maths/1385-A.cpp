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
    int x, y, z;
    cin >> x >> y >> z;

    unordered_map<int, int> mp;

    mp[x]++;
    mp[y]++;
    mp[z]++;

    if (mp[x] >= 2 && x >= y && x >= z)
    {
        cout << "YES"
             << "\n";
        cout << x << " " << min(y, z) << " " << min(y, z) << "\n";
    }

    else if (mp[y] >= 2 && y >= x && y >= z)
    {
        cout << "YES"
             << "\n";
        cout << y << " " << min(x, z) << " " << min(x, z) << "\n";
    }

    else
        cout << "NO"
             << "\n";
}

int main()
{
    fast_cin();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}