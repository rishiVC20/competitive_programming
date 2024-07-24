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
        ll n,l,r;
        cin>>n>>l>>r;
        vi a;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }       

        sort(a.begin(),a.end());
        ll ans = 0;
        for (ll i=0; i<n; i++)
        {
            auto p1 = upper_bound(a.begin(),a.begin()+i,r-a[i])-a.begin();
            auto p2 = lower_bound(a.begin(),a.begin()+i,l-a[i])-a.begin();
            cout<<p1<<' '<<p2<<' '<<'h'<<' ';
            ans += abs(p1-p2); 
        }
        cout<<ans<<endl;
        // cout<<(ans/2)<<endl;
    }
    return 0;
}