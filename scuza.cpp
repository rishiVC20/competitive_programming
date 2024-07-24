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
        ll n,q;
        cin>>n>>q;
        vi a,b;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }       
        for (ll i=0; i<q; i++)
        {
            ll x; cin>>x;
            b.pb(x);
        }
        vi pre(n);
        vi maxi(n);
        maxi[0] = a[0];
        pre[0] = a[0];
        for (ll i=1; i<n; i++)
        {
            maxi[i] = max(maxi[i-1],a[i]);
            pre[i] = pre[i-1] + a[i];
        }

        ll sum = 0;
        ll p;
        // for (ll i=0; i<q; i++)
        // {
        //     ll j=0, l=b[i];
        //     p = 0;
        //     bool f = false;
        //     while (l >= a[j])
        //     {
        //         p++;
        //         j++;
        //         f = true;
        //         if (j==n)
        //             break;
        //     }
        //     // sum += pre[p];
        //     if (f)
        //         cout<<pre[p-1]<<" ";
        //     else
        //         cout<<0<<" ";
        // }

        for (ll i=0; i<q; i++)
        {
            ll it = upper_bound(maxi.begin(),maxi.end(),b[i]) - maxi.begin();
            // cout<<it<<" ";
            if (it != 0){
                // cout<<it-maxi.begin()<<" ";
                cout<<pre[it - 1]<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
        // cout<<sum<<endl;
    }
    return 0;
}