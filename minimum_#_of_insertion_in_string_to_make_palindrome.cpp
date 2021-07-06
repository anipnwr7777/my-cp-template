#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cache[101][101]; // cache[m+1][n+1]

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

ll lcs(string x, string y, ll m, ll n)
{
    if (m == -1 || n == -1)
    {
        return 0;
    }
    if (cache[m][n] != -1)
    {
        return cache[m][n];
    }
    if (x[m] == y[n])
    {
        return cache[m][n] = 1 + lcs(x, y, m - 1, n - 1);
    }
    else
    {
        return cache[m][n] = max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
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
        memset(cache, -1, sizeof(cache));
        string x;
        cin >> x;
        ll m = x.length();
        ll n = m;
        string y = x;
        reverse(x.begin(), x.end());
        ll z = lcs(x, y, m - 1, n - 1);
        ll ans = m - z;
        cout << ans << "\n";
    }
    return 0;
}