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
        ll n;cin>>n;
        vi a,b,kk(n);
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
            kk[n-i-1]=x;
        }       
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            b.pb(x);
        }
        ll p,q;
        bool f=true;
        // for (ll i=1; i<n; i++){
        //     a[n-i]=a[i];
        //     if (a[i]==1)
        //         p=i;
        //     if(b[i]==1)
        //         q=i;    
        // }
        // ll i=n-1, j=n-1;
        // ll l=0,r=0;
        for (ll i=0; i<n; i++){
            if (a[i]!=b[i]){
                f=false;
                break;
            }
        }
        // for (auto i:kk)
        //     cout<<i<<' ';
        if (!f){
            f=true;
            for (ll i=0; i<n; i++){
                if (kk[i]!=b[i]){
                    f=false;
                    break;
                }
            }
        }
        
        
        // while (l<=j){
        //     if (a[l]!=b[j] && b[l]!=a[j] && a[l]!=b[l] && a[j]!=b[j]){
        //         // cout<<'k';
        //         f=false;
        //         break;
        //     }
        //     i--, j--;
        //     l++, r++;
        // }
        if (!f)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;    

    }
    return 0;
}