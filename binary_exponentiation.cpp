#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

ll power(ll a, ll b)
{
    if(b==1)
    {
        return a;
    }
    ll res=power(a,b/2);
    res=res*res;
    if(b%2!=0)
    {
        res=res*a;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            cout<<power(4,3);
        }
    return 0;
}