#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
//priority_queue <int, vector<int>, greater<int>> minheap

void precomputation()
{
     //no precomputation
}

void solve()
{
     int n;
     cin >> n;
     for (int i = 31; i >= 0; i--)
     {
          if (n & (1 << i))
          {
               cout << 1;
          }
          else
               cout << 0;
     }
}

signed main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     precomputation();

     int t;
     cin >> t;
     while (t--)
     {
          solve();
     }

     return 0;
}