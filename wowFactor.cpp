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
    string s;
    cin>>s;
    string p="";
    int n = s.size();
    ll curr=0;
    for (ll i=0; i<n; i++){
        if (i==0 && s[i]=='v'){
            // p += s[i];
            curr++;
            continue;
        }
        if (s[i]=='v'){
            curr++;
        }
        else{
            if (curr>0){
                for (ll j=0; j<curr-1; j++){
                    p += 'w';
                    // curr--;
                }
                if (curr==1)
                    p += 'v';
                curr=0;
            }
            p += s[i];
        }
    }
    if (curr>0){
        for (ll j=0; j<curr-1; j++){
            p += 'w';
            // curr--;
        }
        if (curr==1)
            p += 'v';
        curr=0;
    }
    ll m = p.size();
    vi a(m);
    vi b(m);
    ll cp=0;
    for (ll i=0; i<m; i++){
        if (p[i]=='w')
            cp++;
        a[i]=cp;    
    }
    ll k = 0;
    for (ll i=m-1; i>=0; i--){
        if (p[i]=='w')
            k++;
        b[i]=k;    
    }
    // for (auto i:a)
    //     cout<<i<<' ';
    // cout<<endl;    
    // for (auto i:b)
    //     cout<<i<<' ';
    ll ans = 0;
    for (ll i=0; i<m; i++){
        if (p[i]=='o'){
            // cout<<a[i]<<' '<<b[i]<<' ';
            ans += a[i]*b[i];
        }
    }
    // cout<<p<<' ';
    cout<<ans;
    return 0;
}