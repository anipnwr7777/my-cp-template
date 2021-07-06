#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> ar(100);

ll binarysearch(ll n, ll key)
{
    ll low = 0;
    ll high = n - 1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (ar[mid] == key)
        {
            return mid + 1;
        }
        if (ar[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, key;
    cin >> n >> key;
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    cout << binarysearch(n, key);
    return 0;
}