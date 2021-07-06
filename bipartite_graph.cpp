#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int visited[100000];     // ***** size (number of nodes plus 1) ***** //
vector<int> adj[100000]; // ***** size (number of nodes plus 1) ***** //
vector<ll> colour(1000, 0);

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
bool dfs(ll v, ll c)
{
    visited[v] = 1;
    colour[v] = c;

    for (ll child : adj[v])
    {
        if (visited[child] == 0)
        {
            if (dfs(child, !c) == false)
            {
                return false;
            }
        }
        else
        {
            if (colour[child] == colour[v])
            {
                return false;
            }
        }
    }
    return true;
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
            adj[i].clear(), visited[i] = 0, colour[i] = 0; //clear for each test case

        makeadj(edges);

        cout << dfs(0, 0) << "\n"; //***** see for yourself 0 or 1 ******//

        //// code here ////
    }
    return 0;
}