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
        while (!s.empty() && s.top() <= arr[i]) // less than laga hua hai to I want first element that is  greater than or equal to this element
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
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}