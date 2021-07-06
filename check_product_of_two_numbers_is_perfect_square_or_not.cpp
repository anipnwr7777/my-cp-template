#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
//priority_queue <int, vector<int>, greater<int>> minheap
bool isprime[10000001];
int k[10000001];

void seive(int n)
{
     memset(isprime, true, sizeof(isprime));
     isprime[0] = false;
     isprime[1] = false;

     for (int i = 2; i * i < n; i++)
     {
          if (isprime[i] == true)
          {
               for (int j = i; j < n; j = j + i)
               {
                    if (isprime[j] == true)
                    {
                         isprime[j] = false;
                    }
                    if (k[j] % (i * i) == 0)
                    {
                         k[j] = k[j] / (i * i);
                    }
               }
          }
     }
}

void pre()
{
     for (int i = 0; i < 10000001; i++)
     {
          k[i] = i;
     }
     seive(1e7 + 1); // k gets filled
}

void solve()
{
     // traverse k and id 2 k are equal then the
     // the multiplication of their corresponding
     // number will give a perfect square.
     // else not perfect square.
}

signed main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     int t;
     cin >> t;

     pre();

     while (t--)
     {
          solve();
     }

     return 0;
}