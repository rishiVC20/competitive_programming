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
const ll mid=998244353;
ll mul (ll a, ll b, ll m=mid)
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

ll multiply(ll x){
    ll ans = 1;
    // while (x){
    //     ans *= x;
    //     x--;
    // }
    ans = (ans*x)%mid;

    return (ans%mid);
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        vi a,b;
        ll n = s.size();
        for (ll i=0; i<n; i++){
            a.pb(s[i]-'0');
        }
        ll curr=1;
        for (ll i=1; i<n; i++){
            if (s[i]==s[i-1]){
                curr++;
            }
            else{
                if (curr>1){
                    b.pb(curr);
                    curr=1;
                }
            }
        }
        if (curr>1)
            b.pb(curr);
        // for (auto i:b)
        //     cout<<i<<' '; 
            // for (auto i:a)
            // cout<<i<<' ';   
        // for (ll i=0; i<n-1; ){
        //     if (a[i]==a[i+1]){
        //         a.erase(a.begin() + (i+1));
        //     }
        //     else{
        //         i++;
        //     }
        // }

        vi arr;
        for (ll i = 0; i < n; i++) {
            if (i < n - 1 && a[i] == a[i + 1]) {
                continue;
            } 
            else {
                arr.pb(a[i]);
            }
        }

        cout<<n-arr.size()<<' ';
        ll q = n-arr.size();
        ll k = 1;
        ll x = b.size();
        for (auto i:b){
            k *= multiply(i);
            k = k%mid;
            // k+=i;
            // cout<<k<<' ';
        }
        // cout<<k<<' ';
        if (b.size()==0){
            cout<<1<<endl;
            continue;
        }
        ll g = 1;
        while (q){
            g = g*q;
            q--;
            g = g%mid;
        }
        // cout<<g<<' ';
        ll ans = mul(k,g,mid);
        cout<<ans;
        cout<<endl;
    }
    return 0;
}





