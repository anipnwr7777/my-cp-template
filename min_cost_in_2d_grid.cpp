#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cost[101][101];
ll cache[101][101];                                            // **** memoisation  **** // take size plus 1

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

ll mincost(ll r, ll c)
{
    if(r == 1) return cache[1][c];
    if(c == 1) return cache[r][1];

    if(cache[r][c] != -1) return cache[r][c];
    else
    {
        return cache[r][c] = min (mincost(r-1,c) , mincost(r, c-1) ) + cost[r][c];
    }
    
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
            ll r,c; cin>>r>>c;
            for(ll i = 1; i<= r ; i++)                           // **** r - rows ,,  c - columns   ****** /////
            {                                                    // *** indexing from one ***** //   
                for (ll j = 1; j <= c; j++)
                {
                    cin>>cost[i][j];
                }
            }    
            cache[1][1] = cost[1][1];
            for (ll i = 2; i <= c; i++)
            {
                cache[1][i] = cache[1][i-1] + cost[1][i];
            }
            for (ll i = 2; i <= r ; i++)
            {
                cache[i][1] = cache[i-1][1] + cost[i][1];
            }
            cout<<mincost(r,c)<<"\n";              
        }
    return 0;
}