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
        vi v;
        for (ll i=0; i<n; i++)
        {
            ll x1; cin>>x1;
            ll x2; cin>>x2;
            a.pb(x1);
            v.pb(x2);
        }       
        ll maxi = 0;
        for (ll i=0; i<n-1; i++)
        {
            for (ll j=i+1; j<n; j++)
            {
                ll k = a[i]*v[j] + a[j]*v[i];
                maxi = max(maxi,k);
            }
        }

        cout<<maxi<<endl;
    }
    return 0;
}