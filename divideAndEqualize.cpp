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

void countDivisor(ll x, map<ll,ll> &mp){
    ll i = 2;
    while (i*i<=x){
        while (x%i==0){
            mp[i]++;
            x /= i;
        }
        i++;
    }
    if (x>1) mp[x]++;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vi a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }       
        map<ll,ll>mp;
        sort(a.begin(),a.end());
        for (auto i:a){
            countDivisor(i,mp);
        }
        bool f = true;
        for (auto i:mp){
            cout<<i.first<<' '<<i.second<<" ";
        }
        for (auto i:mp){
            if (i.second%n != 0){
                f = false;
                break;
            }
        }

        if (f)
            YES;
        else
            NO;    
    }
    return 0;
}