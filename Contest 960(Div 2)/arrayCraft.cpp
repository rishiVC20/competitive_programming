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
        ll n,x,y;
        cin>>n>>x>>y;
        vi a(n+1,-1);
        for (ll i=y; i<=x; i++){
            a[i]=1;
        }
        // for (auto i:a)
        //  cout<<i<<' ';
        ll k = -1;
        for (ll i=y-1; i>=1; i--){
            a[i]=k;
            k = k*(-1);
        }
        ll p = -1;
        for (ll i=x+1; i<=n; i++){
            a[i]=p;
            p *= (-1);
        }   
        for (ll i=1; i<=n; i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}