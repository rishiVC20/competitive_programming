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
        ll x;
        cin>>x;
        ll n = x;
        ll ans = INT_MIN;
        ll k,p;
        for (ll i=1; i<n; i++)
        {
            k = ans;
            ll d = __gcd(x,i)+i;
            ans = max(ans,d);
            // cout<<ans<<" ";
            if (k!= ans)
                p = i;   
        }       
        cout<<p<<endl;
    }
    return 0;
}