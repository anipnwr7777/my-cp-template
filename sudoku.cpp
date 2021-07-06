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

void print(vector<vector<ll>> &arr){
    cout<<"\n";
    for(ll i=0; i<9 ; i++){
                for(ll j=0 ; j<9 ; j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<"\n";
            }
            cout<<"\n";
}

bool isvalid(vector<vector<ll>> &arr,ll i,ll j,ll val){
    for(ll k=0 ; k<9 ; k++){
        if(arr[i][k] == val){
            return false;
        }
    }

    for(ll k=0 ; k<9 ; k++){
        if(arr[k][j] == val){
            return false;
        }
    }

    ll x= i/3*3;
    ll y= j/3*3;
    for(ll m=0; m<3 ; m++){
        for(ll n=0 ; n<3 ; n++){
            if(arr[x + m][y + n] == val) return false;
        }
    }
    return true;
}

void sudoku(vector<vector<ll>> &arr, ll i, ll j){
    if(i==8 and j==8){
        print(arr);
        return;
    }

    if(j==8){
        i=i+1;
        j=0;
    }
    else{
        j++;
    }

    if(arr[i][j] != 0){
        sudoku(arr,i,j);
    }
    else{
        for(ll pi=1; pi<=9 ; pi++){
            if(isvalid(arr,i,j,pi)){
                arr[i][j] = pi;
                sudoku(arr,i,j);
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            vector<vector<ll>> arr(9,vector<ll>(9,0));
            for(ll i=0; i<9 ; i++){
                for(ll j=0 ; j<9 ; j++){
                    cin>>arr[i][j];
                }
            }
            sudoku(arr,0,0);
            

        }
    return 0;
}