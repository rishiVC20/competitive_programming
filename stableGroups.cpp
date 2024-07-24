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
ll customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
ll sortPairVector(vector<pair<ll, ll>> &v)
{
    sort(v.begin(), v.end(), [](pair<ll, ll> x, pair<ll, ll> y) {
        return x.second < y.second;
    });
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
    ll n, k, x;
    cin >> n >> k >> x;
    vi a;
    for (ll i = 0; i < n; i++)
    {
        ll z;
        cin >> z;
        a.pb(z);
    }
    sort(a.begin(), a.end());
    vector<pair<ll, ll>> v;
    // ll c = 0;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] > x)
        {
            v.pb({i, a[i] - a[i - 1]});
            // c++;
        }
    }

    // sort(v.begin(), v.end(), customComparator);
    sortPairVector(v);
    // sort(v.begin(), v.end(), [](pair<ll, ll> x, pair<ll, ll> y) {
    //     return x.second < y.second;
    // });
    if (v.size() == 0)
    {
        cout << 1 << endl;
        // return;
    }
    else if (k == 0)
    {
        cout << v.size() + 1 << endl;
        // return;
    }
    else
    {
        ll q = v.size();
        // cout<<q<<' ';
        for (ll i = 0; i < v.size(); i++)
        {
            ll diff = v[i].second;
            ll aa = diff / x;
            if (diff % x == 0)
                aa--;
            // cout<<k<<' ';
            if (k >= aa)
            {
                k -= aa;
                q--;
            }
            else if (k <= 0)
                break;
        }

        cout << q + 1 << endl;
        return 0;
    }