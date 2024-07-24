// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

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
        vi d;
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            a.pb(x);
            if (i!=0)
                d.pb(abs(a[i]-a[i-1]));
        }      
        // for (auto i:d)
        //     cout<<i<<" "; 
        ll sum = accumulate(a.begin(),a.end(),0);
        ll m = d.size();
        if (m==0){
            cout<<a[0]<<endl;
            continue;
        }
        sort(d.begin(),d.end(),greater<ll>());
        ll j=0;
        while (k--){
            sum -= d[j];
            j++;
            if (j==m)
                break;

        }
        cout<<sum<<endl;
    }
    return 0;
}