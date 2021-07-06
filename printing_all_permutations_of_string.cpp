#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

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

void f(string s)
{
}

int main()
{
      ios::sync_with_stdio(0);
      cin.tie(0);
      ll t;
      cin >> t;
      while (t--)
      {
            string s;
            cin >> s;
            f(s);
      }
      return 0;
}