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
        vi v;
        ll p = 0;
        for (ll i=0; i<n-1; i++){
            ll x;
            cin>>x;
            p = max(p,x);
            v.pb(x);
        }   
        for(auto i:v){
            // cout<<i<<" ";
        }
        cout<<p+1<<" ";   
        ll k = p+1; 
        for (ll i=0; i<n-1; i++){
            k = k+ v[i];
            cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}