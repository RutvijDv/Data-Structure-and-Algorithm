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

    for (int k = 0; k < 2 * n + 1; k++)
    {

        int i = min(k, n * 2 - k);

        for (int j = 0; j < n - i; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j < i * 2 + 1; j++)
        {
            cout << min(j, i * 2 - j);

            if (j != i * 2)
            {
                cout << " ";
            }
        }
        cout << endl;
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