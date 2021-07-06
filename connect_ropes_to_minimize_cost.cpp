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
        ll n;
        cin >> n;
        vector<ll> ar(n);
        for (auto &x : ar)
        {
            cin >> x;
        }
        priority_queue<ll, vector<ll>, greater<ll>> p;

        for (auto x : ar)
        {
            p.push(x);
        }
        ll ans = 0;
        while (!p.empty())
        {
            ll a = p.top();
            p.pop();
            ll b = p.top();
            p.pop();
            ans = ans + a + b;
            if (!p.empty())
            {
                p.push(a + b);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}