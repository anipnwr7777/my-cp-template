#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
//priority_queue <int, vector<int>, greater<int>> minheap

int wt[100];
int cache[100][100];

bool subsetsum(int n, int sum)
{

     if (sum == 0)
     {
          return true;
     }

     if (n < 0)
     {
          return false;
     }

     if (cache[n][sum] != -1)
     {
          return cache[n][sum];
     }

     if (wt[n] <= sum)
     {
          return cache[n][sum] = subsetsum(n - 1, sum - wt[n]) || subsetsum(n - 1, sum);
     }
     else
     {
          return cache[n][sum] = subsetsum(n - 1, sum);
     }
}

signed main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     int t;
     cin >> t;
     while (t--)
     {
          int n, range = 0;
          cin >> n;
          memset(cache, -1, sizeof(cache));

          for (int i = 0; i < n; i++)
          {
               cin >> wt[i];
               range += wt[i];
          }

          int ans = 0;
          for (int i = range / 2; i >= 0; i--)
          {
               if (subsetsum(n - 1, i) == 1)
               {
                    ans = (range - (2 * i));
                    break;
               }
          }
          cout << ans << "\n";
     }
     return 0;
}