// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
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
        if (exponent%2==0)
        {
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else
        {
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}


int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vi a;
        ll c = 0;
        ll d = 0;
        bool f = false;
        ll maxi =0;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            if (x>0)
                f = true;
            
            d += x;
            
            c += x;
            c = max(abs(c),abs(d));
            // cout<<c<<" ";
            // maxi = max(c,abs(d));
            // cout<<maxi<<" ";
            
        }

        cout<<c<<endl;
    }
    return 0;
}