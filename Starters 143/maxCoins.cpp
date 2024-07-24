// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout << 'Y' << 'E' << 'S' << endl
#define NO cout << 'N' << 'O' << endl

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
bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
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
    vi a;
    for (ll i = 1; i <= 10; i++)
    {
        a.pb(powl(2, i));
    }
    // for (auto i : a)
    //     cout << i << ' ';
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        // ll cp = n*(n+1)/2-((n-x)*(n-x+1)/2);
        // ll cp2 = (n-x)*(n-x+1)/2;
        // cout<<cp-cp2<<endl;

        ll k = n;
        ll b = n - x;
        ll cp = 0;
        ll v=0;
        while (v!=x)
        {
            cp += pow(2, k);
            v++;
            k--;
            // if (k==(x+1))
            //     break;
        }

        while (b != 0)
        {
            cp -= pow(2, b);
            b--;
        }

        cout << cp << endl;
    }
    return 0;
}