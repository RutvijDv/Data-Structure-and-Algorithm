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
    int m, n;
    cin >> m >> n;

    vector<int> rows(m, 0);
    vector<int> cols(n, 0);
    vector<vector<int>> matB(m, vector<int>(n, 0));
    vector<vector<int>> matA(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            matB[i][j] = x;

            if (x == 1)
            {
                rows[i]++;
                cols[j]++;
            }
        }
    }

    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matB[i][j] == 1)
            {
                flag = true;
                if (rows[i] == n && cols[j] == m)
                {
                    matA[i][j] = 1;
                    cnt++;
                }
                else if (!(rows[i] == n || cols[j] == m))
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    if (cnt == 0 && flag)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matA[i][j] << " ";
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