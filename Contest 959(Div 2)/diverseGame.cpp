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
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>a(n,vector<ll>(m));
        vector<vector<ll>>b(n,vector<ll>(m));
        for (ll i=0; i<n; i++){
            for (ll j=0; j<m; j++){
                cin>>a[i][j];
            }
        }

        for (ll i=0; i<n; i++){
            for (ll j=0; j<m; j++){
                b[i][j] = a[i][j]+1;
                if (b[i][j] > n*m){
                    b[i][j] = 1;
                }
            }
        }

        if (a==b){
            cout<<-1<<endl;
        }
        else{
            for (ll i=0; i<n; i++){
                for (ll j=0; j<m; j++){
                    cout<<b[i][j]<<' ';
                    
            }
            cout<<endl;
            }
        // cout<<endl;
        }

    }
    return 0;
}