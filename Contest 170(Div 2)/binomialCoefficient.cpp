// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

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
    ll tt;
    cin>>tt;
    // while (tt--)
    // {
        vi a,b;
        for(ll i=0; i<tt; i++){
            ll x;cin>>x;
            a.pb(x);
        }
        for(ll i=0; i<tt; i++){
            ll x;cin>>x;
            b.pb(x);
            ll ans=power(2,x);
            // cout<<ans<<' ';
            // ans= (ans % maxi + maxi) % maxi;
            cout<<ans<<endl;
        }

        

    // }
    return 0;
}