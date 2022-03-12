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
    ll r, g, b, w;

    cin >> r >> g >> b >> w;

    ll sum = r + g + b + w;

    int even = 0;
    int odd = 0;

    if (r % 2 == 0)
        even++;
    else
        odd++;

    if (g % 2 == 0)
        even++;
    else
        odd++;

    if (b % 2 == 0)
        even++;
    else
        odd++;

    if (w % 2 == 0)
        even++;
    else
        odd++;

    if (odd <= 1)
    {
        cout << "Yes\n";
    }
    else
    {
        int x = 1;
        while (r > 0 && g > 0 && b > 0 && x--)
        {
            r--;
            g--;
            b--;
            w += 3;

            int cnt = 0;

            if (r % 2 == 1)
                cnt++;
            if (g % 2 == 1)
                cnt++;
            if (b % 2 == 1)
                cnt++;
            if (w % 2 == 1)
                cnt++;

            if (cnt <= 1)
            {
                cout << "Yes\n";
                return;
            }
        }

        cout << "No\n";
    }
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