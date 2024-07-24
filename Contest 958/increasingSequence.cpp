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
//         a.pb(n);
//         ll p = 0;
//         // for (ll i=n-1; i>=1; i--){
//         //     if (i|a[p] == n){
//         //         // cout<<'j'<<' ';
//         //         p++;
//         //         a.pb(i);
//         //     }

//         // }

//         for (ll i=n-1; i>0;){
//             cout<<a[p]<<' ';
//             while (a[p]&i == n){
//                 i--;
//                 cout<<'k'<<' ';
//                 if (i==0)
//                     break;
//             }
//             if (i>0){
//                 a.pb(i);
//                 p++;

//             }
//         }
//         cout<<a.size()<<endl;
//         for (ll i=a.size()-1; i>=0; i--){
//             cout<<a[i]<<' ';
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout << 'Y' << 'E' << 'S' << endl
#define NO cout << 'N' << 'O' << endl

const ll mod = 1e9 + 7;

ll mul(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{

    a = (a * b) / (__gcd(a, b));
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
        if (exponent % 2 == 0)
        {
            base = (base * base) % mod;
            exponent = exponent / 2;
        }
        else
        {
            ans = (ans * base) % mod;
            exponent--;
        }
    }
    return ans;
}
ll toBin(ll x)
{
    ll s=0;
    ll i=0;
    while (x!=0){
        ll bit = x&1;
        // char c = (bit*powl(10,i))-'0';
        s = (bit*powl(10,i))+s;
        x = x>>1;
        i++;
    }

    return s;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll x = onebit(n);
        // cout << x + 1 << endl;
        ll s = toBin(x);
        cout << s << endl;
    }
    return 0;
}