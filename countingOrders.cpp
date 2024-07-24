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
        vi b;
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            a.pb(x);
        }       
        for (ll i=0; i<n; i++){
            ll x;  cin>>x;
            b.pb(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll j=0;
        vi s;
        for (ll i=0; i<n; i++)
        {
            while (j<n && a[j]<=b[i]){
                j++;
            }
            // s[i] = n-j;
            // cout<<n-j<<" ";
            s.pb(n-j);
        }
        sort(s.begin(),s.end());
        for (auto i:s){
            // cout<<s[i]<<" ";
        }
        for (ll i=0; i<n; i++)
        {
            s[i] -= i;
        }
        // for (auto i:s){
        //     cout<<s[i]<<" ";
        // }
        ll p = 1;
        for (ll i=0; i<n; i++)
        {
            p = mul(p,s[i],mod);
        }

        cout<<p<<endl;
    }
    return 0;
}