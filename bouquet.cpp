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
        ll n,m;
        cin>>n>>m;
        vi a;
        map<ll,ll>mp;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
            mp[x]++;
        }       

        sort(a.begin(),a.end());
        vector<pair<ll,ll>>v;
        for (auto i:mp){
            v.pb({i.first,i.second});
        }
        sort(v.begin(),v.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
            return a.first < b.second;
        });

        ll sum = v[0].second;
        for (ll i=1; i<v.size(); i++){
            if (v[i].first*v[i].second <= m)
                sum = max(sum,v[i].first*v[i].second);
            if (v[i].first-v[i-1].first <= 1){
                if (v[i].first*v[i].second + v[i-1].first*v[i-1].second <= m)
                    sum = max(sum,v[i].first*v[i].second + v[i-1].first*v[i-1].second);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}