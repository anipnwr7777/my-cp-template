#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cache[11];

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

ll lis(vector<ll> &v, ll i, ll n, ll prev){
    if( i == n+1 ){
        return 0;
    }

    if( v[i]>prev ){
        return max(lis( v , i+1 , n , v[i]) + 1, lis( v , i+1 , n , prev ) );
    }
    else{
        return lis( v , i+1 , n , prev );
    }
}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            memset(cache,-1,sizeof(cache));
            ll n,data; cin>>n;
            vector<ll> v(n);
            for(ll i=0 ; i<n ; i++){
                cin>>v[i];
            }
            ll prev = INT_MIN;
            cout<<lis(v,0,n-1,prev)<<"\n";
        }
    return 0;
}