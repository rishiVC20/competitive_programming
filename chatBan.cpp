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
    vi pre(1e6);
    for (ll i=0; i<1e6; i++){
        pre[i] = 2*i-1;
    }
    for (int i=0; i<10; i++){
            cout<<pre[i]<<' ';
        }
    while (t--)
    {   
        ll k,x;
        cin>>k>>x;
        
        ll cp = lower_bound(pre.begin(),pre.end(),x)-pre.begin();
        // cp--;
        // cout<<cp<<' ';
        // if (pre[cp] <= x){
        //     cout<<cp<<endl;
        // }
        // else{
        //     while (pre[cp] > x){
        //         cp--;
        //     }
        //     cout<<cp<<endl;
        // }
        cout<<cp<<endl;
    }
    return 0;
}