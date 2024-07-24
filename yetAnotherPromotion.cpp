// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define vi vector<ll> 

const ll mod = 1e9+7;
__builtin_popcountll(x)
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
        ll a,b;
        cin>>a>>b;
        ll n,m;
        cin>>n>>m;
        if (n <= m){
            cout<<n*min(a,b)<<endl;
            continue;
        }       
        ll k1 = n*b;
        ll k2 = n/(m+1);
        ll k3 = n%(m+1);
        ll sum = k2*a*m + k3*min(a,b);
        cout<<min(k1,sum)<<endl;
    }
    return 0;
}