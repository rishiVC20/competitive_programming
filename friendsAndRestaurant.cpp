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
        vector<pair<ll,ll>>arr(n);
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            arr[i].first = x;
        }
        vi diff1;
        vi diff2;
        ll count = 0;
        ll sum = 0;
        ll k = 0;
        vi diff;
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            arr[i].second = x;
            ll p = arr[i].second-arr[i].first;
            // if (p>=0)
            // cout<<p<<" ";
            // if (p >= 0){
            //     if (p != 0)
            //         diff1.pb(p);
            //     // if (p==0) k++;
            //     count++;
            //     sum += p;
            // }
            // else{
            //     diff2.pb(p);
            // }
            diff.pb(p);
        }
        // ll cnt = count - k;
        // sort(diff1.begin(),diff1.end());
        // sort(diff2.begin(),diff2.end(), greater<ll>());
        // // for (auto i:diff1)
        // //     cout<<i<<" ";
        // // for (auto i:diff2)
        // //     cout<<i<<" ";    
        // ll m = min(diff1.size(),diff2.size());
        // for (ll i=0; i<m; i++)
        // {
        //     if (diff1[i] >= abs(diff2[i]))
        //         count++;
        // }
        // cout<<count/2<<endl;

        sort(diff.begin(),diff.end(),greater<ll>());
        ll j =n-1;
        ll cn = 0;
        for (ll i=0; i<n; i++)
        {
            while (j>i && diff[i]+diff[j]<0)
                j--;
            if (j<=i)
                break;
            cn++;
            j--;        
        }
        cout<<cn<<endl;
    }
    return 0;
}