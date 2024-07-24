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
        ll f = true;
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            arr.pb(x);
            if (x%k!=0)
                f = false;
        }       
        if (f){
            cout<<0<<endl;
            continue;
        }
        sort(arr.begin(),arr.end());
        ll p = arr[n-1];
        ll diff1 = arr[n-1]-arr[0];
        ll c = k/2;
        for (ll i=0; i<n; i++)
        {
            ll diff = p-arr[i];
            if (diff>0){
                ll m = diff/k;
                arr[i] += m*k;
                // if (p-arr[i] > c)
                //     arr[i] += k;
            }
        }
        ll mini = arr[n-1];
        for (ll i=0; i<n; i++)
            mini = min(mini,arr[i]);
        ll sum = p - mini;    
        // for (auto i:arr)
        //     cout<<i<<" ";
        sort(arr.begin(),arr.end());
        p = arr[n-1];
        for (ll i=0; i<n; i++){
            sum = min(sum,p-arr[i]);
            p = max(p,arr[i]+k);
        }
        cout<<sum<<endl;
        // ll diff2 = arr[n-1]-arr[0];
        // if (diff1 < diff2) 
        //     cout<<diff1<<endl;
        // else
        //     cout<<diff2<<endl;    
    }
    return 0;
}