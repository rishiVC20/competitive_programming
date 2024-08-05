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
        ll sum = 0;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);  
            // if (x%2 == 0)
            //     sum++;         
        }
        bool f=true;
        for (ll i=1; i<n; i++){
            if (a[i]%2 != a[i-1]%2){
                f=false;
                break;
            }
        }
        if (f){
            cout<<0<<endl;
            continue;
        }
        sort(a.begin(),a.end());
        ll kk = INT_MIN,qq=INT_MIN;
        for (ll i=0; i<n; i++){
            if (a[i]%2==0){
                kk = max(kk,a[i]);
            }
            else{
                qq = max(qq,a[i]);
            }
        }
        for (ll i=0; i<n; i++){
            if (a[i]%2 == 0 && a[i]<qq){
                sum++;
                a[i] += qq;
                qq = max(qq,a[i]);
            }
        }
        f=true;
        for (ll i=1; i<n; i++){
            if (a[i]%2!=a[i-1]%2){
                f=false;
                break;
            }
        }
        if (f){
            cout<<sum<<endl;
            continue;
        }
        ll q = -1;
        for (ll i=0; i<n; i++){
            if (a[i]%2 == 1 && a[i]==qq){
                q = i;
                break;
            }
        }
        a[q]=qq+kk;
        sum++;
        for (ll i=0; i<n; i++){
            if (a[i]%2 == 0)
                sum++;
        }
        // if (a[n-1]%2 == 0){
        //     ll maxi;
        //     for (ll i=n-2; i>=0; i--){
        //         if (a[i]%2!= 0){
        //             maxi = a[i];
        //             break;
        //         }
        //     }
        //     // cout<<maxi<<' ';
        //     for (ll i=0; i<n-1; i++){
        //         if (a[i]%2 == 0 && a[i]<maxi){
        //             a[i] += maxi;
        //             maxi = max(maxi,a[i]);
        //         }
        //     }
        //     // for (auto i:a)
        //     //     cout<<i<<' ';
        //     // cout<<maxi<<' ';
        //     // if (maxi < a[n-1]){
        //     //     // cout<<'k'<<' ';
        //     //     sum++;
        //     // }
        //     for (ll i=0; i<n; i++){
        //         if (a[i]>maxi ){
        //             sum++;
        //             // a[i] += maxi;
        //             maxi+=a[i];
        //         }
        //     }
        //     // else{
        //     //     sum += 2;
        //     // }
        // }
        cout<<sum<<endl;
    }
    return 0;
}