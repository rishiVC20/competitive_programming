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
        vector<vector<char>>a(n,vector<char>(m));       
        vector<vector<char>>b(n,vector<char>(m));

        for(ll i=0; i<n; i++){
            for (ll j=0; j<m; j++){
                cin>>a[i][j];
            }
        }

        for(ll i=0; i<n; i++){
            for (ll j=0; j<m; j++){
                cin>>b[i][j];
            }
        }       
        for (ll i=0; i<n-1; i++){
            for (ll j=0; j<m-1; j++){
                ll diff = (b[i][j]-a[i][j] + 3)%3;
                if (diff==0)
                    continue;
                else if (diff==1){
                    a[i][j] = (a[i][j]-'0' + 1)%3+'0';
                    a[i+1][j+1] = (a[i+1][j+1]-'0' + 1)%3+'0';
                    a[i][j+1] = (a[i][j+1]-'0' + 2)%3 + '0';
                    a[i+1][j] = (a[i+1][j]-'0' + 2)%3 + '0';
                }
                else if (diff==2){
                    a[i][j] = (a[i][j]-'0' + 2)%3+'0';
                    a[i+1][j+1] = (a[i+1][j+1]-'0' + 2)%3+'0';
                    a[i][j+1] = (a[i][j+1]-'0' + 1)%3 + '0';
                    a[i+1][j] = (a[i+1][j]-'0' + 1)%3 + '0';
                }    
            }
        }

        if (a==b)
            YES;
        else
            NO;    
    }
    return 0;
}