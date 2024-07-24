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
        vi arr;
        unordered_set<ll>p;
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            arr.pb(x);
            p.insert(x);

        }
        sort(arr.begin(),arr.end());
        // for (auto i:arr)
        //     cout<<i<<" ";
        ll count = 0;
        ll curr = 1;
        vi arr2;
        bool f = true;
        for (ll i=1; i<n; i++){
            if (arr[i] == arr[i-1]){
                curr++;
            }
            else{
                arr2.push_back(curr);
                curr = 1;
                if (i==n-1) 
                    f = false;
            }
        }
        if (f)
            arr2.pb(curr);
        // for (auto i:arr)
        //     cout<<i<<" ";
        // cout<<endl;    
        // for (auto i:arr2)
        //     cout<<i<<" ";
        // ll count = 0;
        for (ll i=0; i<arr2.size(); i++)
        {
            if (arr2[i] > 2){
                ll k = arr2[i]/3;

                count += k;
            }
        }
        cout<<count<<endl;
        
   }
    return 0;
}