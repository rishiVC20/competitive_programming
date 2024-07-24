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
        ll n,a,b;
        cin>>n>>a>>b;
        ll diff = b-a;
        // cout<<diff<<' ';
        if (diff <= 0){
            cout<<n*a<<endl;
            continue;
        }       
        ll sum = 0;
        if (diff >= n){
            ll q = b-n;
            // cout<<q<<' ';
            sum += b*(b+1)/2 - q*(q+1)/2;
            cout<<sum<<endl;
            continue;
        }
        
        ll p = b-diff;
        // cout<<p<<' ';
        sum += b*(b+1)/2 - p*(p+1)/2;
        if (n-diff > 0)
            sum += (n-diff)*a;

        cout<<sum<<endl;
    }
    return 0;
}