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
    string p, h;
    cin >> p >> h;

    if (p.length() > h.length())
    {
        cout << "NO" << endl;
        return;
    }

    vector<int> countP(26, 0);
    vector<int> countH(26, 0);

    for (int i = 0; i < p.size(); i++)
    {
        countH[h[i] - 'a']++;
        countP[p[i] - 'a']++;
    }
    int j = 0;

    if (countH == countP)
    {
        cout << "YES" << endl;
        return;
    }

    for (int i = p.size(); i < h.size(); i++)
    {
        countH[h[i] - 'a']++;
        countH[h[j] - 'a']--;
        j++;

        if (countH == countP)
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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