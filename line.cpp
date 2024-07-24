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
        string s;
        cin>>s;
        vi a;
        for (ll i=0; i<n; i++){
            if (s[i]=='L')
                a.pb(i);
            else
                a.pb(n-(i+1));    
        }       
        // for (auto i:a)
        //     cout<<i<<' ';
        ll sum = accumulate(a.begin(),a.end(),0);
        ll p = sum;
        vi b;
        for (ll i=0; i<n; i++){
            p = sum;
            if (s[i]=='L'){
                p -= a[i];
                p += n-(i+1);
            }
            else{
                p-= a[i];
                p+= i;
            }
            cout<<p<<' ';
        }
        cout<<endl;
        // for (auto i:)
    }
    return 0;
}