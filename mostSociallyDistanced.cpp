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
        ll q=n+1,p=-1;
        for (ll i=0; i<n; i++){
            if (a[i]==1){
                q=i;
            }
            if (a[i]==n)
                p=i;
        }
        // if (abs(p-q)==n-1 && n>3){
        //     cout<<n<<endl;
        //     for (auto i:a)
        //         cout<<i<<' ';
        //     cout<<endl;
        //     continue;    
        // }
        vi b;
        for (ll i=0; i<n; i++){
            if (i==p){
                b.pb(n);
                continue;
            }
            if (i==q){
                b.pb(1);
                continue;
            }
            if (i==0 || i==n-1){
                b.pb(a[i]);
                continue;
            }
            if (i>0 && i<n-1){
                if (a[i]>a[i-1] && a[i]>a[i+1]){
                    b.pb(a[i]);
                }
                if (a[i]<a[i-1] && a[i]<a[i+1]){
                    b.pb(a[i]);
                }
            }
               
        }
        cout<<b.size()<<endl;
        for (auto i:b)
            cout<<i<<' ';
        cout<<endl; 
    }
    return 0;
}