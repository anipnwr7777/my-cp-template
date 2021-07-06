#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cache[1001][1001];

ll knapsack(vector<ll> &wt, vector<ll> &val, ll n, ll w)
{
    if (n == -1 || w == 0)
        return 0;

    if (cache[n][w] != -1)
    {
        return cache[n][w];
    }

    if (wt[n] <= w)
    {
        return cache[n][w] = max(val[n] + knapsack(wt, val, n, w - wt[n]), knapsack(wt, val, n - 1, w));
    }
    else
    {
        return cache[n][w] = knapsack(wt, val, n - 1, w);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        memset(cache, -1, sizeof(cache));
        vector<ll> wt, val;
        ll n, w, data;
        cin >> n >> w;
        for (ll i = 0; i < n; i++)
        {
            cin >> data;
            wt.push_back(data);
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> data;
            val.push_back(data);
        }
        cout << knapsack(wt, val, n - 1, w) << "\n";
    }
    return 0;
}