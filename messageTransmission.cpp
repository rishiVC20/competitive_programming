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
    ll t=1;
    // cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        ll n=s.size();
        bool f=false;
        string g;
        for(ll i=0; i<n; i++){
            for(ll j=1; j<=i; j++){
                string k=s.substr(j,i-j+1);
                string p=s.substr(i+1);
                // cout<<k<<' '<<p<<' ';
                if(k==p){
                    f=true;
                    g=s.substr(0,j)+k;
                    break;
                }    
            }
            if(f)
                break;
        }
        if(f){
            YES;
            cout<<g<<endl;
        }
        else{
            NO;
        }
    }
    return 0;
}