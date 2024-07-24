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
        ll mini = INT_MAX;
        bool f = true;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
            mini = min(mini,x);
            if (i>0 && a[i] < a[i-1]){
                f = false;
            }
        }
        // if (f){
        //     ll sum = 0;
        //     for (ll i=n-1; i>=0; i--){
        //         sum += a[i];
        //     }
        //     cout<<sum<<endl;
        //     continue;
        // }
        // cout<<mini<<' ';
        ll sum = 0;
        ll maxi  = INT_MIN;
        // for (ll i=n-1; i>=0; i--){
        //     // maxi = max(maxi,a[i]);
        //     // if (a[i]>maxi){
        //     //     sum += a[i];
        //     //     maxi = a[i];
        //     // }
        //     // else if (a[i] > 0)
        //     //     sum++;
        //     sum = max(a[i]-mini,sum);
        // }
        ll p = 0;
        for (ll i=0; i<n; i++){
            if (a[i]+p > sum){
                sum = a[i]+p;
            }
            p++;
        }
        // sum += mini;
        cout<<sum<<endl;
    }
    return 0;
}