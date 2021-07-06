#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll adj[101][101];

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

void solve(ll nodes)
{
    for (ll k = 0; k < nodes; k++)
    {
        for (ll i = 0; i < nodes; i++)
        {
            for (ll j = 0; j < nodes; j++)
            {
                if (adj[i][k] == INT_MAX || adj[k][j] == INT_MAX)
                {
                    continue;
                }
                else if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
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
        ll nodes, edges, a, b, w;
        cin >> nodes >> edges;
        for (ll i = 0; i < nodes; i++)
        {
            for (ll j = 0; j < nodes; j++)
            {
                if (i == j)
                {
                    adj[i][j] = 0;
                }
                else
                {
                    adj[i][j] = INT_MAX;
                }
            }
        }

        for (ll i = 0; i < edges; i++)
        {
            cin >> a >> b >> w;
            adj[a][b] = w;
        }
        solve(nodes);
        for (ll i = 0; i < nodes; i++)
        {
            for (ll j = 0; j < nodes; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}