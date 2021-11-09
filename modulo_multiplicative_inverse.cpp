#include<bits/stdc++.h>
using namespace std;
#define int long long
#define largest 9223372036854775700
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

template<typename t>
void __print(vector<t> v)
{
    cerr << endl;
    for (t x : v) {__print(x); cerr << " ";}
    cerr << endl;
}

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
    for (auto &i : x)
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

#define mod 1000000007

int power(int x, int y)
{
    // this is modular exponentiation --> (x ^ y) % mod
    if (y == 0)
        return 1;
    if (y % 2 == 0)
        return (power( x , y / 2 ) * power( x , y / 2 )) % mod;
    else
        return (x * power( x , (y - 1) / 2) * power( x , (y - 1) / 2 )) % mod;
}

int solve(int a) {
    a++;
    int ans = 0, divisionFactor = 2, multiplicationFactor = 1;
    for (int i = 1 ; i <= 35 ; i++) {
        int inv = power(divisionFactor, mod - 2);
        ans = (ans + ((a % mod) * (inv % mod) * (multiplicationFactor % mod)) % mod) % mod;
        divisionFactor *= 2;
        multiplicationFactor *= 2;
    }
    return ans;
}


void solve() {
    // int a; 
    // cin >> a;
    // cout << solve(a) << endl;
    cout << power(2, mod-2) << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}