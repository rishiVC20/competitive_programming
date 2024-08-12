// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long 
// // #define pb push_back 
// // #define onebit(x) __builtin_popcountll(x)
// // #define vi vector<ll>
// // #define YES cout<<'Y'<<'E'<<'S'<<endl
// // #define NO cout<<'N'<<'O'<<endl  

// // const ll mod = 1e9+7;

// // ll mul (ll a, ll b, ll m=mod)
// // {
// //     a = a % m;
// //     b = b % m;
// //     return (((a * b) % m) + m) % m;
// // }
// // ll LCM(ll a, ll b)
// // {
    
// //     a = (a*b)/(__gcd(a,b));
// //     return a;
// // }
// // bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
// // {
// //     return a.second < b.second;
// // }
// // ll power(ll base, ll exponent)
// // {
// //     if (exponent < 0)
// //     {
// //         return 0;
// //     }
// //     ll ans = 1;
// //     while (exponent)
// //     {
// //         if (exponent%2==0)
// //         {
// //             base = (base*base) % mod;
// //             exponent = exponent/2;
// //         }
// //         else
// //         {
// //             ans = (ans*base) % mod;
// //             exponent--;
// //         }
// //     }
// //     return ans;
// // }


// // int main() {
// //     ll t;
// //     cin>>t;
// //     while (t--)
// //     {
// //         ll x,y,k;
// //         cin>>x>>y>>k;
// //         ll c=k;
// //         // if (k%2)
// //         //     k--;
// //         // else    
// //         //     k-=2;    
// //         vi a,b;
// //         for (ll i=0; i<k/2; i++){
// //             a.pb(i+1);
// //             a.pb((i+1)*-1);
// //             b.pb(i+1);
// //             b.pb((i+1)*-1);
// //         }       
// //          if (k % 2 != 0) {
// //             a.pb(0);
// //             b.pb(0);
// //         }
// //         for (ll i=0; i<k; i++){
// //             cout<<a[i]+x<<' '<<b[i]+x<<endl;
// //         }
// //         // if (c%2==0){
// //         //     cout<<0<<' '<<0<<endl;
// //         //     cout<<x*c<<' '<<y*c<<endl;
// //         // }
// //         // else{
// //         //     cout<<x*c<<' '<<y*c<<endl;
// //         // }
// //     }
// //     return 0;
// // }


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
//         ll x,y,k;
//         cin>>x>>y>>k;
//         // ll c=k;
//         // if (k%2)
//         //     k--;
//         // else    
//         //     k-=2;    
//         // vi a,b;
//         // for (ll i=0; i<k/2; i++){
//         //     a.pb(i+1);
//         //     a.pb((i+1)*-1);
//         //     b.pb(i+1);
//         //     b.pb((i+1)*-1);
//         // }       
//         vector<pair<ll, ll>> a;

//          for (ll i = 1; i < k; i += 2) {
//             a.pb({i, i});
//             a.pb({-i, -i});
//         }
//         if (k % 2 == 0) {
//             a.pop_back();
//             // cout<<'k';
//         }

//          ll pp = 0;
//          ll qq = 0;
//         for (auto p : a) {
//             pp += p.first;
//             qq += p.second;
//         }
//         ll c = x * k - pp;
//         ll d = y * k - qq;
//         a.pb({c, d});
        
//         // cout<<k<<' ';
//         // cout<<a.size()<<' '<<b.size()<<endl;
//         // for (auto i:b)
//         //     cout<<i<<' ';
//         // cout<<endl;    
//         // for (ll i=0; i<k; i++){
//         //     cout<<a[i]<<' '<<b[i]<<endl;
//         // }
//         // if (c%2==0){
//         //     cout<<0<<' '<<0<<endl;
//         //     cout<<x*c<<' '<<y*c<<endl;
//         // }
//         // else{
//         //     cout<<x*c<<' '<<y*c<<endl;
//         // }
//         for (auto i : a) {
//             cout << i.first << " " << i.second << endl;
//         }
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
        ll x,y,k;
        cin>>x>>y>>k;
        // if (k%2==0)
        //     k-=2;
        // else
        //     k--;    
        for (ll i=-k/2; i<=k/2; i++){
            if (i==0 && k%2==0)
                continue;

            cout<<x+i<<' '<<y<<endl;
        }       
    }
    return 0;
}