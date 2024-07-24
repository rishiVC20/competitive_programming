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
        ll n;
        cin>>n;
        ll k = n*(n-1)/2;
        vi arr;
        for (ll i=0; i<k; i++){
            ll x;
            cin>>x;
            arr.pb(x);
        }  
        sort(arr.begin(),arr.end());
        for (ll i=0; i<k; i+=n){
            cout<<arr[i]<<" ";
            n--;
        }     
        cout<<arr[k-1]<<endl;
    }
    return 0;
}