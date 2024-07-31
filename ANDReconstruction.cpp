// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>
// #define YES cout<<'Y'<<'E'<<'S'<<endl
// #define NO cout<<'N'<<'O'<<endl  

// const ll mod = 1e9+7;

// ll mul (ll a, ll b, ll m=mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll LCM(ll a, ll b)
// {
    
//     a = (a*b)/(__gcd(a,b));
//     return a;
// }
// bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
// {
//     return a.second < b.second;
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


// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         vi a;
//         for (ll i=0; i<n-1; i++){
//             ll x; cin>>x;
//             a.pb(x);
//         }
//         vector<vector<ll>>b(n,vector<ll>(30,0));
        
//         for (ll i=29; i>=0; i--){
//             if (a[0] & (1<<i)){
//                 b[0][i]=1;
//                 b[1][i]=1;
//             }
//         }
//         bool f=true;
//         for (ll i=1; i<n-1; i++){
//             for (ll j=29; j>=0; j--){
//                 if (a[i] & (1<<j)){
//                     if (b[i][j] == -1){
//                         f=false;
//                         break;
//                     }
//                     b[i][j]=1;
//                     b[i+1][j]=1;
//                     // cout<<'j'<<' ';
//                 }
//             }
//             if (!f){
//                 break;
//             }
//             for (ll j=29; j>=0; j--){
//                 if (b[i][j]==1 && b[i+1][j]!=1){
//                     b[i+1][j] = -1;
//                 }
//                 // else if (b[])
//             }
//         }
//         if (!f){
//             cout<<-1<<endl;
//             continue;
//         }
//         // for (ll i=0; i<n; i++){
//         //     for (ll j=0; j<10; j++){
//         //         cout<<b[i][j]<<' ';
//         //     }
//         //     // cout<<endl;
//         // }
//         for (ll i=0; i<n; i++){
//             ll ans = 0;
//             for (ll j=29; j>=0; j--){
//                 if (b[i][j] == 1){
//                     // cout<<b[i][j]<<'k';
//                     ans = ans|(1<<j);
//                 }
//             }
//             cout<<ans<<' ';
//         }
//         cout<<endl;
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
        for (ll i=0; i<n-1; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        a.pb(a.back());
        // for (auto i:a)
        //     cout<<i<<' ';
        vi b(n);
        b[0] = a[0];
        for (ll i=1; i<n; i++){
            ll k = a[i]|a[i-1];
            b[i] = a[i]|a[i-1];
        }
        // b.pb(a.back());
        for (auto i:b){
            cout<<i<<' ';
        }
        bool f=true;
        for (ll i=0; i<n-1; i++){
            if (b[i]&b[i+1] != a[i]){
                cout<<b[i]<<'k';
                f=false;
                // break;
            }
        }
        if (!f){
            cout<<-1<<endl;
            continue;
        }
        // for (auto i:b){
        //     cout<<i<<' ';
        // }
        cout<<endl;
    }
    return 0;
}