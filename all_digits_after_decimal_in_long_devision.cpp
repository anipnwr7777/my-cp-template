#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
#define int long long
#define largest 9223372036854775807
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) 
{
    cerr << '{';
     __print(x.first); 
     cerr << ','; 
     __print(x.second); 
     cerr << '}';
 }

template<typename T>
void __print(const T &x) 
{
    int f = 0; 
    cerr << '{'; 
    for (auto &i: x) 
        cerr << (f++ ? "," : ""), __print(i); 
    cerr << "}";
}
void _print() 
{
    cerr << "]\n";
}
template <typename T, typename... V>
void _print(T t, V... v) 
{
    __print(t); 
    if (sizeof...(v)) 
        cerr << ", "; 
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//----------------------------------------------------------------------------------------------



void precomputation()
{
    //no precomputation
}

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=1 ; i<100000 ; i++)
    {
        a*=10;
        if(a/b == c)
        {
            cout<<i<<endl;
            return;

        }
        a%=b;
    }
    cout<<-1<<endl;
}

//------------------------------------------------------------------------------------------------

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    precomputation();

    {
    solve();
    }

    return 0;
}