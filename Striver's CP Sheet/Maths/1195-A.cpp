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
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        mp[x]++;
    }

    int ans = 0;
    int temp = 0;

    for (auto x : mp)
    {
        int drink = x.first;
        int quantity = x.second;

        ans += (quantity / 2) * 2;
        temp += quantity % 2;
    }

    ans += temp / 2 + temp % 2;

    cout << ans << "\n";
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