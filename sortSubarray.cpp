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
        vi a,b;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            b.pb(x);
        }

        ll maxi = 0;
        ll curr = 1;
        ll ans = 0;
        ll k = -1;
        ll l = -1;
        bool f = true;
        for (ll i=0; i<n; i++){
            // ans = maxi;
            if (a[i] != b[i]){
                k = i;
                if (l==-1)
                    l = i;
            }
        }
        // cout<<k<<' ';
        // cout<<maxi<<' ';
        
        // cout<<l<<' '<<k<<' ';
        while (l>0 && b[l-1]<=b[l])
            l--;
        while (k<n-1 && b[k+1]>=b[k])
            k++;

        cout<<l+1<<' '<<k+1<<endl;        
    }
    return 0;
}

//3 4