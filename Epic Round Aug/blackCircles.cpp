// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  
#define db double
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
        vector<pair<ll,ll>>v;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            ll y; cin>>y;
            v.pb({x,y});
        }       
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll z = powl(x1-x2,2)+powl(y1-y2,2);
        vi d;
        // cout<<z<<' ';
        bool f=true;
        for (ll i=0; i<n; i++){
            ll k1=v[i].first;
            ll k2=v[i].second;

            // ll g = powl(k1-x1,2)+powl(k2-y1,2);
            ll h = powl(k1-x2,2)+powl(k2-y2,2);
            // cout<<g<<' '<<h<<' ';
            if (z >= h){
                f=false;
                break;
            }
            // if (max(g,h) < z){
            //     f=false;
            //     break;
            // }
        }
        if (f){
            YES;
        }
        else{
            NO;
        }
    }
    return 0;
}

/*
YES
NO
YES
YES
YES
NO
YES
*/