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
        vi a(n+1,0);
        for (ll i=1; i<=n; i++){
            ll x;cin>>x;
            a[i]=x;
        }       
        string k="$";
        string s;cin>>s;
        k+=s;
        vi pre(n+1,0);
        vi c,d;
        for (ll i=1; i<=n; i++){
            pre[i] = pre[i-1]+a[i];
            if (k[i]=='L')
                c.pb(i);
            if (k[i]=='R')
                d.pb(i);    
        }
        // for (auto i:c)
        //     cout<<i<<' ';
        // cout<<endl;    
        // for (auto i:d)
        //     cout<<i<<' ';    
        reverse(d.begin(),d.end());
        
        ll cn=0;
        ll i=0, j=0;
        while (i<c.size() && j<d.size()){
            if (c[i]>d[j])
                break;
            cn += pre[d[j]]-pre[c[i]-1];
            i++;
            j++;    
        }

        cout<<cn<<endl;
    }
    return 0;
}