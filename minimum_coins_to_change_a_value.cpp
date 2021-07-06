#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> coins(10);
ll cache[160];

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

ll f(ll amount, ll n)
{
    if (amount == 0)
    {
        return 0;
    }
    if (cache[amount] != -1)
    {
        return cache[amount];
    }
    ll mn = INT_MAX;
    for (ll i = 0; i < n; i++)
    {
        if (coins[i] <= amount)
        {
            mn = min(mn, f(amount - coins[i], n));
        }
    }

    return cache[amount] = (1 + mn);
}

int main()
{
    memset(cache, -1, sizeof(cache));
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, amount;
        cin >> n >> amount;
        for (ll i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        cout << f(amount, n);
    }
    return 0;
}