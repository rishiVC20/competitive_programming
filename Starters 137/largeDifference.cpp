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
        ll n,k;
        cin>>n>>k;
        vi a;
        ll sum = 0;
        for (ll i=0;i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
            if (i!=0){
                sum += abs(a[i]-a[i-1]);
            }
        }

        ll maxi = sum;
        for (ll i=0; i<n; i++)
        {
            ll kk= a[i];
            a[i] = 1;
            ll dd = 0;
            for (ll j=1; j<n; j++)
            {
                dd += abs(a[j]-a[j-1]);
            }
            maxi = max(maxi,dd);
            dd = 0;
            a[i] = k;
            for (ll j=1; j<n; j++)
            {
                dd += abs(a[j]-a[j-1]);
            }
            maxi = max(maxi,dd);
            a[i] = kk;
        }

        cout<<maxi<<endl;
   }
    return 0;
}