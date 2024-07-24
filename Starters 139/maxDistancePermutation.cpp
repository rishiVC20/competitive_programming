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
        for (ll i=1; i<=n; i++)
            cout<<i<<' ';
        cout<<endl;
        if (n==1){
            cout<<1<<endl;
            continue;
        }
        vi a;
        // for (ll i=1; i<=n; i++)
        //     a.pb(i);
        // ll i=0, j=1;
        // while (i<n && j<n){
        //     swap(a[i],a[j]);
        //     i+=2, j+=2;
        // }       
        // if (n%2){
        //     swap(a[0],a[n-1]);
        // }
        // for (ll i=0; i<n; i++)
        //     cout<<a[i]<<' ';
        for (ll i=(n/2)+1; i<=n; i++)
            cout<<i<<' ';
        for (ll i=1; i<=(n/2); i++)
            cout<<i<<' ';    
        cout<<endl;               
    }
    return 0;
}