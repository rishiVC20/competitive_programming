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
        ll n,s;
        cin>>n>>s;
        vi a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }       
        vi pre(n);
        pre[0] = a[0];
        for (ll i=1; i<n; i++){
            pre[i] = pre[i-1] + a[i];
        }
        if (accumulate(a.begin(),a.end(),0) < s){
            cout<<-1<<endl;
            continue;
        }
        if (accumulate(a.begin(),a.end(),0) == s){
            cout<<0<<endl;
            continue;
        }
        ll lo=0, hi=n-1;
        ll x,y;
        // while (lo <= hi)
        // {
        //     ll mid = (lo+hi)/2;
        //     if (pre[mid]==s){
        //         x = lo, y=hi;
        //         break;
        //     }
        //     else if (pre[mid] > s)
        //         hi = mid-1;
        //     else
        //         lo = mid+1;    

        // }

        // x = lower_bound(pre.begin(),pre.end(),1)-pre.end();
        // y = lower_bound(pre.begin(),pre.end(),s)-pre.end();

        ll ans = INT_MAX;
        for (ll i=1; i<n; i++)
        {
            ll cc = pre[i-1]+s;
            if (pre[n-1] < cc)
                continue;
            ll x = upper_bound(pre.begin(),pre.end(),cc)-pre.begin();
            x--;
            // cout<<x<<' ';
            ans = min(ans,n-(x-i+1));    
        }
        //starting from 0
        ll cp = upper_bound(pre.begin(),pre.end(),s)-pre.begin();
        cp--;
        ans = min(ans,n-(cp+1));

        cout<<ans<<endl;
    }
    return 0;
}