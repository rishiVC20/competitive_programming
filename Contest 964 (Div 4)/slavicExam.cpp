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
        string a,b;
        cin>>a>>b;
        ll n=a.size();
        ll m=b.size();
        bool f=true;
        for (ll i=0; i<n; i++){
            if (a[i]=='?'){
                f=false;
                break;
            }
        } 
        map<char,ll>mp;
        for (ll i=0; i<n; i++){
            mp[a[i]]++;
        }
        ll i=0, j=0;
        vector<char>d;
        while (i<m && j<n){
            if (a[j]==b[i]){
                i++;
            }
            else if (a[j]=='?'){
                d.push_back(b[i]);
                i++;
            }
            j++;
        }
        if (i==m){
            YES;
            ll g=d.size();
            ll u=0;
            if (g>0){
                for (ll i=0; i<n; i++){
                    if (a[i]=='?'){
                        a[i]=d[u];
                        u++;
                        if (u==g)
                            break;
                    }
                }
            }
            for (ll i=0; i<n; i++){
                if (a[i]=='?'){
                    a[i]='a';
                }
            }
            cout<<a<<endl;
        }
        else{
            NO;
        }
    }
    return 0;
}