#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
pair<int, int> arr[5];

bool comp(pair<int, int> x, pair<int, int> y)
{
    if (x.second < y.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    arr[0].first = 0;
    arr[0].second = 10;
    arr[1].first = 1;
    arr[1].second = 25;
    arr[2].first = 2;
    arr[2].second = 8;
    arr[3].first = 3;
    arr[3].second = 15;
    arr[4].first = 4;
    arr[4].second = 3;
    for (auto x : arr)
    {
        cout << x.first << " " << x.second << "\n";
    }

    sort(arr, arr + 5, comp);
    cout << "\n";
    for (auto x : arr)
    {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}