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

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            string x,y;
            cin>>x>>y;
            ll m=x.length();     ll n=y.length();
            vector<vector<ll>> cache(m+1,vector<ll>(n+1,0));
            
            for(ll i =0 ; i<=m ; i++) {
                cache[i][0]=0;
            }
            for(ll i =0 ; i<=n ; i++) {
                cache[0][i]=0;
            }

            for(ll i=1; i<=m ; i++){
                for(ll j=1; j<=n ; j++){
                    if( x[i-1] == y[j-1] ){
                        cache[i][j] = 1 + cache[i-1][j-1];
                    }
                    else{
                        cache[i][j] = max ( cache[i-1][j] , cache[i][j-1] );
                    }
                }
            }
            cout<<cache[m][n]<<"\n";
        }
    return 0;
}