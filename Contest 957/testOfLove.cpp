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

ll check (string s,ll i, ll m){
    ll n = s.size();
    ll cn = 0;
    ll j = -1;
    while (i+1<n && cn <m){
        if (s[i+1]=='L'){
            j = i+1;
        }
        if (j==-1 &&s[i+1]=='W'){
            j = i+1;
        }
        i++;
        cn++;
    }
    if (cn<m){
        return n;
    }
    return j;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        string s;
        cin>>s;
        ll q = s.size();
        ll v = 0;
        // for (ll i=0; i<q; i++){
        //     if (s[i]=='W')
        //         v++;
        // }
        // if (v>k){
        //     NO;
        //     continue;
        // }
        ll z = -1;
        bool f= true;
        // ll j = check(s,0,m);
        // if (j==-1){
        //     NO;
        //     continue;
        // }
        // while (z<q){
        //     // k++;
            
        //     ll p = check(s,z,m);
        //     cout<<p<<' ';
        //     if (p==n)
        //         break;
        //     if (p==-1){
        //         f = false;
        //         break;
        //     }
        //     if (s[p]=='W')
        //         v++;
        //     z = p;
        // }
        ll j = m-1;
        for (ll i=0; i<q; i++){
            if (s[i]=='L'){
                j = m;
            }
            if (s[i]=='W'){
                // v++;
                if (j<=0){
                    v++;
                }
            }
            else if (j<=0){
                f=false;
                break;
            }
            j--;
        }
        if (v>k){
            NO;
            continue;
        }
        if (f)
            YES;
        else
            NO;    
    }
    return 0;
}