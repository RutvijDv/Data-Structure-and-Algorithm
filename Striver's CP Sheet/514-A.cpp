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
    ll n, i, ans;
    cin >> n;

    i = 1;
    ans = 0;

    while (n > 9)
    {
        int t = n % 10;

        t = min(t, 9 - t);

        ans = t * i + ans;
        n = n / 10;
        i = i * 10;
    }

    if (n != 9)
    {
        int t = n % 10;

        t = min(t, 9 - t);

        ans = t * i + ans;
    }
    else
    {
        ans = n * i + ans;
    }

    cout << ans << endl;
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