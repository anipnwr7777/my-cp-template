#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<ll> rmonostack(ll n, vector<ll> arr)
{
    stack<pair<ll, ll>> s;
    vector<ll> ans(n);

    for (ll i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top().second >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.empty() ? n : s.top().first;
        s.push({i, arr[i]});
    }
    return ans;
}

vector<ll> lmonostack(ll n, vector<ll> arr)
{
    stack<pair<ll, ll>> s;
    vector<ll> ans(n);

    for (ll i = 0; i < n; i++)
    {
        while (!s.empty() && s.top().second >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top().first;
        s.push({i, arr[i]});
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr)
    {
        cin >> x;
    }

    vector<ll> right = rmonostack(n, arr);
    vector<ll> left = lmonostack(n, arr);

    vector<ll> sum(n, 0);
    sum[0] = arr[0];
    for (ll i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    vector<ll> dp(n);
    for (ll i = 0; i < n; i++)
    {
        if (left[i] == -1)
        {
            dp[i] = sum[right[i] - 1];
        }
        else
        {
            dp[i] = sum[right[i] - 1] - sum[left[i]];
        }
        dp[i] *= arr[i];
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}