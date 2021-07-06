#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<vector<ll>> visited(10,vector<ll>(10,0));

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

bool issafe(ll i, ll j, ll n, vector<vector<ll>> &arr) {
    return i>=0 and i<n and j<n and j>=0 and visited[i][j]==0 and arr[i][j]==0;
}

void ratmaze(vector<vector<ll>> &arr, ll n, ll &res, ll i, ll j) {
    if(issafe(i,j,n,arr) == 0) return;
    if(i==n-1 and j==n-1) {
        res++;
        return;
    }
    visited[i][j] = 1;
    ratmaze(arr,n,res,i-1,j);
    ratmaze(arr,n,res,i+1,j);
    ratmaze(arr,n,res,i,j-1);
    ratmaze(arr,n,res,i,j+1);
    visited[i][j] = 0;
}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            ll n,res=0; cin>>n;
            vector<vector<ll>> arr(n,vector<ll>(n,0));
            for(ll i=0 ; i<n ; i++ ) { 
                for(ll j=0 ; j<n ; j++ ) {
                    cin>>arr[i][j];
                }
            }
            if(arr[n-1][n-1]==1) {
                cout<<"0"<<"\n";
                return 0;
            }
            ratmaze(arr,n,res,0,0);
            cout<<res<<"\n";
        }
    return 0;
}