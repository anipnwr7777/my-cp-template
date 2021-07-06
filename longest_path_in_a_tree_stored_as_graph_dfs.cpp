#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int visited[100000];
vector<int> adj[100000];
ll maxnode, maxd;

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

void makeadj(ll edges)
{
    ll v1, v2;
    for (ll i = 0; i < edges; i++)
    {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
}

void dfs(ll v, ll d)
{
    visited[v] = 1;

    if (d > maxd)
    {
        maxd = d;
        maxnode = v;
    }

    for (ll child : adj[v])
    {
        if (visited[child] == 0)
            dfs(child, d + 1);
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
        ll nodes, edges;
        cin >> nodes >> edges;

        for (int i = 0; i < nodes; i++)
            adj[i].clear(), visited[i] = 0;

        makeadj(edges);

        maxd = maxnode = INT_MIN;

        for (ll i = 0; i < nodes; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, 0); //***** see for yourself 0 or 1 ******//
            }
        }

        maxd = INT_MIN;
        memset(visited, 0, sizeof(visited));

        for (ll i = 0; i < nodes; i++)
        {
            if (visited[i] == 0)
            {
                dfs(maxnode, 0); //***** see for yourself 0 or 1 ******//
            }
        }
        cout << maxd << "\n";
    }
    return 0;
}