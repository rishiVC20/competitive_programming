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
        ll a;
        // a = ((n*(n+1)*2022)%mod)*(((4*n-1)*2022)%mod)*337/3 + ((n*(n+1)*2022)%mod)/2;
        a = (((n*(n+1))%mod)*((4*n-1))%mod*337)%mod ;
        // ans += ((n*(n+1)*2022)%mod)/2;
        // cout<<ans<<" ";
        // ll p = 0;
        // ll cn = 0;
        // ll i=1, j=2;
        // while (p < n-1)
        // {
        //     cn += (i*j);
        //     i++, j++;
        //     p++;
        // }       
        // ll k = (cn*2022)%mod;
        cout<<a<<endl;
    }
    return 0;
}