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
        string s;
        cin>>s;
        ll n = s.size();
        ll one = n;
        ll zero = 0;
        string k;
        for (ll i=0; i<n; i++) 
        {
            if (s[i]=='1')
                one = min(one,i);
            else
                zero = max(zero,i);    
        }      
        // cout<<one<<" "<<zero<<" ";
        if (one > zero){
            cout<<0<<endl;
            continue;
        }
        ll p = zero-one+1;
        string st = s.substr(one,p);
        // cout<<st<<" ";
        ll cn = 0;
        ll x = 0;
        for (ll i=0; i<st.size(); i++)
        {
            if (st[i]=='0'){
                cn += (i+1) - x;
                // cout<<cn<<" ";
                x++;
            }
        }
        cout<<cn<<endl;
    }
    return 0;
}