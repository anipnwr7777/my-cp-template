#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

vector<double> top3max(vector<double> &a){
    double max1, max2, max3;
    max1 = max2 = max3 = INT_MIN;
    for(int i=0 ; i<a.size() ; i++){
        if(a[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2){
            max3 = max2;
            max2 = a[i];
        }
        else if(a[i] > max3)
            max3 = a[i];
    }
    return {max1, max2, max3};
}

vector<double> top3min(vector<double> &a){
    double min1, min2, min3;
    min1 = min2 = min3 = INT_MAX;
    for(int i=0 ; i<a.size() ; i++){
        if(a[i] < min1){
            min3 = min2;
            min2 = min1;
            min1 = a[i];
        }
        else if(a[i] < min2){
            min3 = min2;
            min2 = a[i];
        }
        else if(a[i] < min3)
            min3 = a[i];
    }
    return {min1, min2, min3};
}

void solve(){
    vector<double> x = {1, 3, 4, 5, 3, 66, 3, 43 , 33};
    vector<double> ans = top3min(x);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}