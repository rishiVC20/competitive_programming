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
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        bool f=true;
        bool h=true;
        for (ll i=0; i<n; i++){
            if (a[i]!=0)
                h=false;
            else
                f=false;    
        }
        vi k(n), q(n);
        k[0]=a[0];
        for (ll i=1; i<n; i++){
            k[i]=k[i-1]+a[i];
        }
        q[n-1]=a[n-1];
        for (ll i=n-2; i>=0; i--){
            q[i] = q[i+1]+a[i];
        }
        // for (auto i:a)
        //     cout<<i<<' ';
        // cout<<endl;
        // for (auto i:k)
        //     cout<<i<<' ';
        // cout<<endl;    
        // for (auto i:q)
        //     cout<<i<<' ';    
        ll sum=0;
        ll ss=0;
        for (ll i=0; i<n; i++){
            if (a[i]==0){
                    // sum += abs(q[i]-k[i]);
                    if (abs(q[i]-k[i])==0){
                        sum+=2;
                    }
                    if (abs(q[i]-k[i])==1){
                        // cout<<'k';
                        sum++;
                    }
            }
        }
        // if (!f ){
        //     sum += ss*2;
        // }
        cout<<sum<<endl;
        // bool f=true;
        // bool h=true;
        // ll sum=0;
        // for (ll i=0; i<n; i++){
        //     if (a[i]!=0)
        //         h=false;
        //     else
        //         f=false;    
        // }
        // ll s1=0;
        // ll s2=0,m=0;
        // f=true;
        // for (ll i=0; i<n; i++){
        //     if (f &&a[i]!=0){
        //         s1 += a[i];
        //     }
        //     if (!f && a[i]!=0){
        //         s2 += a[i];
        //     }
            
        // }
        // if (abs(s1-s2)==1){
        //     cout<<m<<endl;
        // }
        // else{
        //     cout<<2*m<<endl;
        // }
    }
    return 0;
}