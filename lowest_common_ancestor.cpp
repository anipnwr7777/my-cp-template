#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int visited[100000];
vector<int> adj[100000];
vector<vector<ll>> lca(100, vector<ll>(100, -1));
ll dis1, dis2;

void binarylifting2(ll nodes, ll maxnode, ll d, ll v1, ll v2)
{
    for (ll i = maxnode; i >= 0; i--)
    {
        if (lca[v1][i] != lca[v2][i] && lca[v1][i] != -1)
        {
            v1 = lca[v1][i];
            v2 = lca[v2][i];
        }
    }
}

ll binarylifting(ll nodes, ll maxnode, ll d, ll v2)
{
    ll inm;
    while (d > 0)
    {
        ll maxj = log2(d);
        d = d - pow(2, maxj);
        inm = lca[v2][maxj];
        v2 = inm;
    }
    return v2;
}

void findlca(ll nodes, ll maxnode)
{
    for (ll i = 1; i <= maxnode; i++)
    {
        for (ll j = 1; j <= nodes; j++)
        {
            if (lca[j][i - 1] != -1)
            {
                ll inm = lca[j][i - 1];
                lca[j][i] = lca[inm][i - 1];
            }
        }
    }
}

//****************** ADJACENCY LIST MADE ****************//
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
//****************** ADJACENCY LIST MADE ****************//

// **************  DFS IMPLEMENTED  *********************//
void dfs(ll v, ll par, ll dis, ll v1, ll v2)
{
    visited[v] = 1;
    lca[v][0] = par;
    if (v == v1)
    {
        dis1 = dis;
    }
    if (v == v2)
    {
        dis2 = dis;
    }
    for (ll child : adj[v])
    {
        if (visited[child] == 0)
            dfs(child, v, dis + 1, v1, v2);
    }
}
// **************  DFS IMPLEMENTED  *********************//

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll nodes, edges, v1, v2;
        cin >> nodes >> edges >> v1 >> v2;
        for (int i = 1; i <= nodes; i++)
            adj[i].clear(), visited[i] = 0;

        ll maxnode = log2(nodes);

        for (ll i = 1; i <= nodes; i++)
        {
            for (ll j = 0; j <= maxnode; j++)
            {
                lca[i][j] = -1;
            }
        }

        dis1 = 0;
        dis2 = 0;

        makeadj(edges);
        for (ll i = 1; i <= nodes; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, -1, 0, v1, v2);
            }
        }

        ll d = abs(dis1 - dis2);

        findlca(nodes, maxnode);

        if (v1 > v2)
        {
            ll temp = v1;
            v1 = v2;
            v2 = temp;
        }

        v2 = binarylifting(nodes, maxnode, d, v2);

        binarylifting2(nodes, maxnode, d, v1, v2);

        if (v1 == v2)
        {
            cout << v1 << '\n';
        }
        else
        {
            cout << lca[v2][0] << "\n";
        }
    }
    return 0;
}