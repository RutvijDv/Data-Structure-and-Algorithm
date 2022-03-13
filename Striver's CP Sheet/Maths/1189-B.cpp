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

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> ans(n, 0);

    if (arr[n - 1] >= arr[n - 2] + arr[n - 3])
    {
        cout << "NO\n";
        return;
    }

    int i = n - 2;
    int r = n / 2 + 1;
    int l = n / 2 - 1;

    bool flag = true;

    ans[n / 2] = arr[n - 1];

    while (i >= 0)
    {
        if (flag)
        {
            if (l >= 0)
            {
                ans[l] = arr[i];
                l--;
            }
            else
            {
                ans[r] = arr[i];
                r++;
            }
        }
        else
        {
            if (r < n)
            {
                ans[r] = arr[i];
                r++;
            }
            else
            {
                ans[l] = arr[i];
                l--;
            }
        }

        flag = !flag;
        i--;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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

    solve();
    return 0;
}