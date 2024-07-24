// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
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
bool check(ll mid, vi &a, ll c, ll d)
{
    ll score=0, n=a.size();
    for (ll i=0; i<d; i++)
    {
        if (i%mid < n)
            score += a[i%mid];
    }

    return score >= c;
}

int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,c,d;
        cin>>n>>c>>d;
        vi a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        sort(a.rbegin(),a.rend());
        ll l=1, r=d+2;
        ll re = -1;
        while (l <= r)
        {
            ll mid = l+(r-l)/2;
            if (check(mid,a,c,d)){
                l = mid+1;
                re = mid-1;
            }
            else{
                r = mid-1;
            }
        }

        if (re >= d)
            cout<<"Infinity"<<endl;
        else if (re==-1)
            cout<<"Impossible"<<endl;
        else
            cout<<re<<endl;         
    }
    return 0;
}