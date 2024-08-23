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
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }
        ll p=0,q=1;
        bool f=false;
        while(1){
            ll i=p,j=q;
            ll s1=0,s2=0;
            while(i<n || j<n){
                s1 += a[i];
                if(s1==s2){
                    f=true;
                    break;
                }
                if(j>=n)
                    break;
                s2 += a[j];
                if(s1==s2){
                    f=true;
                    break;
                }
                i+=2,j+=2;
            }
            // cout<<i<<' '<<j<<' ';
            if(f){
                break;
            }
            p++,q++;
            if(p==n || q== n)
                break;
        }    
        if(f)
            YES;
        else
            NO;    
    }
    return 0;
}

/*
YES
YES
NO
YES
NO
YES
*/