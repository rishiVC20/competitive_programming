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
    vi a(501);
    a[0] = 0;
    a[1] = 2;
    ll pp = 3;
    for (ll i=2; i<501; i++)
    {
        a[i] = a[i-1] + pp;
        pp++;
    }
    // for (ll i=0; i<=10; i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;    
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        // ll p = lower_bound(a.begin(),a.end(),n) - a.begin();
        // if (p>n)
        //     p--;
        // cout<<p<<endl;
        // if (p==k){
        //     cout<<"YES"<<endl;
        // }
        // else{
        //     cout<<"NO"<<endl;
        // }
        if ((n==1 && k==1) || (n==2 && k==1)){
            cout<<"YES"<<endl;
            continue;
        }
        
        // if (a[p] != n){
        //     p--;
        //     cout<<'j'<<' '
        // }
        ll  ii = k*(k+1)/2;
        ii += k-1;
        cout<<ii<<' ';
        if (ii <= n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
        // cout<<a[p] <<' ';    
        // cout<<p<<' ';   

        // if (p==k)
        //     cout<<"YES"<<endl;
        // else
        //     cout<<"NO"<<endl;        
    }
    return 0;
}