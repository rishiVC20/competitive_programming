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
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
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
        ll n,m;
        cin>>n>>m;
        vi a;
        ll prod = 1;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
            // prod *= (ll)x;
        }
        string s;
        cin>>s;
        ll i=0, j=n-1;

        vi v;
        ll k = 0;
        // cout<<prod<<" ";
        while (k < n)
        {
            // ll jj = (ll)prod % (ll)m;
            // v.pb(jj);
            // cout<<prod%m<<" ";
            if (s[k]=='L')
            {
                // prod = prod*a[i];
                i++;
            }
            else{
                // prod = prod/a[j];
                j--;
            }
            k++;
        }
        cout<<i<<" "<<j<<endl;
        prod *= a[i];
        ll x = i, y=i;
        k = s.size()-2;
        while (k >= 0)
        {
            v.pb(prod%m);
            if (s[k]=='R')
            {
                x--;
                prod *= a[x]; 
            }
            else if (s[k]=='L')
            {
                y++;
                prod *= a[y];
            }
            k--;
        }
        for (ll i=n-1; i>=0; i--)
            cout<<v[i]<<" ";

        cout<<endl;    

    }
    return 0;
}