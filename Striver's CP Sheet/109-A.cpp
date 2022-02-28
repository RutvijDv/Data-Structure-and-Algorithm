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
    string out;

    while (n % 7 == 0 && n > 0)
    {
        n = n - 7;
        out = out + "7";
    }

    if (n >= 4)
    {
        n = n - 4;
        out = out + "4";
    }

    while (n % 7 != 0)
    {
        n = n - 4;
        out = out + "4";
    }

    while (n > 0)
    {
        n = n - 7;
        out = out + "7";
    }

    if (n == 0)
        cout << out << endl;
    else
        cout << -1 << endl;
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