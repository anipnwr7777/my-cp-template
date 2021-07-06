#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool visited[101];
ll dist[101];
ll adj[101][101];

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

void dijkstra(ll nodes)
{
    ll times = nodes;
    while (times--)
    { // select minimum dist vertex
        ll mn = INT_MAX, current;
        for (ll i = 0; i < nodes; i++)
        {
            if (dist[i] < mn && visited[i] == 0)
            {
                mn = dist[i];
                current = i;
            }
        }

        visited[current] = 1; // mark visited

        for (ll i = 0; i < nodes; i++)
        { // relax edges
            if (adj[current][i] != 0 && visited[i] != 1 && dist[i] > adj[current][i] + dist[current])
            {
                dist[i] = adj[current][i] + dist[current];
            }
        }
    }
}

//***************************************************************************************************************
//******************************** 0 se shuru hai nodes is question me ******************************************
//***************************************************************************************************************

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll nodes, edges, a, b, wt, start;
        cin >> nodes >> edges >> start;

        for (ll i = 0; i < nodes; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[start] = 0; // distance of start vertex from itself is 0

        for (ll i = 0; i < edges; i++)
        {
            cin >> a >> b >> wt;
            adj[a][b] = wt; // this will be done only if graph is non - directed
            adj[b][a] = wt; // if directed then take only one out of them
        }

        dijkstra(nodes);
        for (ll i = 0; i < nodes; i++)
        {
            cout << dist[i] << " ";
        }
    }
    return 0;
}