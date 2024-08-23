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
        ll n,w;
        cin>>n>>w;
        vi a;
        multiset<ll>ms;
        for (ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            ms.insert(x);
        }
        sort(a.begin(),a.end());
        vector<bool>v(n,false);
        ll cn=1;
        // for(ll i=n-1; i>=0; i--){
        //     ll sum=0;
        //     if (!v[i]){
        //         // cout<<a[i]<<' ';
        //         v[i]=true;
        //         sum+=a[i];
        //         cn++;
        //         for (ll j=i-1; j>=0; j--){
        //             if (sum+a[j]<=w && !v[j]){
        //                 // cout<<a[j]<<' ';
        //                 sum+=a[j];
        //                 v[j]=true;
        //             }
        //             // else{
        //             //     break;
        //             // }
        //         }

        //     }
        // }
        ll lf=w;
        while (!ms.empty()){
            auto it=ms.upper_bound(lf);
            if (it==ms.begin()){
                lf=w;
                cn++;
                // ms.erase(ms.begin());
            }
            else{
                it--;
                ll k=*it;
                lf-=k;
                ms.erase(it);
            }
        }

        cout<<cn<<endl;
    }
}