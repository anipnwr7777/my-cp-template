#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll cache[101][101];

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)  
{
    return a*b/gcd(a,b);
}

ll mcm(vector<ll> &arr, ll i, ll j){
    if(i>=j) return 0;

    if(cache[i][j] != -1) return cache[i][j];

    ll min=INT_MAX;
    for(ll k=i ; k<=j-1 ; k++){
        ll temp =  mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(temp<min){
            min=temp;
        }
    }  
    return cache[i][j] = min;
}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            memset(cache,-1,sizeof(cache));
            vector<ll> arr;
            ll data,n; cin>>n;
            while(n--){
                cin>>data; arr.push_back(data);
            }
            ll size=arr.size();
            cout<<mcm(arr,1,size-1)<<"\n";
        }
    return 0;
}