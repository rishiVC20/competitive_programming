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
        vector<pair<ll,ll>> a;
        for (ll i=0; i<2; i++){
            ll l,r;
            cin>>l>>r;
            a.pb({l,r});
        }
        sort(a.begin(),a.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
            return a.first<b.first;
        });
        if (a[0].second+1==a[1].first){
            cout<<1<<endl;
            continue;
        }
        cout<<'a';
        if (a[0].second==a[1].first){
            cout<<2<<endl;
            continue;
        }
        cout<<'b';
        if (a[0].second<a[1].first){
            cout<<0<<endl;
            continue;
        }
        cout<<'c';
        ll s1=a[0].second-a[1].first;
        ll s2=a[1].second-a[0].first;
        ll t1 = min(s1,s2);
        ll j=max(a[0].second-a[0].first,a[1].second-a[1].first);

        cout<<min(t1,j)<<endl;
    }
    return 0;
}