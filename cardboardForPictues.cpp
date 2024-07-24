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
        ll n,c;
        cin>>n>>c;
        vi s;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            s.pb(x);
        }       
        ll start = 1;
        ll end = 1e9;
        ll mid = 0;
        ll ans=0;
        while (start <= end)
        {
            mid = start + (end-start)/2;
            ll sum = 0;
            for (ll i:s)
            {
                sum += (i+mid)*(i+mid);
                if (sum > c)
                    break;
            }
            if (sum==c){
                ans = mid;
                break;
            }
            else if (sum < c){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        cout<<ans/2<<endl;
    }
    return 0;
}