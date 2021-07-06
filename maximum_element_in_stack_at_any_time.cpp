#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
stack<ll> s;
stack<ll> ma;

void pushinstack(ll n)
{
    s.push(n);
    if (ma.empty())
    {
        ma.push(n);
    }
    else if (ma.top() < n)
    {
        ma.push(n);
    }
}

void popfromstack()
{
    if (ma.top() == s.top())
    {
        ma.pop();
    }
    s.pop();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        pushinstack(2);
        pushinstack(6);
        pushinstack(7);
        pushinstack(2);
        pushinstack(8);
        pushinstack(1);
        cout << ma.top() << "\n";
        popfromstack();
        cout << ma.top() << "\n";
        popfromstack();
        cout << ma.top() << "\n";
        popfromstack();
        cout << ma.top() << "\n";
        popfromstack();
        cout << ma.top() << "\n";
    }
    return 0;
}