#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll ans;
ll cache[10][10];

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

ll substring(string s1, ll l1, string s2, ll l2)
{
    if (l1 == -1 || l2 == -1)
    {
        return 0;
    }

    if (cache[l1][l2] != -1)
    {
        return cache[l1][l2];
    }

    substring(s1, l1 - 1, s2, l2);
    substring(s1, l1, s2, l2 - 1);

    if (s1[l1] == s2[l2])
    {
        cache[l1][l2] = substring(s1, l1 - 1, s2, l2 - 1) + 1;
        ans = max(ans, cache[l1][l2]);
        return cache[l1][l2];
    }
    else
    {
        return cache[l1][l2] = 0;
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
        ans = 0;

        string s1, s2;
        cin >> s1 >> s2;
        ll l1 = s1.size(), l2 = s2.size();
        substring(s1, l1 - 1, s2, l2 - 1);
        cout << ans << "\n";
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef long double ld;
// ll ans;
// ll cache[10][10];

// ll substring(string s1, ll l1, string s2, ll l2, ll i, ll j)
// {
//     if (i == l1 || j == l2)
//     {
//         return 0;
//     }

//     substring(s1, l1, s2, l2, i + 1, j);
//     substring(s1, l1, s2, l2, i, j + 1);

//     if (s1[i] == s2[j])
//     {
//         ll x = 1 + substring(s1, l1, s2, l2, i + 1, j + 1);
//         ans = max(ans, x);
//         return x;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         memset(cache, -1, sizeof(cache));
//         ans = 0;

//         string s1, s2;
//         cin >> s1 >> s2;
//         ll l1 = s1.size(), l2 = s2.size();
//         substring(s1, l1, s2, l2, 0, 0);
//         cout << ans << "\n";
//     }
//     return 0;
// }