#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll n, k;
        cin >> n >> k;
        ll ar[n];
        for (auto &x : ar)
        {
            cin >> x;
        }

        for (ll i = 0; i < n; i++)
        {
            pq.push(ar[i]);
            if (i >= k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    }
    return 0;
}