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
        vi a,b;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        // ll maxi = 0;
        // ll ui = -1;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            b.pb(x);
        }

        // ll m = k-1;
        // ll j=0;
        // // cout<<m<<" ";
        // while (m)
        // {
        //     if (b[j] > maxi)
        //     {
        //         maxi = b[j]; //1
        //         ui = j;
        //     }
        //     m--;
        //     j++;
        //     if (j==n)
        //         break;
        // }

        ll sum = 0;
        // sum += a[0];
        // k--;
        // for (ll i=1; i<ui+1; i++)
        // {
        //     if (k)
        //         sum += a[i];
        //     k--;
        // }
        // // cout<<ui<<" ";
        // ll y = k;
        // for (ll i=ui+1; i<=k; i++)
        // {
        //     // cout<<sum<<" ";
        //     if ( i<n && a[i] >= maxi)
        //         sum += a[i];
        //     else{
        //         sum += maxi*y;
        //         break;
        //     }
        //     y--;        
        // }
        ll ui = min(n,k);
        ll maxi = 0;
        ll ans = 0;
        for (ll i=0; i<ui; i++)
        {
            sum += a[i];
            ll rem = k-(i+1);
            maxi = max(maxi,b[i]);
            ans = max(ans,sum+rem*maxi);
        }
        // ll p = n-(ui+1);
        // sum += maxi*p;

        cout<<ans<<endl;

    }
    return 0;
}