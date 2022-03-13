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
    ll n;
    cin >> n;

    ll sum = (n) * (n + 1) / 2;

    if (sum % 2 == 0)
    {
        cout << "Yes\n";

        cout << "1 2\n";
        cout << n - 1 << " ";

        for (int i = 1; i <= n; i++)
        {
            if (i != 2)
            {
                cout << i << " ";
            }
        }
        cout << "\n";
        return;
    }
    else
    {
        if (sum == 1)
        {
            cout << "No\n";
            return;
        }

        ll x = 3;

        while (x <= n)
        {
            if ((sum - x) % x == 0)
            {
                cout << "Yes\n";

                cout << "1 " << x << "\n";
                cout << n - 1 << " ";

                for (int i = 1; i <= n; i++)
                {
                    if (i != x)
                    {
                        cout << i << " ";
                    }
                }
                cout << "\n";
                return;
            }
            x += 2;
        }
    }

    cout << "No\n";
    return;
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