
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775807
#define mod 1000000007
//priority_queue <int, vector<int>, greater<int>> minheap

void precomputation()
{
     //no precomputation
}

void solve()
{
     int cur = 1;
     for (int i = 0; i < 100; i++)
     {
          if (cur == 0)
               cout << "A";
          else
               cout << "B";
          cur ^= 1;
     }
}

signed main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     precomputation();

     {
          solve();
     }

     return 0;
}