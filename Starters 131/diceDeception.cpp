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
        vi arr;
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            arr.pb(x);
        }       
        sort(arr.begin(),arr.end());
        for (ll i=0; i<k; i++){
            if (arr[i] < 4)
                arr[i] = 7-arr[i];
        }
        ll sum = accumulate(arr.begin(),arr.end(),0);
        cout<<sum<<endl;
    }
    return 0;
}