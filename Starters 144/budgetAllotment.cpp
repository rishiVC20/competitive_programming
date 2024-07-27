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
        ll n,x;
        cin>>n>>x;
        vi a;
        ll sum = 0;
        ll k=0;
        for (ll i=0; i<n; i++){
            ll d; cin>>d;
            a.pb(d);
            if (d >= x){
                sum++;
                k+= (d-x);
            }
        }
        // cout<<k<<' ';
        sort(a.rbegin(),a.rend());
        if (sum==n){
            cout<<n<<endl;
            continue;
        }
        ll j=0;
        for (ll i=0; i<n; i++){
            if (a[i] < x){
                j=i;
                break;
            }
        }
        // cout<<j<<' ';
        for (ll i=j; i<n; i++){
            ll diff = x-a[i];
            if (k>=diff){
                a[i] += diff;
                k -= diff;
            }

        }
        ll ans = 0;
        for (auto i:a){
            if (i>=x)
                ans++;
        }

        cout<<ans<<endl;
    }
    return 0;
}