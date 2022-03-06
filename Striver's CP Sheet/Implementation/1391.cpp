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
    int n, m, cnt = 0;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;

            mat[i][j] = x;
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    visited[n - 1][m - 1] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false)
            {

                int x = i, y = j;

                while (visited[x][y] == false)
                {
                    visited[x][y] = true;
                    if (mat[x][y] == 'R')
                    {
                        y++;
                        if (y == m)
                        {
                            y--;
                            mat[x][y] = 'D';
                            cnt++;
                            x++;
                        }
                    }
                    else
                    {
                        x++;
                        if (x == n)
                        {
                            x--;
                            mat[x][y] = 'R';
                            cnt++;
                            y++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << endl;
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