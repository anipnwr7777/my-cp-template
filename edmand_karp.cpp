#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> adj[100000]; // ***** size (number of nodes plus 1) ***** //
vector<vector<ll>> mat(100, vector<ll>(100, 0));

//****************** ADJACENCY LIST MADE ****************//
void makeadj(ll nodes, ll edges)
{
    ll v1, v2, c;
    for (ll i = 0; i < edges; i++)
    {
        cin >> v1 >> v2 >> c;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        mat[v1][v2] = c;
    }
}
//****************** ADJACENCY LIST MADE ****************//

// **************  BFS IMPLEMENTED  *********************//
ll bfs(ll v, vector<ll> &parent, ll sink, ll source)
{
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<ll, ll>> q;
    q.push({v, INT_MAX});
    ll flow = 0;

    while (!q.empty())
    {
        int curr = q.front().first;
        flow = q.front().second;

        q.pop();
        for (auto child : adj[curr])
        {
            if (parent[child] = -1 && mat[curr][child] > 0)
            {
                parent[child] = curr;

                ll newflow = min(flow, mat[curr][child]);
                if (child == sink)
                {
                    return newflow;
                }
                q.push({child, newflow});
            }
        }
    }
    return 0;
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
        ll nodes, edges, source, sink;
        cin >> nodes >> edges >> source >> sink;
        for (int i = 0; i < nodes; i++)
        {
            adj[i].clear();
        }
        makeadj(nodes, edges);

        vector<ll> parent(100);
        ll netflow = 0;
        ll ans;

        while (ans = bfs(0, parent, sink, source))
        {
            netflow += ans;
            ll cur = sink;
            while (cur != source)
            {
                ll prev = parent[cur];
                mat[prev][cur] -= ans;
                mat[cur][prev] += ans;
                cur = prev;
            }
        }
        cout << netflow << "\n";
    }
    return 0;
}