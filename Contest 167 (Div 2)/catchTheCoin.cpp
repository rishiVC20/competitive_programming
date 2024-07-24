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
    ll n;
    cin>>n;
    for (ll i=0; i<n; i++)
    {
        ll x,y;
        cin>>x>>y;
        if (y>=-1){
            YES;
            // continue;
        }
        else{
            NO;
        }
        // ll p = abs(x);
        // bool f = false;
        // ll j = 0;
        // while (p>0){
        //     j--;
        //     if (j==y){
        //         f = true;
        //         break;
        //     }
        //     y--;
        //     // cout<<j<<' '<<y<<' ';
        //     p--;
        // }
        // if (f)
        //     YES;
        // else
        //     NO;    
    }
    return 0;
}