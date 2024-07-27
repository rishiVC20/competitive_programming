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
        vector<vector<char>>a(n,vector<char>(n));     
        for (ll i=0; i<n; i++){
            for (ll j=0; j<n; j++){
                char x; cin>>x;
                a[i][j] = x;
            }
        } 
        ll t = n/k;
        vector<vector<char>>b(t,vector<char>(t));
        ll h=0;
        // for (ll i=0; i<n; i+=t){
        //     ll k = 0;
        //     for (ll j=0; j<n; j+=t){
        //         b[h][k] = a[i][j];
        //         k++;
        //     }
        //     h++;
        // }
        for (ll i = 0; i < t; i++) {
            for (ll j = 0; j < t; j++) {
                b[i][j] = a[i * k][j * k];
            }
        }
        for (ll i=0; i<t; i++){
            for (ll j=0; j<t; j++){
                cout<<b[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}