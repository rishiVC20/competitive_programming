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
        ll n,k;
        cin>>n>>k;
        if (n==3 && k==3){
            cout<<1<<' '<<1<<' '<<1<<endl;
            continue;
        }
        if (n%k==0 ){
            // cout<<n/k<<' '<<n/k<<' '<<n/k<<endl;
            for (ll i=0; i<k; i++)
                cout<<n/k<<' ';
            cout<<endl;    
            continue;
        }
        // ll q = k-3;
        // ll x = k-q;
        n = n-(k-3);     
        ll p = n/2;
        
        if (p*2>=n && p%2==1) 
            p--;
        // cout<<p<<' ';    
        vi a;
        a.pb(p);
        if (2*p < n){
            a.pb(p);
            a.pb(n-2*p);
        }    
        else{
            a.pb(p/2);
            a.pb(n-(p+p/2));
        }

        for (auto i:a)
            cout<<i<<' ';   

        for (ll i=0; i<k-3; i++)
            cout<<1<<' ';
        cout<<endl;    
   }
    return 0;
}