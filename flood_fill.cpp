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

void floodfill(vector<vector<ll>> &v, ll x, ll y, ll old, ll newc, ll m , ll n){
    if(x<0 || x>n-1 || y<0 || y>m-1) return;
    if(v[x][y] != old) return;
    v[x][y] = newc;
    
    floodfill(v,x+1,y,old,newc,m,n);
    floodfill(v,x-1,y,old,newc,m,n);
    floodfill(v,x,y+1,old,newc,m,n);
    floodfill(v,x,y-1,old,newc,m,n);
}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            ll n,m; cin>>n>>m;
            vector<vector<ll>> v(m,vector<ll>(n,0));
            for(ll i=0 ; i<n ; i++){
                for(ll j=0; j<m ; j++){
                    cin>>v[i][j];
                }
            }
            ll x=2,y=2;
            ll newc=7;
            floodfill(v,x,y,v[x][y],newc,m,n);
            for(ll i=0 ; i<n ; i++){
                for(ll j=0; j<m ; j++){
                    cout<<v[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
    return 0;
}