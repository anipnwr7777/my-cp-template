#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
map<string, int> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;

    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        stringstream stream;
        stream << s;
        char b;
        while (true)
        {
            stream >> b;
            if (b == '1')
            {
                string r;
                stream >> r;
                int number;
                stream >> number;
                m[r] += number;
                break;
            }
            if (b == '2')
            {
                string r;
                stream >> r;
                m[r] = 0;
                break;
            }
            if (b == '3')
            {
                string r;
                stream >> r;
                cout << m[r] << "\n";
                break;
            }
        }
    }
    return 0;
}
