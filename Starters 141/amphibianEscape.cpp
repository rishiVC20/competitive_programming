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
        ll n,k,h;
        cin>>n>>k>>h;
        ll sum = 0;
        vi a;
        for (ll i=1; i<=n; i++){
            a.pb(i);
        }
        if (n>=h)
            sum += (n-h+1)*n;
        cout<<sum<<' ';    
        if (n < h){
            cout<<0<<endl;
            continue;
        }
        for (ll i=1; i<min(h,n); i++)
        {
            // for (ll j=1; j<=k; j++)
            // {
            //     ll p = abs(i-j);
            //     if (p*k >= h){
            //         sum++;
            //         // cout<<i<<' '<<j<<' ';
            //     }
            // }
            // ll p = i-ceil(h/k);
            // cout<<p<<' ';
            // if (p>0){
            //     sum += p;
            // }

            ll j = upper_bound(a,begin,a.end(),(i-1)*k);
            
        }

        cout<<sum<<endl;
    }
    return 0;
}