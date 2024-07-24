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
        vi a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }       
        vi b(30,0);
        // for (ll i=0; i<n; i++){
        //     for (ll j=0; j<32; j++){
        //         if (a[i]&(powl(2,j)) == 1){
        //             b[j]++;
        //         }
        //     }
        // }
        for (ll i=0; i<30; i++){
            for (ll j=0; j<n; j++){
                // cout<<a[j]<<' ';
                if (a[j]&(1<<i)){
                    // cout<<'h';
                    b[i]++;
                }
            }
        }
        // cout<<(1<<2)<<' ';
        // for (auto i:b){
        //     cout<<i<<' ';
        // }
        vi ans;
        ll kp = accumulate(b.begin(),b.end(),0);
        for (ll i=0; i<n; i++){
            // bool f = true;
            // for (ll j=0; j<30; j++){
            //     if (b[j]%(i+1) != 0){
            //         f = false;
            //         break;
            //     }
            // }
            // if (f){
            //     cout<<i+1<<' ';
            // }
            if (kp%(i+1) == 0){
                cout<<i+1<<' ';
            }
        }

        cout<<endl;
    }
    return 0;
}