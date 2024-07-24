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
        ll n,k,a,b;
        cin>>n>>k>>a>>b;
        vector<pair<ll,ll>>v;
        pair<ll,ll>c;
        pair<ll,ll>d;
        for(ll i=0; i<n; i++)
        {
            ll x,y;
            cin>>x>>y;
            if (i < k){
                // v[i].first=x;
                // v[i].second=y;
                pair<ll,ll>l;
                l.first=x;
                l.second=y;
                v.pb(l);
            }
            if (i+1==a){
                c.first=x;
                c.second=y;
            }
            if (i+1==b){
                d.first=x;
                d.second=y;
            }
        }   
        // for (ll i=0; i<k; i++)
        //     cout<<v[i].first<<" "<<v[i].second<<" "<<endl;; 
        // cout<< c.first<<" "<<c.second<<" ";
        // cout<< d.first<<" "<<d.second<<" ";
        if (a<=k && b<=k){
            cout<<0<<endl;
            continue;
        }   
        ll dif = abs(d.first-c.first) + abs(d.second-c.second);
        ll minia = INT_MAX;
        ll minib = INT_MAX;
        for (ll i=0; i<v.size(); i++)
        {
            
            minia = min(minia,abs(c.first-v[i].first)+abs(c.second-v[i].second));
            minib = min(minib,abs(d.first-v[i].first)+abs(d.second-v[i].second));
        }
        ll dif2 = minia+minib;
        cout<<min(dif,dif2)<<endl;
        // cout<<dif2<<endl;
    }
    return 0;
}