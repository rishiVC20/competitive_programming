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
        string s;
        cin>>s;  
        map<char,ll>mp;
        for (ll i=0; i<4*n; i++){
            mp[s[i]]++;
        }     
        ll sum = 0;
        // for (auto i:mp){
            if (mp.find('A') != mp.end()){
                if (mp['A'] >= n){
                    sum += n;
                }
                else{
                    sum += mp['A'];
                }
            }
            if (mp.find('B') != mp.end()){
                if (mp['B'] >= n){
                    sum += n;
                }
                else{
                    sum += mp['B'];
                }
            }
            if (mp.find('C') != mp.end()){
                if (mp['C'] >= n){
                    sum += n;
                }
                else{
                    sum += mp['C'];
                }
            }
            if (mp.find('D') != mp.end()){
                if (mp['D'] >= n){
                    sum += n;
                }
                else{
                    sum += mp['D'];
                }
            }

            cout<<sum<<endl;
            
        // }
    }
    return 0;
}