#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);

    // left shift right shift
    // ll n = 8;
    // cout << (n >> 1) << "\n";
    // cout << (n << 2) << "\n";

    //check if ith bit is set or not
    // ll no = 15;
    // ll n = 1;
    // ll i;
    // cin >> i;
    // n = n << i;
    // if ((no & n) == 0)
    // {
    //     cout << "false"
    //          << "\n";
    // }
    // else
    // {
    //     cout << "true"
    //          << "\n";
    // }

    //check if ith bit is clear or not
    // ll no = 15;
    // ll n = 1;
    // ll i;
    // cin >> i;
    // n = n << i;
    // if ((no & n) == 0)
    // {
    //     cout << "true"
    //          << "\n";
    // }
    // else
    // {
    //     cout << "false"
    //          << "\n";
    // }

    //set the ith bit
    // ll no = 15;
    // ll n = 1;
    // ll i;
    // cin >> i;
    // n = n << i;
    // no = no | n;
    // cout << no << "\n";

    //clear ith bit
    // ll no = 15;
    // ll n = 1;
    // ll i;
    // cin >> i;
    // n = n << i;
    // n = ~(n);
    // no = no & n;
    // cout << no << "\n";

    //counting number of set bits
    // ll n = 10;
    // ll count = 0;
    // while (n > 0)
    // {
    //     if (n & 1 == 1)
    //     {
    //         count++;
    //     }
    //     n = n >> 1;
    // }
    // cout << count << "\n";

    //counting number of set bits
    ll n = 15;
    ll cnt = 0;
    while (n > 0)
    {
        cnt++;
        n = n & (n - 1);
    }
    cout << cnt << "\n";

    return 0;
}