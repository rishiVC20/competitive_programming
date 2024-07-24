// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>

const ll mod = 1e9 + 7;

ll mul(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{

    a = (a * b) / (__gcd(a, b));
    return a;
}
ll power(ll base, ll exponent)
{
    if (exponent < 0)
    {
        return 0;
    }
    ll ans = 1;
    while (exponent)
    {
        if (exponent % 2 == 0)
        {
            base = (base * base) % mod;
            exponent = exponent / 2;
        }
        else
        {
            ans = (ans * base) % mod;
            exponent--;
        }
    }
    return ans;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll h, n;
        cin >> h >> n;
        vi a;
        vi c;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.pb(x);
        }
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            c.pb(x);
        }

        ll i = 0;
        ll cn = 1;
        ll kk = accumulate(a.begin(), a.end(), 0);
        h -= kk;
        if (h <= 0)
        {
            cout << cn << endl;
            continue;
        }
        // while (h > 0)
        // {
        //     h -= a[i];
        //     i += c[i];
        //     i = i%n;
        //     cn++;
        // }
        while (h > 0)
        {
            for (ll i = 0; i < n; i++)
            {
                if (cn % (c[i]) == 0)
                    h -= a[i];
            }
            cn++;
        }
        cout << (ll)cn << endl;
    }
    return 0;
}

/*
1
3
15
25
1
19999800001
1
21

*/