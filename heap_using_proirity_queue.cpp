#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        // max heap
        // priority_queue<ll> pq;
        // pq.push(3);
        // pq.push(6);
        // pq.push(4);
        // pq.push(9);
        // pq.push(5);
        // cout << pq.top() << "\n";
        // pq.pop();
        // cout << pq.top() << "\n";

        // min heap
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        pq.push(3);
        pq.push(6);
        pq.push(4);
        pq.push(9);
        pq.push(5);
        cout << pq.top() << "\n";
        pq.pop();
        cout << pq.top() << "\n";
        return 0;
    }
}