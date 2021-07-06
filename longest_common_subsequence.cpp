#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cache[101][101]; // cache[m+1][n+1]

ll lcs(string x, string y, ll m, ll n)
{
    if(m == -1 || n == -1)
        return 0;

    if(cache[m][n] != -1)
        return cache[m][n];

    if(x[m] == y[n])
        return cache[m][n] = 1 + lcs(x, y, m - 1, n - 1);

    else
        return cache[m][n] = max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        memset(cache, -1, sizeof(cache));
        string x, y;
        cin >> x >> y;
        ll m = x.length();
        ll n = y.length();
        cout << lcs(x, y, m - 1, n - 1) << "\n";
    }
    return 0;
}