// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

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
        bool c = 0;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
            c += (x==1);
        }       
        if (c){
            cout<<"YES"<<endl;
            continue;
        }
        vi b;
        sort(a.begin(),a.end());
        bool f = true;
        for (ll i=n-1; i>=0; i--)
        {
            if (a[i]%a[0]==0)
                continue;
            else{
                f = false;
                b.pb(a[i]);
            }    
        }
        if (f){
            cout<<"YES"<<endl;
            continue;
        }
        ll m = b.size();
        if (m==1){
            cout<<"YES"<<endl;
            continue;
        }   
        sort(b.begin(),b.end());
        bool k = true;
        for (ll i=1; i<m; i++){
            if (b[i]%b[0]){
                k = false;
                break;
            }
        }   

        if (k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
    }
    return 0;
}