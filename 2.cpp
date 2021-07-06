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
        map<ll, ll> mp;
        ll arr[] = {9, 7, 7, 7, 1, 1, 1, 1, 2, 3, 3, 4, 5, 6};
        for (ll i =0; i < 14; i++)
        {
            mp[arr[i]]++;
        }
        for (auto x : mp)
        {
            cout << x.first << " " << x.second << "\n";
        }
    }

    return 0;
}