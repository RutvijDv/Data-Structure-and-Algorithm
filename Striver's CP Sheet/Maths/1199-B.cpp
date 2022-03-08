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

void PrintDiv(int a, int b, int n)
{

    int c = a / b;

    for (int i = 0; i < n; i++) // iterated
    {
        cout
            << c;
        a -= b * c;
        if (a == 0)
            break; // full division no need to continue
        a *= 10;
        c = a / b;
        if (i == 0)
            cout << ".";
    }
    cout << "\n";
}

void solve()
{
    double l, h;
    cin >> h >> l;

    ld a1 = PrintDiv(pow(l, 2), (2 * h), 100000000);
    ld a2 = h / 2;

    cout
        << a1 - a2 << "\n";
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