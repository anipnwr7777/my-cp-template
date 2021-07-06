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
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for (auto &x : arr)
        {
            cin >> x;
        }
        unordered_map<ll, ll> mp;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for (auto x : arr)
        {
            mp[x]++;
        }
        ll count = 0;
        for (auto x : mp)
        {
            count++;
            pq.push({x.second, x.first});
            if (count > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            cout << pq.top().second << " ";
            pq.pop();
        }
    }
    return 0;
}