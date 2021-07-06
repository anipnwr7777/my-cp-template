#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int visited[100000];     // ***** size (number of nodes plus 1) ***** //
vector<int> adj[100000]; // ***** size (number of nodes plus 1) ***** //
ll in[100];
ll low[100];
ll timer;
bool onstack[100];

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
    in[v] = low[v] = timer;
    timer++;
    s.push(v);
    onstack[v] = true;

    for (ll child : adj[v])
    {
        if (visited[child] == 1 && onstack[child] == 0)
        {
            continue;
        }
        else if (visited[v] == 1 && onstack[child] == 1)
        {
            low[v] = min(in[child], low[v]);
        }
        else if (visited[child] == 0)
        {
            dfs(child, s);
            low[v] = min(low[v], low[child]);
        }
    }

    if (low[v] == in[v])
    {
        while (1)
        {
            if (s.top() == v)
            {
                cout << v << " ";
                s.pop();
                onstack[v] = 0;
                break;
            }
            cout << s.top() << " ";
            onstack[s.top()] = 0;
            s.pop();
        }
        cout << "\n";
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
        timer = 0;
        memset(in, -1, sizeof(in));
        memset(low, -1, sizeof(low));
        for (int i = 1; i <= nodes; i++)
            adj[i].clear(), visited[i] = 0, onstack[i] = 0; //clear for each test case
        stack<ll> s;
        makeadj(nodes, edges);
        dfs(1, s);
    }
    return 0;
}