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
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }
        vi b;
        for (ll i=0; i<n-1; i++)
        {
            b.pb(__gcd(a[i],a[i+1]));
        }

        ll cn = 0;
        bool f = true;
        bool t = true;
        ll tt = 0;
        for (ll i=0; i,b.size()- 1; i++)
        {
            
            if (b[i] > b[i+1] && f==true)
            {
                cn++;
                if (cn){
                    tt++;
                }
            }
            else if (b[i]>=b[i+1] && cn==1 && f==true)
            {
                cn++;
            }
            else {
                if (tt){
                    t = false;
                    break;
                }
                if (cn==2)
                {
                    f = false;
                }
                if (cn==1)
                {
                    f = false;
                    t = false;
                    break;
                }
            }
        }

        if (t)
            cout<<"YES"<<endl; 
        else
            cout<<"NO"<<endl;    
    }
    return 0;
}