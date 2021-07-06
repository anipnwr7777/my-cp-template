#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> adj[100000]; // ***** size (number of nodes plus 1) ***** //
vector<ll> indeg(100, 0);

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
        indeg[v2]++;
    }
}
//****************** ADJACENCY LIST MADE ****************//

// **************  topological IMPLEMENTED  *********************//
void topological(ll nodes)
{
    queue<int> q;
    for (ll i = 0; i < nodes; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << "->"; // print the traversal
        q.pop();
        for (auto child : adj[curr])
        {
            indeg[child]--;
            if (indeg[child] == 0)
            {
                q.push(child);
            }
        }
    }
}
// **************  topological IMPLEMENTED  *********************//

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
            adj[i].clear(); //clear for each test case
        }
        makeadj(nodes, edges);
        topological(nodes);
    }
    return 0;
}