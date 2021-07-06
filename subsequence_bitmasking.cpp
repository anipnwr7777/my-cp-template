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
     string s;
     cin >> s;
     int n = s.size();
     for (int i = 0; i < (1 << n); i++)
     {
          string x = "";
          for (int j = 0; j < n; j++)
          {
               if (i & (1 << j))
               {
                    x = s[n - 1 - j] + x;
               }
          }
          cout << x << "\n";
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