#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
//priority_queue <int, vector<int>, greater<int>> minheap

int gcd(int a, int b)
{
     if (b == 0)
          return a;
     return gcd(b, a % b);
}

int lcm(int a, int b)
{
     return a * b / gcd(a, b);
}

void solve()
{
     cout << gcd(123456700, 122222133);
}

signed main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);

     {
          solve();
     }
     return 0;
}