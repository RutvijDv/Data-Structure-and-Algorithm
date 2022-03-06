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
    string s1, s2;
    cin >> s1 >> s2;

    int h1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int h2 = (s2[0] - '0') * 10 + (s2[1] - '0');

    int m1 = (s1[3] - '0') * 10 + (s1[4] - '0');
    int m2 = (s2[3] - '0') * 10 + (s2[4] - '0');

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;

    int t = (t1 + t2) / 2;

    int h = t / 60;
    int m = t % 60;

    if (h < 10)
        cout << "0";
    cout << h << ":";

    if (m < 10)
        cout << "0";
    cout << m;
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