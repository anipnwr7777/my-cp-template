#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int visited[100000], dis[100000]; // ***** size (number of nodes plus 1) ***** //
vector<int> adj[100000];          // ***** size (number of nodes plus 1) ***** //

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

// **************  BFS IMPLEMENTED  *********************//
void bfs(ll v)
{
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << "->"; // print the traversal
        q.pop();
        for (auto child : adj[curr])
        {
            if (visited[child] == 0)
            {
                visited[child] = 1;
                q.push(child);
                dis[child] = dis[curr] + 1;
            }
        }
    }
}
// **************  BFS IMPLEMENTED  *********************//

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
            adj[i].clear(), visited[i] = 0; //clear for each test case
        }
        makeadj(nodes, edges);
        bfs(1); //***** see for yourself 0 or 1 (starting node) ******//
        //cout<<dis[4]<<endl;
        //// code here ////
    }
    return 0;
}