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
//         for (ll i=0; i<n; i++){
//             ll x; cin>>x;
//             a.pb(x);
//         }       
//         if (n==1){
//             cout<<1<<endl;
//             continue;
//         }
//         ll i=0, j=1;
//         ll maxi = 1;
//         while (j<n){
//             if (a[i] != a[j]){
//                 j++;
//             }
//             else{
//                 i++;
//             }
//             maxi = max(maxi,j-i);
//         }

//         cout<<maxi<<endl;
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
        set<ll>st;
        map<ll,ll>mp;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            st.insert(x);
            mp[x]++;
        }       
        // if (n==1){
        //     cout<<0<<endl;
        //     continue;
        // }
        for (auto i:mp){
            a.pb(i.second);
        }
        sort(a.rbegin(),a.rend());
        // if (st.find(1) != st.end()){
        //     cout<<a[a.size()-1]<<endl;
        //     continue;
        // }
        // for(auto i:a)
        //     cout<<i<<' ';
        ll x = a.size();
        // cout<<x<<' ';
        
        ll d = 0;
        bool f=true;
        ll sum = 0;
        for (ll i=0; i<x; i++){
            sum += a[i];
            d = max(d,(sum/(i+1))*(i+1));
        }   
        cout<<d<<endl;
    }
    return 0;
}