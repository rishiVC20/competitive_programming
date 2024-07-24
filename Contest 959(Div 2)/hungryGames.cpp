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
        ll n,x;
        cin>>n>>x;
        ll cp = 0;
        ll cd = 0;
        vi a;
        vi pre;
        for (ll i=0; i<n; i++){
            ll k; cin>>k;
            a.pb(k);
            if (i==0){
                pre.pb(k);
            }
            else{
                pre.pb(a[i-1]+k);
            }
            if (k<=x)
                cd++;
        }       
        if (cd==0){
            cout<<0<<endl;
            continue;
        }
        // cout<<cp<<' ';
        for (ll i=0; i<n; i++){
            // ll ck = a[i];
            ll ck = 0;
            ll j = i;
            while (j<n){
                ll h = upper_bound(pre.begin(),pre.end(),a[j]+x)-pre.begin();
                h--;
                cp += (h-j + 1);
                j = h;
            }
            // cout<<cp<<' ';
        }

        cout<<cp<<endl;
    }
    return 0;
}