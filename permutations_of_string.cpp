#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
//priority_queue <int, vector<int>, greater<int>> minheap
set<string> ansset;

void precomputation()
{
     //no precomputation
}

void permutations(string ques, string asf)
{

     if (ques.size() == 0)
     {
          ansset.insert(asf);
          return;
     }
     for (int i = 0; i < ques.size(); i++)
     {
          char x = ques[i];
          string left = ques.substr(0, i);
          string right = ques.substr(i + 1);
          string rques = left + right;
          permutations(rques, asf + x);
     }
}

void solve()
{
     string ques;
     cin >> ques;
     permutations(ques, "");
     cout << ansset.size() << "\n";
     for (auto x : ansset)
     {
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