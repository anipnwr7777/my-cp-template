#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cache[10][10];
vector<ll> wt(10);

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

ll subsetsum(ll n, ll sum)
{

    if (n == -1)
    {
        if (sum == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return subsetsum(n - 1, sum - wt[n]) + subsetsum(n - 1, sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        memset(cache, -1, sizeof(cache));
        ll n, sum;
        cin >> n >> sum;

        for (ll i = 0; i < n; i++)
        {
            cin >> wt[i];
        }

        cout << subsetsum(n - 1, sum) << "\n";
    }
    return 0;
}