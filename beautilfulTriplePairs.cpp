// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll> 

// const ll mod = 1e9+7;

// ll mul (ll a, ll b, ll m=mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll power(ll base, ll exponent)
// {
//     if (exponent < 0)
//     {
//         return 0;
//     }
//     ll ans = 1;
//     while (exponent)
//     {
//         if (exponent%2==0)
//         {
//             base = (base*base) % mod;
//             exponent = exponent/2;
//         }
//         else
//         {
//             ans = (ans*base) % mod;
//             exponent--;
//         }
//     }
//     return ans;
// }

// bool check(int i, int j, vi &a)
// {
//     if (a[i]==a[j])
//         return true;

//     return false;    
// }

// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         vi a,b,c;
//         for (ll i=0; i<n; i++)
//         {
//             ll x; cin>>x;
//             if (i==0){
//                 a.pb(x);
//             }
//             else if (i==1){
//                 a.pb(x);
//                 b.pb(x);
//             }
//             else if (i==n-2){
//                 b.pb(x);
//                 c.pb(x);
//             }
//             else if (i==n-1)
//                 c.pb(x);
//             else{
//                 a.pb(x);
//                 b.pb(x);
//                 c.pb(x);
//             }
//         }       
//         for (auto i:a){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//         for (auto i:b){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//         for (auto i:c){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//         cout<<endl;

//         vi mp(n-2,0);
//         vi pk(n-2,0);
//         ll cn=0;
//         map<ll,set<ll>> sp;
//         for (int i=0; i<n-2; i++)
//         {
//             for (int j=i+1; j<n-1; j++)
//             {
//                 if (a[i]==a[j])
//                 {
//                     bool p1 = check(i,j,b);
//                     bool p2 = check(i,j,c);
//                     if (p1==false && p2==true){
//                         mp[i]++;
//                         sp[i].insert(j);
//                     }
//                     else if (p1==true && p2==false){
//                         mp[i]++;
//                         sp[i].insert(j);
//                     }
//                     else if (p1==true && p2==true)
//                         cn++;

//                 }
//             }
//         }

//         for (int i=0; i<n-2; i++)
//         {
//             // if (mp[i] > 0)
//             //     continue;
//             for (int j=i+1; j<n-1; j++)
//             {
//                 if (b[i]==b[j]){
//                     // bool p1 = check(i,j,c);
//                     // if (p1)
//                     //     mp[i]++;
//                     bool p1 = check(i,j,a);
//                     bool p2 = check(i,j,c);
//                     if (p1==false && p2==true){
//                         mp[i]++;
//                         sp[i].insert(j);
//                     }
//                     else if (p1==true && p2==false){
//                         mp[i]++;
//                         sp[i].insert(j);
//                     }
//                 }
//             }
//         }
//         // for (auto i:mp)
//         //     cout<<i<<" ";
//         // ll ans = accumulate(mp.begin(),mp.end(),0);

//         ll ans = 0;
//         // for (ll i=0; i<mp.size(); i++)
//         // {
//         //     if (mp[i] > 0){
//         //         ans += mp[i];
//         //     }
//         // }
//         // cout<<ans-cn<<endl;

//         for (auto i:sp)
//         {
//             // cout<<i.first<<":"<<" ";
//             for (auto j:i.second){
//                 // cout<<j<<" ";
//                 ans++;
//             }
//             // cout<<endl;    
//         }
//         // cout<<ans<<endl;
//         // cout<<endl;
//     }
//     return 0;
// }



// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

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
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }       

        map<tuple<ll,ll,ll>,ll>mp;
        ll ans = 0;
        for (ll i=0; i<n-2; i++)
        {
            ans += mp[{a[i],a[i+1],-1}] + mp[{a[i],-1,a[i+2]}] + mp[{-1,a[i+1],a[i+2]}] - 3*mp[{a[i],a[i+1],a[i+2]}];
            mp[{a[i],a[i+1],-1}]++;
            mp[{a[i],-1,a[i+2]}]++;
            mp[{-1,a[i+1],a[i+2]}]++;
            mp[{a[i],a[i+1],a[i+2]}]++;
        }

        cout<<ans<<endl;
    }
    return 0;
}