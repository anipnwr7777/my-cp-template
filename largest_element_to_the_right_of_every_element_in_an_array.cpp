// ***************** O(n) ***************

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<ll> monostack(ll n, ll arr[])
{
    stack<ll> s;
    vector<ll> ans(n);

    for (ll i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll arr[n];
    for (auto &x : arr)
    {
        cin >> x;
    }

    vector<ll> ans = monostack(n, arr);
    vector<ll> maxele(n);
    ll max = INT_MIN;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (max < ans[i])
        {
            max = ans[i];
        }
        maxele[i] = max;
    }
    for (auto x : maxele)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}