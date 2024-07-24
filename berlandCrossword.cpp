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

void check(ll n, ll u, ll r, ll d, ll l, bool &f)
{
    ll U = 0, R = 0, D = 0, L = 0;
    U = u;
    if (U >= n-1)
    {
        R++;
        r--;
        if (U==n){
            L++;
            l--;
        }
    }
    if (R >= r)
    {
        f = true;
        return;
    }
    R += r;
    if (R >= n-1)
    {
        D++;
        d--;
        if (R==n){
            R++;
            r--;
        }
    }
    if (D >= d)
    {
        f = true;
        return;
    }
    D += d;
    if (D >= n-1)
    {
        L++;
        l--;
        if (D==n){
            D++;
            d--;
        }
    }
    if (L >= l)
    {
        f = true;
        return;
    }
    L += l;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool f = false;
        check(n, u, r, d, l, f);
        // cout<<f<<' ';
        check(n, u, l, d, r, f);
        // cout<<f<<' ';
        check(n, l, d, r, u, f);
        // cout<<f<<' ';
        check(n, l, u, r, d, f);
        // cout<<f<<' ';
        check(n, d, r, u, l, f);
        // cout<<f<<' ';
        check(n, d, l, u, r, f);
        // cout<<f<<' ';
        check(n, r, u, l, d, f);
        // cout<<f<<' ';
        check(n, r, d, l, u, f);
        // cout<<f<<' ';

        if (f)
            YES;
        else
            NO;    

    }
    return 0;
}