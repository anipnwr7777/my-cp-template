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

int cal(int a, int z, int m)
{
     int r = m % a;
     int q = m / a;
     return a * (z % q) - r * (z / q);
}

void solve()
{
     int a = 6, z = 100;
     cout << cal(a, z, 100);
}

signed main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     precomputation();

     {
          solve();
     }

     return 0;
}