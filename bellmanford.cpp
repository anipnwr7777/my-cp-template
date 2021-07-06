#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll adj[101][101];
ll dist[101];

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

struct edge
{
    ll a, b, w;
};
edge arr[101];

void bellmanford(ll nodes, ll edges)
{
    for (ll j = 0; j < edges - 1; j++) // edges-1 times
    {
        for (ll i = 0; i < edges; i++) // relax all of the edges
        {
            if (dist[arr[i].a] + arr[i].w < dist[arr[i].b])
            {
                dist[arr[i].b] = dist[arr[i].a] + arr[i].w;
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
        ll nodes, edges, start;
        cin >> nodes >> edges >> start;

        for (ll i = 0; i < nodes; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[start] = 0; // distance of start vertex from itself is 0

        for (ll i = 0; i < edges; i++)
        {
            cin >> arr[i].a >> arr[i].b >> arr[i].w;
        }
        bellmanford(nodes, edges);

        for (ll i = 0; i < nodes; i++)
        {
            cout << dist[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}