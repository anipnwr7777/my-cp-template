#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cache[101];

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

ll fibonacci(ll n){
    if(n == 0 || n == 1) return n;
    if(cache[n] != -1){
        return cache[n];
    }
    return cache[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            memset(cache,-1,sizeof(cache));
            ll n; cin>>n;
            cout<<fibonacci(n)<<"\n";
        }
    return 0;
}