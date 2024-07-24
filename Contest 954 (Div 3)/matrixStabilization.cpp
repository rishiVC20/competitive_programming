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

vi p1 = {0,0,1,-1};
vi p2 = {1,-1,0,0};
void check (ll a, ll i, ll j, vector<vector<ll>> &v, ll n, ll m)
{
    vi k;
    if (i+p1[0]>=0 && i+p1[0]<n && j+p2[0]>=0 && j+p2[0]<m)
        k.pb(v[i+p1[0]][j+p2[0]]);
    if (i+p1[1]>=0 && i+p1[1]<n && j+p2[1]>=0 && j+p2[1]<m)
        k.pb(v[i+p1[1]][j+p2[1]]);
    if (i+p1[2]>=0 && i+p1[2]<n && j+p2[2]>=0 && j+p2[2]<m)
        k.pb(v[i+p1[2]][j+p2[2]]);
    if (i+p1[3]>=0 && i+p1[3]<n && j+p2[3]>=0 && j+p2[3]<m)
        k.pb(v[i+p1[3]][j+p2[3]]);   
    k.pb(a);
    ll s = k.size();
    if (s==1)
        return;
    sort(k.begin(),k.end());
    if (k[s-1]==a && k[s-1]!=k[s-2]){
        v[i][j] = k[s-2];
    }                 
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>a(n,vector<ll>(m));       
        for (ll i=0; i<n; i++)
        {
            for (ll j=0; j<m; j++)
            {
                ll x; cin>>x;
                a[i][j] = x;
            }
        }

        for (ll i=0; i<n; i++)
        {
            for (ll j=0; j<m; j++)
            {
                check(a[i][j],i,j,a,n,m);
            }
        }

        for (ll i=0; i<n; i++)
        {
            for (ll j=0; j<m; j++)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }

    }
    return 0;
}