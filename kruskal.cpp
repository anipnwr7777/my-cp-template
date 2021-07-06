#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll parent[11]; // initialize with -1

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

ll find(ll n)
{
    if (parent[n] < 0)
    {
        return n;
    }
    else
    {
        ll x = find(parent[n]);
        parent[n] = x;
        return x;
    }
}

void Union(ll a, ll b)
{
    parent[a] += parent[b];
    parent[b] = a;
}

struct edge
{
    ll a;
    ll b;
    ll w;
};
edge arr[101];

bool comp(edge x, edge y)
{
    if (x.w < y.w)
    {
        return true;
    }
    else
    {
        return false;
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
        memset(parent, -1, sizeof(parent)); // important initialization
        ll n, m;                            // n->number of nodes,  m->number of edges
        cin >> n >> m;
        for (ll i = 0; i < m; i++)
        {
            cin >> arr[i].a >> arr[i].b >> arr[i].w;
        }

        sort(arr, arr + m, comp);
        ll sum = 0;

        for (ll i = 0; i < m; i++)
        {
            ll p1 = find(arr[i].a);
            ll p2 = find(arr[i].b);
            if (p1 != p2)
            {
                Union(p1, p2);
                sum += arr[i].w;
            }
        }

        cout << sum << "\n";
    }
    return 0;
}