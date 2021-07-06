#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
//priority_queue <int, vector<int>, greater<int>> minheap

int kadane(vector<int> &v, int n)
{
     int csum = v[0];
     int osum = v[0];

     for (int i = 1; i < n; i++)
     {
          if (csum >= 0)
          {
               csum += v[i];
          }
          else
          {
               csum = v[i];
          }
          if (csum > osum)
          {
               osum = csum;
          }
     }
     return osum;
}

signed main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     int t;
     cin >> t;
     while (t--)
     {
          int n;
          cin >> n;
          vector<int> v(n);
          for (int i = 0; i < n; i++)
          {
               cin >> v[i];
          }
          cout << kadane(v, n) << "\n";
     }
     return 0;
}