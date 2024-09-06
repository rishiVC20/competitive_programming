// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
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
        ll n;
        cin>>n;
        vi a;
        bool f=false;
        ll p=0;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(x<0){
                f=true;
                p++;
            }
        }
        if(!f){
            ll c=accumulate(a.begin(),a.end(),0);
            cout<<c<<endl;
            continue;
        }
        sort(a.begin(),a.end());
        if(p%2==0){
            ll c=0;
            for(ll i=0; i<n; i++){
                c += abs(a[i]);
            }
            cout<<c<<endl;
        }
        else{
            ll c=0;
            ll maxi=INT_MAX;
            for(ll i=0; i<n; i++){
                c += abs(a[i]);
                maxi = min(maxi,abs(a[i]));
            }
            c -= 2*maxi;

            cout<<c<<endl;
        }
    }
    return 0;
}