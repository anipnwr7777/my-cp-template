#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll wt[100];
ll cache[100][100];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

bool subsetsum(ll n, ll sum)
{
    // yha pe bhaut badi point hai. bas base case ne aadha ghanta kharab kar diya.
    //(n<0) wali condition upar likhi thi aur pehle n check ho rha tha aur n har baar -1
    // ho rha tha last me. to har baar false aana hi tha. to pehle (sum == 0) check karna
    // chaiye tha kyuki usi se true return hoga agar hota hai to. nahi to baad me to
    // n<0 check ho hi jayega. tab flase aayega to chalega. to ye apne aapme imp hai.

    //*************  sequence in which base case are compared  ******************

    if (sum == 0)
    {
        return true;
    }

    // sum == 0 isiliye kyuyki us sequence of decision me jisme muje sum last me zero mil
    // jata hai wohi to chaiye tha. n negative na ho check kar sakta tha lekin nahi
    // kara kyuki already me recursive call se pehle kam weight wale call hi kar
    // raha hu. jo  weight allowed weight se jyada hai me use call hi nahi kar rha.
    // to weight kabhi negative nahi hi hoga. isiliye nahi check kiya.

    if (n < 0)
    {
        return false;
    }

    if (cache[n][sum] != -1)
    {
        return cache[n][sum];
    }

    if (wt[n] <= sum)
    {
        return cache[n][sum] = subsetsum(n - 1, sum - wt[n]) || subsetsum(n - 1, sum);
    }
    else
    {
        return cache[n][sum] = subsetsum(n - 1, sum);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, sum;
        cin >> n >> sum;
        memset(cache, -1, sizeof(cache));

        for (ll i = 0; i < n; i++)
        {
            cin >> wt[i];
        }

        cout << subsetsum(n - 1, sum) << "\n";
    }
    return 0;
}