// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

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
        vi b;
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            a.pb(x);
        }
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            b.pb(x);
        }
        ll cn = 0;
        ll j=0; 
        for (ll i=0; i<n; i++){
            if (a[j] <= b[i])
                j++;
            else
                cn++;    
        }
        cout<<cn<<endl;
   }
    return 0;
}