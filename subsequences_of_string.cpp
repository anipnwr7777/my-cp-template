#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<string> f(string s)
{
    if (s == "")
    {
        vector<string> l;
        l.push_back("");
        return l;
    }

    char e = s[0];
    string d = s;
    d.erase(0, 1);
    vector<string> t = f(d);
    vector<string> ans;
    for (auto x : t)
    {
        ans.push_back("_ " + x);
    }
    for (auto x : t)
    {
        ans.push_back(e + x);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> ans = f("abcde");
    for (auto x : ans)
    {
        cout << x << "\n";
    }

    return 0;
}