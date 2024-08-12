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
        vector<pair<ll,ll>>a(16);
        for (ll i=0; i<16; i++){
            ll x; cin>>x;
            a[i].first=x;
        }
        vector<pair<ll,ll>>v=a;
        sort(v.begin(),v.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
            return a.first < b.first;
        });
        v[0].second=0;
        v[1].second=1;
        v[2].second=1;
        v[3].second=2;
        v[4].second=2;
        v[5].second=2;
        v[6].second=2;
        v[7].second=3;
        v[8].second=3;
        v[9].second=3;
        v[10].second=3;
        v[11].second=3;
        v[12].second=3;
        v[13].second=3;
        v[14].second=3;
        v[15].second=4;
        for (ll i=0; i<16; i++){
            ll p = a[i].first;
            for (ll j=0; j<16; j++){
                if (v[j].first==p){
                    cout<<v[j].second<<' ';
                }
            }
        }
        cout<<endl;
    }
    return 0;
}