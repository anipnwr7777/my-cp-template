#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, w, data;
        vector<ll> wt, val;
        cin >> n >> w;
        wt.push_back(0);
        val.push_back(0);
        for (ll i = 1; i <= n; i++)
        {
            cin >> data;
            wt.push_back(data);
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> data;
            val.push_back(data);
        }
        vector<vector<ll>> cache(n + 1, vector<ll>(w + 1, 0)); // declare

        for (ll i = 0; i <= w; i++)
        { //initialize
            cache[0][i] = 0;
        }
        for (ll i = 0; i <= n; i++)
        {
            cache[i][0] = 0;
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= w; j++)
            {
                if (wt[i] <= j)
                {
                    cache[i][j] = max(val[i] + cache[i - 1][j - wt[i]], cache[i - 1][j]);
                }
                else
                {
                    cache[i][j] = cache[i - 1][j];
                }
            }
        }
        cout << cache[n][w] << "\n";
    }
    return 0;
}