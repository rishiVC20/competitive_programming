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
        vi a,b;
        for (int i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }       
        for (ll i=0; i<n+1; i++){
            ll x; cin>>x;
            b.pb(x);
        }
        // for (auto i:a)
        //     cout<<i<<" ";
        // for (auto i:b)  
        //     cout<<i<<" ";    
        ll cn = 1;
        ll p = b[n];
        bool f = false;
        ll k = INT_MAX;
        for (int i=0; i<n; i++)
        {
            if ((a[i]>=p && b[i]<=p) || (a[i]<=p && b[i]>=p)){
                f = true;
                break;
            }
            k = min(k,min(abs(a[i]-p),abs(b[i]-p)));
        }
        if (!f)
            cn += k;
        for (ll i=0; i<n; i++){
            cn += abs(a[i]-b[i]);
        }    

        cout<<cn<<endl;
    }
    return 0;
}