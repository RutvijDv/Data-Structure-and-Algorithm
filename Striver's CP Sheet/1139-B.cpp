#include <bits/stdc++.h>

using namespace std;

#define read(type) readll<type>() // Fast read
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
    cin >> n;

    vector<ll> arr(n, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll sum = 0;
    ll prev = INT_MAX;

    for (ll i = n - 1; i >= 0; i--)
    {
        ll x = arr[i];

        if (x < prev)
        {
            sum += x;
            // cout << x << endl;
            prev = x;
        }
        else
        {
            if (prev > 0)
            {
                sum += prev - 1;
                prev = prev - 1;
            }
            else
            {
                break;
            }
        }
    }

    cout << sum << endl;
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