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

ll func(ll n){
    ll c = 0;
    while (n){
        n >>= 1;
        c++;
    }
    return c;
}
int main() {
    ll t;
    cin>>t;
    vi pre(1e7);
    pre[0]=0;
    for (ll i=1; i<1e7; i++)
    {
        ll kp = func(i);
        pre[i] = kp;
    }
    // cout<<pre[2]<<' '<<pre[3]<<' '<<pre[4]<<' '<<pre[7]<<' '<<pre[12]<<' ';
    while (t--)
    {
        ll n;
        cin>>n;
        vi a;
        // vector<pair<ll,ll>>a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }    
        // sort(a.begin(),a.end());
        ll sum = 0;
        // for (ll i=0; i<n-1; i++){
        //     for (ll j=i+1; j<n; j++){
        //         if ((a[i]&a[j]) >= (a[i]^a[j]) )
        //             sum++;
        //     }
        // }

        sort(a.begin(),a.end());
        map<ll,ll>mp;
        for (ll i=0; i<n; i++){
            ll cp = log2(a[i]);
            if (mp.find(cp) != mp.end())
                sum += mp[cp];
            mp[cp]++  ;  
        }
        cout<<sum<<endl;
    }
    return 0;
}