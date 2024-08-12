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
        ll n; cin>>n;
        vector<pair<ll,ll>> a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb({i+1,x});
        }
        // for (auto i:a)
        //     cout<<i.first<<' '<< i.second<<' ';
        // cout<<endl;    
        ll cn = 0;
        vi b;
        for (ll i=1; i<=n; i++)
            b.pb(i);
        for (ll i=1; i<a.size(); i++){
            ll j = lower_bound(b.begin(),b.end(),a[i].second)-b.begin();
            cout<<j<<' ';
            if (j>=0 && b[j]==a[i].first)
                j--;
            if (j>=0){
                cn += j+1;
            }    
        }

        cout<<cn<<endl;
    }
    return 0;
}