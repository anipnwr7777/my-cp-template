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
        ll n, k, ele;
        cin >> n >> k >> ele;
        vector<ll> arr(n);
        for (auto &x : arr)
        {
            cin >> x;
        }
        vector<ll> diff(n);
        for (ll i = 0; i < n; i++)
        {
            diff[i] = abs(arr[i] - ele);
        }
        priority_queue<pair<ll, ll>> pq;
        for (ll i = 0; i < n; i++)
        {
            pq.push({diff[i], arr[i]});
            if (i >= k)
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