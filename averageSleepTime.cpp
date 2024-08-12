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
        double n,k;
        cin>>n>>k;
        vector<double> a;
        for (ll i=0; i<n; i++){
            double x; cin>>x;
            a.pb(x);
        }       
        vector<double> b;
        vector<double> pre(n);
        pre[0] = a[0];
        for (ll i=1; i<n; i++){
            pre[i] = pre[i-1]+a[i];
        }
        double qq = 0;
        qq += pre[k-1];
        double t=0;
        for (ll i=k; i<n; i++){
            qq += (pre[i]-pre[t]);
            t++;
        }
        double p=n-k+1;
        // cout<<qq<<' ';
        qq = qq/p;
        cout<<fixed<<setprecision(6)<<qq<<endl;
    return 0;
}