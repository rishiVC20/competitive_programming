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
        ll n,x;
        cin>>n>>x;
        vi a,b,c;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            b.pb(x);
        }    
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            c.pb(x);
        }   

        ll sum = 0;
        ll ans = 0;
        if (x==0){
            cout<<"YES"<<endl;
            continue;
        }

        bool f = false;
        for (ll i=0; i<n; i++)
        {
            
            if ((a[i]|x) <= x)
            {
                sum = sum|a[i];
            }
            else
            {
                // sum = ans;
                break;
            }
        }
        for (ll i=0; i<n; i++)
        {
            if ((b[i]|x) <= x)
            {
                sum = sum|b[i];
            }
            else
            {
                // sum = ans;
                break;
            }
        }
        for (ll i=0; i<n; i++)
        {
            if ((c[i]|x) <= x)
            {
                sum = sum|c[i];
            }
            else
            {
                // sum = ans;
                break;
            }
        }

        

        if (sum==x)
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;    

    }
    return 0;
}