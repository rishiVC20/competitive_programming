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
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
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
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }
        if (count(a.begin(),a.end(),a[0])==n){
            cout<<"NO"<<endl;
            continue;
        }       

        cout<<"YES"<<endl;
        cout<<"R";
        ll i = 1, j = 2;
        ll cn = 1;
        while (a[i] ==  a[j] && j<n){
            cout<<"R";
            cn++;
            i++;
            j++;
        }

        for (ll i=0; i<n-cn; i++)
            cout<<"B";
        cout<<endl;    
    }
    return 0;
}

/*
YES
RBRR
YES
BBRBB
NO
YES
RBBR
YES
RRB
YES
BRR
YES
BRB
*/