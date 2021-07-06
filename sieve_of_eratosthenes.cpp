#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
//priority_queue <int, vector<int>, greater<int>> minheap

bool isprime[1000001]; // *****  fill isprime[n+1]   *******
int primefactors[1000001];


        
// worst case - O(n*n)
void seive(int n)
{
     memset(isprime, true, sizeof(isprime));
     isprime[0] = false;
     isprime[1] = false;

     for (int i = 2; i * i < n; i++)
     {
          if (isprime[i] == true)
          {
               for (int j = i * i; j <= n; j = j + i)
               {
                    if (isprime[j] == true)
                    {
                         isprime[j] = false;
                    }
               }
          }
     }
}



//******* O(n) time and O(n) space
void primefactorization(int n)
{
     memset(primefactors, -1, sizeof(primefactors));

     for (int i = 2; i < n; i++)
     {
          if (primefactors[i] == -1)
          {
               for (int j = i; j <= n; j = j + i)
               {
                    if (primefactors[j] == -1)
                    {
                         primefactors[j] = i;
                    }
               }
          }
     }
}


// *** O(n)
void findprimefactors(int n)
{
     while (n != 1)
     {
          cout << primefactors[n] << " ";
          n = n / primefactors[n];
     }
}


//***** O(sqrt(n))
bool isprimealone(int n)
{
     if (n == 1)
     {
          return false;
     }
     for (int i = 2; i * i <= n; i++)
     {
          if (n % i == 0)
          {
               return false;
          }
     }
     return true;
}


// *** O(sqrt(n))
vector<pair<int,int>> primefactorizationfast(int n)
{
     vector<pair<int, int>> factors;
     for (int i = 2; i * i <= n ; i++)
     {
          if (n % i == 0) {
               int cnt = 0;
               while (n % i == 0)
               {
                    n /= i;
                    cnt++;
               }
               factors.push_back({cnt, i});
          }
     }
     if (n != 1) factors.push_back({1, n});
     return factors;
}        

void printallfactors(int n)
{
     for(int i=2 ; i*i<=n ; i++)
     {
          if(n%i == 0)
          {
               cout<<i<<" "<<n/i<<" ";
          }
     }
     cout<<n<<endl;
}


signed main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     int t;
     //seive(1e6 + 1);
     //primefactorization(1e6 + 1);
     cin >> t;
     while (t--)
     {
          int n;
          cin >> n;
     }
     return 0;
}