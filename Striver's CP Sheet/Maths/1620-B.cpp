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
    ll w, h, ans = INT_MIN;
    cin >> w >> h;

    int base;

    for (int i = 0; i < 2; i++)
    {
        int n;
        cin >> n;

        int a, b;

        cin >> a;

        for (int j = 1; j < n; j++)
        {
            cin >> b;
        }

        base = b - a;
        ans = max(ans, base * h);
    }

    for (int i = 0; i < 2; i++)
    {
        int n;
        cin >> n;

        int a, b;

        cin >> a;

        for (int j = 1; j < n; j++)
        {
            cin >> b;
        }

        base = b - a;
        ans = max(ans, base * w);
    }

    cout << ans << "\n";
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