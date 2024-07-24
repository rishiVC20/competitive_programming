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
        bool f = true;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
            if (i!=0 && a[i]!=a[i-1]){
                f = false;
            }
        }       
        if (f){
            NO;
            continue;
        }
        vector<pair<ll,ll>>v;
        vector<bool>vis(n,false);
        // for (ll i=0; i<n-1; i++){
        ll i = 0;
        vis[i] = true;
        ll p = -1;
        bool q = false;
        for (ll j=i+1; j<n; j++){
            if (a[i] != a[j]){
                v.pb({i+1,j+1});
                vis[j] = true;
            }   
            // else{
            //     p = j;
            //     q = true;
            // }
            // if (q && j==n-2)    
            //     break;
        }
        // if (v.size()){
        //     NO;
        //     continue;
        // }

        for (ll i=0; i<n; i++){
            if (!vis[i]){
                // v.pb({p+1,i+1});
                for (ll j=0; j<n; j++){
                    if (a[i]!=a[j] && vis[j]){
                        v.pb({i+1,j+1});
                        break;
                    }
                }
            }
        }
        YES;
        for (auto i:v){
            if (i.first != i.second)
                cout<<i.first<<' '<<i.second<<endl;
        }
    }
    return 0;
}