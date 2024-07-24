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
        string s,p;
        cin>>s>>p;
        ll cp = 0;
        ll f=0,h=0,v=0,u=0;
        ll kp = 0;
        ll d=0;
        for (ll i=0; i<n; i++){
            cp += (s[i]!=p[i]);
            kp += (s[i]==p[i]);
            f += (s[i]=='1');
            h += (s[i]=='0');
            v += (p[i]=='1');
            u += (p[i]=='0');
            if (s[i]!=p[i]){
                d+=s[i]-'0';
            }
        }      
        
        // if (n==1 && s[0]==p[0]){
        //     YES;
        //     continue;
        // }
        // if (n==2){
        //     if (cp==2 && k%2==1 && f==v && h==u){
        //         YES;
        //     }
        //     else if (cp==0 && k%2==0 && f==v && h==u){
        //         YES;
        //     }
        //     else
        //         NO;
        //     continue;    
        // }
        // cout<<f<<' '<<h<<' '<<v<<' '<<u<<' ';
        // cout<<cp<<' '<<kp<<' ';
        if (s==p && k%2==1 && (s=="01"||s=="10")){
            NO;
            continue;
        }
        if (cp==2 && n==2 && k%2==0){
            NO;
            continue;
        }
        if ((cp/2)<=k && cp==d*2)
            YES;
        else
            NO;        
    }
    return 0;
}