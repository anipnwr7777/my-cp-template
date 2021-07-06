#include <bits/stdc++.h>
using namespace std;

int main()
{
     multiset<int, greater<int>> mt; // atmost
     multiset<int> mt1;              // atleast

     // nahi mila to mt.end() pe hi hoga iterator

     mt.insert(1);
     mt.insert(2);
     mt.insert(8);
     mt.insert(1);
     mt.insert(8);

     for (auto x : mt)
     {
          cout << x << " ";
     }

     return 0;
}
