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
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    vector<int> temp(n, 0);

    pq1.push(arr[0]);
    temp[0]++;
    pq2.push(arr[n - 1]);
    temp[n - 1]++;

    for (int i = 1; i < n; i++)
    {
        int l = arr[i];
        int m = arr[n - i - 1];

        if (pq2.size() > y)
            pq2.pop();

        if (pq1.size() > x)
            pq1.pop();

        if (pq1.top() > l || pq1.size() == 0)
            temp[i]++;

        if (pq2.top() > m || pq2.size() == 0)
        {
            temp[n - i - 1]++;
            cout << n - i - 1 << endl;
        }

        pq1.push(l);
        pq2.push(m);
    }

    for (int i = 0; i < n; i++)
    {
        // cout << temp[i] << endl;
        if (temp[i] == 2)
        {
            cout << i + 1 << endl;
            return;
        }
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