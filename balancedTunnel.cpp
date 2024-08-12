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
    // ll t;
    // cin>>t;
    // while (t--)
    // {
        ll n;
        cin>>n;
        vi a,b;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            b.pb(x);
        }
        ll i=0, j=0;
        set<ll>st;
        ll cn=0;
        while (i<n && j<n){
            // cout<<'k';
            if (st.find(a[i])==st.end()){
                while (a[i]!=b[j] && j<n && i<n){
                    
                    cn++;
                    st.insert(b[j]);
                    j++;
                }
                i++,j++;
            }
            else{
                i++;
            }
        }
        cout<<cn<<endl;
    // }
    return 0;
}