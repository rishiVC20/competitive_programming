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
        vi k,c;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            x--;
            k.pb(x);
        }       
        for (ll i=0; i<m; i++){
            ll x; cin>>x;
            c.pb(x);
        }
        sort(k.rbegin(),k.rend());
        ll sum = 0;
        ll d=0;
        // for (auto i:c)
        //     cout<<i<<' ';
        for (ll i=0; i<n; i++){
            if (c[k[i]] > c[d]){
                sum += c[d];
                d++;
                // cout<<'h';
            }
            else{
                // cout<<'k';
                sum += c[k[i]];
            }
        }

        cout<<sum<<endl;
    }
    return 0;
}