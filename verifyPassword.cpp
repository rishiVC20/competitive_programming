// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
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
        ll n; cin>>n;
        string s;
        cin>>s;
        bool f = true;
        for (ll i=0; i<n-1; i++)
        {
            if (s[i] > s[i+1]){
                f = false;
                break;
            }
            // cout<<s[i]<<' ';
        }       
        if (f)
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;    
    }
    return 0;
}