#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
//priority_queue <int, vector<int>, greater<int>> minheap

vector<vector<int>> dp(100, vector<int>(100, 0));

int lcs(string a, string b, int la, int lb)
{
     for (int i = 0; i < la; i++)
     {
          for (int j = 0; j < lb; j++)
          {
               if (i == 0 || j == 0)
               {
                    dp[i][j] = 0;
               }
          }
     }
     for (int i = 1; i <= la; i++)
     {
          for (int j = 1; j <= lb; j++)
          {
               if (a[i - 1] == b[j - 1])
               {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
               }
               else
               {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
               }
          }
     }
     return dp[la][lb];
}

void printlcs(string a, string b, int la, int lb)
{
     vector<char> v;
     int i = la, j = lb;
     while (i >= 1 && j >= 1)
     {
          if (a[i - 1] == b[j - 1])
          {
               v.push_back(a[i - 1]);
               i--;
               j--;
          }
          else if (dp[i - 1][j] > dp[i][j - 1])
          {
               i--;
          }
          else
          {
               j--;
          }
     }
     for (int i = v.size(); i >= 0; i--)
     {
          cout << v[i] << " ";
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
          string a, b;
          cin >> a >> b;
          int la = a.size();
          int lb = b.size();

          lcs(a, b, la, lb);
          printlcs(a, b, la, lb);
     }
     return 0;
}