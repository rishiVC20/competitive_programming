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

vi check(vi &a, vi &b, vi &c, ll k, ll n)
{   
    vi ans;
    ll A=0, B=0, C=0;
    for (ll i=0; i<n; i++){
        A += a[i], B += b[i], C += c[i];
        ll j;
        // cout<<A<<' '<<B<<' '<<C<<endl;
        // cout<<ceil(k/3)<<' ';
        if (ans.size()==0 && A >= ((k+2)/3)){
            ans.pb(i+1);
            // j = i+2;
            A = 0, B=0, C=0;
        }
        else if (ans.size()==1 && B>=((k+2)/3)){
            // ans.pb(j);
            ans.pb(i+1);
            // j = i+2;
            A=0,B=0,C=0;
        }
        else if (ans.size()==2 && C>=((k+2)/3)){
            // ans.pb(j);
            ans.pb(i+1);
            A=0,B=0,C=0;
        }
    }

    // cout<<ans.size()<<endl;
    return ans;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vi a,b,c;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            b.pb(x);
        }
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            c.pb(x);
        }
        // ll sum = accumulate(a.begin(),a.end(),0);
        ll sum = 0;
        for (ll i=0; i<n; i++){
            sum += a[i];
        }
        // cout<<sum<<' ';
        if (check(a,b,c,sum,n).size()==3){
            vi ans = check(a,b,c,sum,n);
            cout<<1<<' '<<ans[0]<<' '<<ans[0]+1<<' '<<ans[1]<<' '<<ans[1]+1<<' '<<ans[2]<<endl;
        }
        else if (check(a,c,b,sum,n).size()==3){
            vi ans = check(a,c,b,sum,n);
            cout<<1<<' '<<ans[0]<<' '<<ans[1]+1<<' '<<ans[2]<<' '<<ans[0]+1<<' '<<ans[1]<<endl;
        }
        else if (check(b,a,c,sum,n).size()==3){
            vi ans = check(b,a,c,sum,n);
            cout<<ans[0]+1<<' '<<ans[1]<<' '<<1<<' '<<ans[0]<<' '<<ans[1]+1<<' '<<ans[2]<<endl;
        }
        else if (check(b,c,a,sum,n).size()==3){
            vi ans = check(b,c,a,sum,n);
            cout<<ans[1]+1<<' '<<ans[2]<<' '<<1<<' '<<ans[0]<<' '<<ans[0]+1<<' '<<ans[1]<<endl;
        }
        else if (check(c,a,b,sum,n).size()==3){
            vi ans = check(c,a,b,sum,n);
            cout<<ans[0]+1<<' '<<ans[1]<<' '<<ans[1]+1<<' '<<ans[2]<<' '<<1<<' '<<ans[0]<<endl;
        }
        else if (check(c,b,a,sum,n).size()==3){
            vi ans = check(c,b,a,sum,n);
            cout<<ans[1]+1<<' '<<ans[2]<<' '<<ans[0]+1<<' '<<ans[1]<<' '<<1<<' '<<ans[0]<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}