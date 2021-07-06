#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll parent[101];
bool visited[101];
ll weight[101];
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

//***************************************************************************************************************
//******************************** 0 se shuru hai nodes is question me ******************************************
//***************************************************************************************************************

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll nodes, edges, a, b, wt;
        cin >> nodes >> edges;
        parent[0] = -1;
        for (ll i = 0; i < nodes; i++)
        {
            weight[i] = INT_MAX;
        }
        weight[0] = 0;

        for (ll i = 0; i < edges; i++)
        {
            cin >> a >> b >> wt;
            adj[a][b] = wt;
            adj[b][a] = wt;
        }

        ll sum = 0;
        ll times = nodes;

        while (times--)
        { // select minimum weight vertex
            ll mn = INT_MAX, current;
            for (ll i = 0; i < nodes; i++)
            {
                if (weight[i] < mn && visited[i] == 0)
                {
                    mn = weight[i];
                    current = i;
                }
            }

            visited[current] = 1; // mark visited

            sum += weight[current]; // update sum

            for (ll i = 0; i < nodes; i++)
            { // relax edges and mark parent
                if (adj[current][i] != 0 && visited[i] != 1 && weight[i] > adj[current][i])
                {
                    weight[i] = adj[current][i];
                    parent[i] = current;
                }
            }
        }
        cout << sum << "\n";
    }
    return 0;
}