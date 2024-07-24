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
        vi a;
        vi pre(n);
        for (ll i=0; i<n; i++)  
        {
            ll x; cin>>x;
            a.pb(x);
              
        }     
        sort(a.begin(),a.end());
        pre[0] = a[0];
        for (ll i=1; i<n; i++)
        {
            pre[i] = pre[i-1] + a[i];
        }
        ll t = upper_bound(pre.begin(),pre.end(),x) - pre.begin();
        // auto ub = upper_bound(pre.begin(),pre.end(),x) - pre.begin();
        // ll t = distance(pre.begin(), ub);
        // ll t = *ub;
        
        // cout<<t<<endl;
        if (t == 0){
            cout<<0<<endl;
            continue;
        }
        // for (auto i:pre)
        //     cout<<i<<" ";
        t--;
        ll pk = t;
        ll sum = 0;
        vi v;
        // for (ll i=t; i>=0; i--)
        // {
        //     ll q = pre[i];
        //     ll c = 0;
        //     // while (q <= x)
        //     // {
        //     //     c++;
        //     //     q += (i+1);
        //     // }
        //     c += x/(q-i);
        //     v.pb(c);
        //     // sum += q*c;
        // }
        // for (auto i:v)
        //     cout<<i<<" ";
        // pk = 1;
        // for (ll i=v.size()-1; i>=0; i--)
        // {
        //     if (i!=0)
        //     {
        //         // sum += pk*(v[i]-v[i-1]);
        //         pk++;
        //     }
        //     else if (i==0){
        //         // sum += pk*v[0];
        //     }
        // }
        sum = 0;
        for (ll i=0; i<n; i++)
        {
            if (pre[i] <= x)
            {
                sum += (x-pre[i])/(i+1) + 1;
            }
        }
        cout<<sum<<endl;
        // cout<<endl;
    }
    return 0;
}