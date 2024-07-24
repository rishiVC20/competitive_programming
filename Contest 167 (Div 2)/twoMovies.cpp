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
        vi p,q;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            p.pb(x);
        } 
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            q.pb(x);
        }     
        ll u = 0;
        ll v = 0;
        for (ll i=0; i<n; i++){
            ll x = p[i];
            ll y = q[i];
            if (y > x && y==1){
                v += 1;
            }
            else if (x > y && x==1){
                u += 1;
            }
            
        }
        for (ll i=0; i<n; i++){
            ll x = p[i];
            ll y = q[i];
            if (x==y && x==1){
                if (u>v){
                    v += 1;
                }
                else{
                    u += 1;
                }
            }
            else if (x==y && x==-1)
            {
                if (u>v){
                    u+=-1;
                }
                else{
                    v += -1;
                }
            }
        }

        cout<<min(u,v)<<endl;
    }
    return 0;
}