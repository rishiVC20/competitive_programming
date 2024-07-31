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
        string p,q;
        cin>>p>>q;
        vector<vector<ll>>a(2,vector<ll>(n,0));
        for (ll i=0; i<n; i++){
            if (p[i]=='x')
                a[0][i] = 1;
            if (q[i]=='x')
                a[1][i] = 1;    
        }
        ll sum = 0;
        for (ll i=1; i<n-1; i++){
            if (a[0][i]==0){
                if (a[1][i-1]==1 && a[1][i+1]==1 && a[1][i]==0 && a[0][i-1]==0 && a[0][i+1]==0){
                    sum++;
                }
            }
            if (a[1][i]==0){
                if (a[0][i-1]==1 && a[0][i+1]==1 && a[0][i]==0 &&  a[1][i-1]==0 && a[1][i+1]==0){
                    sum++;
                }
            }
        }

        cout<<sum<<endl;
    }
    return 0;
}