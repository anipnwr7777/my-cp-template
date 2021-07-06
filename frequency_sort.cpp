#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool comp(pair<ll, ll> x, pair<ll, ll> y)
{
	if (x.first < y.first)
		return false;
	else
		return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<ll> arr(n);
		map<ll, ll> mp;
		vector<pair<ll, ll>> ans;

		for (auto &x : arr)
		{
			cin >> x;
		}

		for (auto x : arr)
		{
			mp[x]++;
		}
		for (auto x : mp)
		{
			ans.push_back({x.second, x.first});
		}
		sort(ans.begin(), ans.end(), comp);

		for (auto x : ans)
		{
			while (x.first--)
			{
				cout << x.second << " ";
			}
		}
	}

	return 0;
}