#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int visited[100000];     // ***** size (number of nodes plus 1) ***** //
vector<int> adj[100000]; // ***** size (number of nodes plus 1) ***** //
ll in[10000];
ll low[10000];
ll timer = 0;

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

//****************** ADJACENCY LIST MADE ****************//
void makeadj(ll nodes, ll edges)
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
void dfs(ll v, ll par)
{
    visited[v] = 1;
    in[v] = low[v] = timer;
    timer++;

    for (ll child : adj[v])
    {
        if (visited[child] == 1 && child != par)
        {
            low[v] = min(low[v], in[child]);
        }

        if (visited[child] == 0)
        {
            dfs(child, v);

            if (low[child] > in[v])
            {
                cout << v << "-" << child << " bridge\n";
            }

            low[v] = min(low[v], low[child]);
        }
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
        ll nodes, edges;
        cin >> nodes >> edges;
        memset(in, 0, sizeof(in));
        memset(low, 0, sizeof(low));
        for (int i = 1; i <= nodes; i++)
        {
            adj[i].clear(), visited[i] = 0; //clear for each test case
        }

        makeadj(nodes, edges);
        timer = 0;
        dfs(1, 0);
    }
    return 0;
}