#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cost[11][11];
ll cache[11][11];

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}


// ******************************     in this question we are moving right and down only      ************************** //


int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            memset(cache,-1,sizeof(cache));  
            ll r,c,data; cin>>r>>c;
            for(ll i = 1; i<= r ; i++)                           // **** r - rows ,,  c - columns   ****** /////
            {                                                    // *** indexing from one ***** //   
                for (ll j = 1; j <= c; j++)
                {
                    cin>>cost[i][j];
                }
            }
            cache[1][1]=cost[1][1];
             for (ll i = 2; i <= c; i++)
            {
                cache[1][i] = cache[1][i-1] + cost[1][i];
            }
            for (ll i = 2; i <= r ; i++)
            {
                cache[i][1] = cache[i-1][1] + cost[i][1];
            }
            for (ll i = 2; i <= r; i++)
            {
                for (ll j = 2; j <= c; j++)
                {
                    cache[i][j] = min ( cache[i-1][j] , cache[i][j-1] ) + cost[i][j];
                }
                
            }
            cout<<cache[r][c]<<"\n";
        }
    return 0;
}