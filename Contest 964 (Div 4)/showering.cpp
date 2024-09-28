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
        ll n,s,m;
        cin>>n>>s>>m;
        bool f=false;
        vector<pair<ll,ll>>v;
        for (ll i=0; i<n; i++){
            ll x,y;
            cin>>x>>y;
            if (i==0){
                if (x-0 >= s)
                    f=true;
            }
            v.pb({x,y});
        }
        if (f){
            YES;
            continue;
        }
        for (ll i=1; i<n; i++){
            if (v[i].first-v[i-1].second >= s){
                f=true;
                break;
            }
        }
        ll g = v.size();
        if (m-v[g-1].second >= s)
            f=true;
        if (f){
            YES;
        }
        else{
            NO;
        }
    }
    return 0;
}