#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int visited[100];     // ***** size (number of nodes plus 1) ***** //
vector<int> adj[100]; // ***** size (number of nodes plus 1) ***** //
vector<ll> rev[100];

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
    }
}
//****************** ADJACENCY LIST MADE ****************//

// **************  DFS IMPLEMENTED  *********************//
void dfs(ll v, stack<ll> &s)
{
    visited[v] = 1;
    for (ll child : adj[v])
    {
        if (visited[child] == 0)
            dfs(child, s);
    }
    s.push(v);
}
// **************  DFS IMPLEMENTED  *********************//

void dfs1(ll v)
{
    visited[v] = 1;
    cout << v << " ";
    for (ll child : rev[v])
    {
        if (visited[child] == 0)
            dfs1(child);
    }
}

void reverse(ll nodes)
{
    for (ll i = 0; i < nodes; i++)
    {
        for (auto child : adj[i])
        {
            rev[child].push_back(i);
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
        ll nodes, edges;
        cin >> nodes >> edges;

        for (int i = 0; i < nodes; i++)
        {
            adj[i].clear(), visited[i] = 0, rev[i].clear(); //clear for each test case
        }

        makeadj(nodes, edges);
        stack<ll> s;

        for (ll i = 0; i < nodes; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, s); //***** see for yourself 0 or 1 ******//
            }
        }

        reverse(nodes);
        memset(visited, 0, sizeof(visited));

        while (!s.empty())
        {
            if (visited[s.top()] == 1)
            {
                s.pop();
            }
            else
            {
                dfs1(s.top());
                cout << "\n";
            }
        }
    }
    return 0;
}