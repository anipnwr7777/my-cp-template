#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775807
#define mod 1000000007
//priority_queue <int, vector<int>, greater<int>> minheap

vector<int> monostack(int n, int arr[])
{
     stack<int> s;
     vector<int> ans(n);

     for (int i = 2 * n - 1; i >= 0; i--)
     {
          while (!s.empty() && s.top() <= arr[i % n]) // less than laga hua hai to I want first element that is  greater than or equal to this element
          {
               s.pop();
          }
          ans[i % n] = s.empty() ? -1 : s.top();
          s.push(arr[i % n]);
     }
     return ans;
}

int main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);

     int n;
     cin >> n;
     int arr[n];
     for (auto &x : arr)
     {
          cin >> x;
     }

     vector<int> ans = monostack(n, arr);
     for (auto x : ans)
     {
          cout << x << " ";
     }
     cout << "\n";
     return 0;
}