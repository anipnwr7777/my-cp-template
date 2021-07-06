#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

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
        val.push_back(0); // 0 push kara hai indexing same karne ke liye ( dp matrix se match karne ke liye )
        for (ll i = 01; i <= n; i++)
        { // 0 row and column for initialisation and 1 se n tak for sub-problems
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
        { // 1 to n -> for all sub-problems
            for (ll j = 1; j <= w; j++)
            {
                if (wt[i] <= j)
                {
                    cache[i][j] = max(val[i] + cache[i][j - wt[i]], cache[i - 1][j]);
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