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
        vi a(n);
        for (ll i=0; i<n; i++)  
            cin>>a[i];
        if (n==1){
            cout<<0<<endl;
            continue;
        }    
        sort(a.begin(),a.end());
        ll i=0, j=n-1;
        ll maxi = 0;
        ll s1 = 0;
        ll s2 = 0;
        while (i < j){
            s1 += a[i];
            s2 += a[j];
            // cout<<"hhi"<<" ";
            ll diff = s2-s1;
            maxi = max(maxi,diff);
            i++;
            j--;
        }           
        cout<<maxi<<endl;
    }
    return 0;
}