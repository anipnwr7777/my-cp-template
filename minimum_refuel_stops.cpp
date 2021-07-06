#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll minRefuelStops(ll n, ll target, ll startfuel, vector<vector<ll>> &stations)
{

    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = startfuel;
    for (ll i = 0; i < n; i++)
    {

        for (ll j = i; j >= 0; j--)
        {
            if (dp[j] >= stations[i][0])
            {
                dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
    }

    for (ll i = 0; i <= n; i++)
    {
        if (dp[i] >= target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, target, startfuel;
        cin >> n >> target >> startfuel;
        vector<vector<ll>> stations(n, vector<ll>(2));
        for (ll i = 0; i < n; i++)
        {
            cin >> stations[i][0] >> stations[i][1];
        }
        cout << minRefuelStops(n, target, startfuel, stations) << "\n";
    }
    return 0;
}