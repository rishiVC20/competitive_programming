// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
bool isBin(ll i)
{
    string s = to_string(i);
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '0' || s[i] == '1')
            continue;
        else
            return false;
    }
    return true;
}
int main()
{
    ll t;
    cin >> t;
    vector<ll> b;
    for (ll i = 2; i <= 1e5; i++)
    {
        if (isBin(i))
        {
            b.push_back(i);
        }
    }
    while (t--)
    {
        ll n;
        cin >> n;
        

        for (ll i = b.size() - 1; i >= 0; i--)
        {
            while (n % b[i] == 0)
            {
                n /= b[i];
            }
        }
        if (n == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}