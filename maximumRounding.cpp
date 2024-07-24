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
        ll str;
        cin>>str;
        string sp = to_string(str);
        ll n = sp.size();
        cout<<n<<" ";
        ll num = stoi(sp);
        // cout<<num<<" ";
        for (ll i=1; i<=n; i++)
        {
            ll l = powl(10,i);
            ll k = num%l;
            ll x = l-k;
            ll p = l/2;
            if (p%10==9) p++;
            // cout<<num<<" ";
            // cout<<p<<" ";
            if (k >= p)
                num += x;
        }
        cout<<num<<endl;
    }
    return 0;
}