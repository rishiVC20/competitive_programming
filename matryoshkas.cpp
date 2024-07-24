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
        map<ll,ll>mp;
        set<ll>st;
        vi kk;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
            mp[x]++;
            st.insert(x);
        }       

        sort(a.begin(),a.end());
        for (auto i:st)
            kk.pb(i);
        sort(kk.begin(),kk.end());        
        
        ll maxi = 0;
        mp[0] = 0;
        auto it = mp.begin();
        while (it != mp.end())
        {
            ll x = (*it).first;
            ll y = (*it).second;
            ll diff = mp[x-1];
            ll inc = max(y-diff,0LL);
            maxi += inc;
            it++;
        }
        cout<<maxi<<endl;
    }
    return 0;
}