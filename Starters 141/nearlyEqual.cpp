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
        string a,b;
        cin>>a>>b;
        ll ans = 0;
        // for (ll i=0; i<m; i++){
        //     ll p = b[i];
        //     ll w = i;
        //     ll sum = 0;
        //     bool f = false;
        //     for (ll j=0; j<n; j++){
        //         if (a[j]==b[w] && f == false){
        //             w++;
        //             sum++;
        //             f = true;
        //         }
        //         else if (f && a[j]==b[w]){
        //             sum++;
        //             w++;
        //         }
        //         else if (f==true){
        //             w++;
        //         }
        //     }
        //     // cout<<sum<<' ';
        //     ans = max(sum,ans);
        // }

        for (ll i=0; i<=n-m; i++)
        {
            ll j = i;
            ll w = 0;
            ll sum = 0;
            while (w<m){
                if (b[w] == a[j]){
                    sum++;
                }
                w++;
                j++;
            }
            ans = max(ans,sum);
        }

        cout<<m-ans<<endl;
    }
    return 0;
}