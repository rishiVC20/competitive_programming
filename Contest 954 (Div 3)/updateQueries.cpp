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
        string s; 
        cin>>s;
        vi a;
        for (ll i=0; i<m; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }         
        string c; 
        cin>>c;
        sort(c.begin(),c.end());
        sort(a.begin(),a.end());
        // multimap<ll,ll>mp;
        map<ll,ll>mp;
        // cout<<c<<' ';
        for (ll i=0; i<m; i++)
        {
            // mp.insert({a[i],c[i]});
            // if (mp[a[i]])
            mp[a[i]] = 0;
        }
        for (ll i=0; i<m; i++)
        {
            if (mp[a[i]] == 0)
                mp[a[i]] = c[i];
        }
        ll j = 0;
        // for (ll i=0; i<m; i++)
        // {
        //     if (mp.find(a[i]) != mp.end()){
        //         // if (c[j] < ){
        //             s[a[i]-1] = c[j];
        //             j++;
        //         // }
        //         cout<<s<<' ';
        //     }
        // }
        map<ll,bool>b;
        for (ll i=0; i<m; i++){
            b[a[i]] = false;    
        }
        for (ll i=0; i<m; i++){
            if (b[a[i]]==false){
                s[a[i]-1] = c[j];
                j++;
                b[a[i]] = true;
            }
        }

        cout<<s<<endl;
    }
    return 0;
}