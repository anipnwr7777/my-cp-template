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
     for (int i = 2; i < 1000; i++)
     {
          if ((i & (i - 1)) == 0)
               cout << i << "\n";
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