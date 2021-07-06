#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll wt[100];
ll cache[100][100];

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
    //******** audio ************
    if (sum == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }

    if (cache[n][sum] != -1)
    {
        return cache[n][sum];
    }

    if (wt[n] <= sum)
    {
        return cache[n][sum] = subsetsum(n, sum - wt[n]) + subsetsum(n - 1, sum);
    }
    else
    {
        return cache[n][sum] = subsetsum(n - 1, sum);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, sum;
        cin >> n >> sum;

        memset(cache, -1, sizeof(cache));

        for (ll i = 0; i < n; i++)
        {
            cin >> wt[i];
        }

        cout << subsetsum(n - 1, sum);
    }
    return 0;
}