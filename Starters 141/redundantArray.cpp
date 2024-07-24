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
        bool f = true;
        map<ll,ll>mp;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
            mp[x]++;
            if (i!=0 && a[i]!=a[i-1]){
                f = false;
            }
        }       
        if (f){
            cout<<0<<endl;
            continue;
        }

        bool h = true;
        for (auto i:mp){
            // cout<<i.first<<' '<<i.second<<' ';
            if (i.first == 1){
                h = false;
            }
        }
        // cout<<endl;

        ll ans = INT_MAX;
        ll p;
        for (auto i:mp){
        //     // if (i.second > ans){
        //     //     ans = i.second;
        //     //     p = i.first;
        //     // }
        //     // else if (i.second == ans){
        //     //     p = min(p,i.first);
        //     // }
        //     ll k = i.first;
        //     ll j = 0;
        //     ll sum = 0;
        //     // cout<<'j'<<' ';
        //     while (j<n){
        //         // cout<<'j'<<' ';
        //         if (a[j]==k){
        //             j++;
        //             continue;
        //         }
        //         else{
        //             ll l = j;
        //             while (j<n && a[j]!=k){
        //                 j++;
        //             }
        //             ll r = j-1;
        //             sum += (r-l + 1)*k;
        //         }
        //         // ans = min(ans,sum);
                
        //     }
        //     ans = min(ans,sum);

            ll u = i.first;
            ll v = i.second;
            ans = min(u*(n-v),ans);
            
        }

        
        // cout<<ans<<' ';
        // if (h==true){
        //     cout<<min(n,n-ans)<<endl;
        //     continue;
        // }
        // cout<<p<<' '<<ans<<' ';
        cout<<min(n,ans)<<endl;

    }
    return 0;
}