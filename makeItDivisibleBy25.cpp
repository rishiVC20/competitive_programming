// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll solve(string &p, string &e)
{
    ll ans = 0;
    ll len = p.size() - 1;
    while (len >= 0 && p[len] != e[1])
    {
        len--;
        ans++;
    }
    len--;
    if (len < 0)
        return INT_MAX;
    while (len >= 0 && p[len] != e[0])
    {
        len--;
        ans++;
    }
    return (len < 0) ? INT_MAX : ans;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string p = to_string(n);
        string sub[4] = {"00", "25", "50", "75"};
        ll ans = INT_MAX;
        for (auto e : sub)
        {
            ans = min(ans, solve(p, e));
        }
        cout << ans << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1593/B