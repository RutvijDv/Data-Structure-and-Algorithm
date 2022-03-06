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

    if ((n / 2) % 2 == 1)
    {
        cout << "NO\n";
        return;
    }

    vector<int> e(n / 2, 0);
    vector<int> o(n / 2, 0);

    int num = 1;
    int io = 0;
    int ie = 0;
    bool flag = true;

    while (io < (n / 2))
    {
        if (flag)
        {
            o[io++] = num;
            e[ie++] = num + 1;
        }
        else
        {
            e[ie++] = num;
            o[io++] = num + 1;
        }
        num = num + 3;
        flag = !flag;
    }
    cout << "YES\n";

    for (int i = 0; i < n / 2; i++)
    {
        cout << e[i] << " ";
    }
    for (int i = 0; i < n / 2; i++)
    {
        cout << o[i] << " ";
    }
    cout << "\n";
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