#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int visited[100000];     // ***** size (number of nodes plus 1) ***** //
vector<int> adj[100000]; // ***** size (number of nodes plus 1) ***** //

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
void dfs(ll v)
{
    visited[v] = 1;

    for (ll child : adj[v])
    {
        if (visited[child] == 0)
            dfs(child);
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
        for (int i = 0; i < nodes; i++)
            adj[i].clear(), visited[i] = 0; //clear for each test case

        makeadj(nodes, edges);
        ll c = 0;
        for (ll i = 0; i < nodes; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i); //***** see for yourself 0 or 1 ******//
                c++;
            }
        }
        cout << c;
        //// code here ////
    }
    return 0;
}