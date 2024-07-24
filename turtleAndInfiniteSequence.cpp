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
ll help(ll x)
{
    ll cn = -1;
    while (x)
    {
        cn++;
        x >>= 1;
    }
}
ll find (ll a, ll b)
{
    if (a==b)
        return a;

    ll ans = 0;
    ll a1 = help(a);    
    ll b1 = help(b);

    while (a1 == b1)
    {
        ll d = (1LL << b1);
        ans += d;
        a -= d;
        b -= d;
        a1 = help(a);
        b1 = help(b);
    }    

    b1 = max(a1,b1);
    for (ll i=0; i<=b1; i++)
    {
        ans += (1LL << i);
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
        if (m==0){
            cout<<n<<endl;
            continue;
        }       

        if (m==1 && n>0){
            cout<<(n-1|n|n+1)<<endl;
            continue;
        }
        
        ll d = max(0LL,n-m);
        ll d1 = n+m;
        ll ans = find(d,d1);

        cout<<ans<<endl;
    }
    return 0;
}