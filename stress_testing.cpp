#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775807
#define mod 1000000007
//priority_queue <int, vector<int>, greater<int>> minheap
char pool[] = "01?";

void precomputation()
{
     //no precomputation
}

string cf(int a, int b, string s)
{
}

string my(int a, int b, string s)
{
}

void solve()
{
     srand(time(0));
     // // int n = rand() % 1000;
     // // cout << n;

     // // cout << pool[rand() % 3];

     // //generate values in a range
     // int low = 25, high = 35;
     // cout << rand() % (high - low + 1) + low;
     while (true)
     {
          int size = rand() % 10;
          string s = "";
          for (int i = 0; i < size; i++)
          {
               s += pool[rand() % 3];
          }
          int zero = 0, one = 0;
          for (auto x : s)
          {
               if (x == '0')
                    zero++;
               else if (x == '1')
                    one++;
          }

          string mystr = my(zero, one, s);
          string cfstr = cf(zero, one, s);

          if (mystr != cfstr)
          {
               cout << mystr << " " << cfstr << "\n";
               break;
          }
     }
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