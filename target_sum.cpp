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
        ll sumarr = 0;
        for (ll i = 0; i < n; i++)
        {
            sumarr += wt[i];
        }
        ll diff = (sumarr + sum) / 2;
        if ((sumarr + sum) % 2 != 0)
        {
            cout << "0"
                 << "\n";
        }

        else if (n == 1)
        {
            if (wt[0] == sum || wt[0] == (-1) * sum)
            {
                cout << "1"
                     << "\n";
            }
            else
            {
                cout << "0"
                     << "\n";
            }
        }
        else
        {
            cout << subsetsum(n - 1, diff) << "\n";
        }
    }
    return 0;
}