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
        vi a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        sort(a.begin(),a.end());
        ll g = a[n-1];
        ll sum=INT_MIN;
        for (ll i=g; i<g+k; i++){
            bool f=true;
            for (ll j=0; j<n; j++){
                if ((i-a[j])%(2*k) >= k){
                    f=false;
                    break;
                }
            }
            if (f){
                sum=i;
                break;
            }
        }
        if (sum==INT_MIN){
            cout<<-1<<endl;
        }
        else{
            cout<<sum<<endl;
        }
        
        // for (ll i=0; i<n; i++){
        //     for (ll j=i+1; j<n; j++){
        //         ll p = abs(a[j]-a[i]);
        //         // ll p = LCM(a[j],a[i]);
        //         if (p%k == 0){
        //             sum = max(a[i],a[j]);
        //         }
        //     }
        // }       
        // if (sum==INT_MIN)
        //     cout<<-1<<endl;
        // else
        //     cout<<sum<<endl;    
    }
    return 0;
}