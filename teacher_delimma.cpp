#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll parent[11];

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

ll find(ll n){
    if(parent[n] < 0){
        return n;
    }
    else{
        ll x = find(parent[n]);
        parent[n] = x;
        return x;
    }
}

void Union(ll a, ll b){
    parent[a] += parent[b];
    parent[b] = a;
}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            ll students,bonds;
            cin>>students>>bonds;
            memset(parent,-1,sizeof(parent));

            ll a,b;
            for(ll i=0; i<bonds ; i++){
                cin>>a>>b;
                a = find(a);
                b = find(b);
                if( a!=b ){
                    Union(a,b);
                }
            }
            ll ans=1;
            for(ll i=0 ; i<students ; i++){
                if(parent[i]<0){
                    ans = ans*abs(parent[i]);
                }
            }
            cout<<ans<<"\n";
        }
    return 0;
}