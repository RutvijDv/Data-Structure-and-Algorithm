#include <bits/stdc++.h>

using namespace std;

#define read(type) readInt<type>() // Fast read
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ll> vii;
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
    ll n;
    string s;

    cin >> n;
    cin >> s;

    ll first = INT_MAX, second = INT_MAX;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (first == INT_MAX)
                first = i;
            else
                second = i;
        }
    }

    if (first == INT_MAX && second == INT_MAX)
    {
        cout << n << endl;
        return;
    }

    if (first != INT_MAX && second != INT_MAX)
    {

        first = min(first, n - first - 1);
        second = min(second, n - second - 1);

        cout << 2 * n - min(2 * first, 2 * second) << endl;
        return;
    }

    first = min(first, n - first - 1);
    cout << 2 * n - 2 * first << endl;
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