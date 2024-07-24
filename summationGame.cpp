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
        ll n,k,x;
        cin>>n>>k>>x;
        vi a;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }
        sort(a.begin(),a.end());
        vi pre(n);
        pre[0] = a[0];
        for (ll i=1; i<n; i++)
        {
            pre[i] = pre[i-1]+a[i];
        }
        ll sum = INT_MIN;
        ll j = n-1;
        for (ll i=0; i<=k; i++)
        {   
            // cout<<pre[j]<<' '<<pre[j-x]<<'h'<<' ';
            // ll ans = 0;
            // cout<<j-x<<' ';
            if (j-x>=0){
                ll ans = pre[j] - 2*(pre[j] - pre[j-x]);
                sum = max(sum,ans);
            }
            else if (j>=0){
                ll ans = -1*pre[j];
                sum = max(sum,ans);
                // if (sum < 0){
                //     sum = 0;
                // }
                // break;
            }
            // cout<<sum<<' ';
            // if (j== 0)
            //     break;
            j--;
        }
        if (sum<0 && k>=n){
            sum = 0;
        }
        // if (sum == INT_MIN)
        //     sum = 0;
        cout<<sum<<endl;
    }
    return 0;
}