#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cache[101][101];                         //*********** see the size ********//

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
            ll r,c; cin>>r>>c;
            for (ll i = 1; i <= r; i++) cache[1][i] = 1;                              // initialisation      
            for (ll j = 1; j <= c; j++) cache[j][1] = 1;                              // initialisation     
            for (ll i = 2; i <= r; i++)
            {
                for (ll j = 2; j <= c; j++)
                {
                    cache[i][j] = cache[i-1][j] + cache[i][j-1] ;                   // ****** 1 based indexing ******  //
                }
            }
            cout<<cache[r][c]<<"\n";
        }
    return 0;
}

//// ***************** if some cells are blocked ****************  ////
/*
the code is same as above just some changes. generalised formula is same except -

1. in initialisation the number of ways to reach a point after blocked cell is zero. the number of ways to reached a blocked cell is zero. 

*/