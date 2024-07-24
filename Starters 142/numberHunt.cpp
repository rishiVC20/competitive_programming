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

bool prime(ll x){
    for (ll i=2; i<x; i++)
    {
        if (x%i==0)
            return false;
    }

    return true;
}
bool sq(ll x){
    for (ll i=1; i*i<=x; i++){
        if (i*i == x)
            return true;
    }

    return false;
}

bool check(ll x){
    for (ll i=5; i*i<=x; i+=6){
        if (x%i == 0)
            return true;
    }

    return false;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll x; cin>>x;
        if (x==1){
            cout<<6<<endl;
            continue;
        }
        if (x==2){
            cout<<6<<endl;
            continue;
        }
        if (x==3){
            cout<<15<<endl;
            continue;
        }
        // if (x%2==0){
        //     cout<<x*(x+1)<<endl;
        // }
        // else{
        //     cout<<x*(x+2)<<endl;
        // }
        bool f = false;
        ll k = x+1;
        // while (1){
        //     if (prime(k)==true || sq(k)==true){
        //         cout<<'j'<<' '; 
        //         k++;
        //         continue;
        //     }
        //     cout<<k<<' ';
        //     if (__gcd(x,k) == x || __gcd(x,k) == 1){
        //         cout<<k<<endl;
        //         break;
        //     }
        //     k++;
        // }

        ll c = 0;
        vi b;
        while (1){
            if (k%2==0 || k%3==0){
                k++;
                continue;
            }
            
            if (check(k)){
                b.pb(k);
                b.pb(k+6);
                break;
            }
            k++;
        }

        cout<<b[0]*b[1]<<endl;

    }
    return 0;
}