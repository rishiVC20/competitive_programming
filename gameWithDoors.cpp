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
        ll x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        if(x2<y1 || y2<x1){
            cout<<1<<endl;
            continue;
        }
        vi v(101,0);
        for(ll i=x1; i<=x2; i++){
            v[i]++;
        }       
        for(ll i=y1; i<=y2; i++){
            v[i]++;
        }       
        ll cn=0;
        for(ll i=0; i<100; i++){
            if(v[i]==1 && v[i+1]==2){
                cn++;
            }
            if(v[i]==2 && v[i+1]>=1){
                cn++;
            }
        }

        cout<<cn<<endl;
    }
    return 0;
}