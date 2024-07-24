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
        ll n;
        cin>>n;
        vi a;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);           
        }
        vi pre(n);
        vi maxi(n);
        pre[0] = a[0];
        maxi[0] = a[0];

        for (ll i=1; i<n; i++)
        {
            maxi[i] = max(maxi[i-1],a[i]);
            pre[i] = pre[i-1] + a[i];
        }
        // for (auto i:maxi)
        //     cout<<i<<" ";
        // cout<<endl;    
        ll cn = 0;
        if (a[0]==0)
            cn++;
        if (n==1 ){
            cout<<cn<<endl;
            continue;
        }
        for (ll i=1; i<n; i++)
        {
            if (maxi[i] == (pre[i]-maxi[i]))   
                cn++;
        }

        cout<<cn<<endl;
    }
    return 0;
}

/*
1
0
3
3
4
1
2

*/