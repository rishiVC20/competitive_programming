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
        ll n,k;
        cin>>n>>k;
        vi a;
        ll p=0;
        ll q=0;
        for (ll i=0; i<k; i++){
            ll x; cin>>x;
            a.pb(x);
            // if (x==1){
            //     q++;
            // }
            
        }       

        sort(a.begin(),a.end());
        // p--;
        // if (p<0){
        //     cout<<q-1<<endl;
        //     continue;
        // }
        ll cn = 0;
        for (ll i=0; i<k-1; i++){
            if (a[i]!=1){
                p+=a[i];
                cn+=a[i]-1;
            }
            else
                q++;    
        }
        cout<<p+q+cn<<endl;
    }
    return 0;
}