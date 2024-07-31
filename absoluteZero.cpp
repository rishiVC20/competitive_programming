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
//         bool f=true;
//         bool m=false;
//         for (ll i=0; i<n; i++){
//             ll x; cin>>x;
//             a.pb(x);
//             if (x%2 == 0)
//                 m=true;
//             if (i!=0){
//                 if (a[i]%2 != a[i-1]%2)
//                     f = false;
//             }
//         }       
//         if (n==1){
//             cout<<1<<endl;
//             cout<<a[0]<<endl;
//             continue;
//         }
//         if (!f){
//             cout<<-1<<endl;
//             continue;
//         }

//         vi v;
//         for (ll i=29; i>=0; i--){
//             ll k = (1<<i);
//             v.pb(k);
//         }
//         if (m)
//             v.pb(1);

//         cout<<v.size()<<endl;
//         for (auto i:v)
//             cout<<i<<' ';
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
        bool f=true;
        for  (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
            if (i!=0){
                if (a[i-1]%2 != a[i]%2){
                    f=false;
                }
            }
        }
        if (!f){
            cout<<-1<<endl;
            continue;
        }
        vi v;
        for (ll i=0; i<30; i++){
            sort(a.begin(),a.end());
            if (a[0]==a[n-1] && a[0]==0){
                break;
            }
            ll m = a[0]+(a[n-1]-a[0])/2;
            v.pb(m);
            for (ll i=0; i<n; i++){
                a[i] = abs(a[i]-m);
            }
        }
        cout<<v.size()<<endl;
        for (auto i:v)
            cout<<i<<' ';
        cout<<endl;    

    }
    return 0;
}