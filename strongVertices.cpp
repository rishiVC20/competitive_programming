// // Rishikesh Chaudhari
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>

// const ll mod = 1e9 + 7;

// ll mul(ll a, ll b, ll m = mod)
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
//         if (exponent % 2 == 0)
//         {
//             base = (base * base) % mod;
//             exponent = exponent / 2;
//         }
//         else
//         {
//             ans = (ans * base) % mod;
//             exponent--;
//         }
//     }
//     return ans;
// }

// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n;
//         cin >> n;
//         vi a, b;
//         for (ll i = 0; i < n; i++)
//         {
//             ll x;
//             cin >> x;
//             a.pb(x);
//         }
//         for (ll i = 0; i < n; i++)
//         {
//             ll x;
//             cin >> x;
//             b.pb(x);
//         }

//         unordered_map<ll, set<ll>> st;
//         for (ll i = 0; i < n; i++)
//         {
//             for (ll j = 0; j < n; j++)
//             {
//                 if (i != j)
//                 {
//                     if (a[i] - a[j] >= b[i] - b[j])
//                     {
//                         st[i + 1].insert(j + 1); 
//                     }
//                 }
//             }
//         }

//         for (auto i:st)
//         {
//             ll p = i.first;
//             for (ll j=0; j<i.second.size(); j++)
//             {
                
//             }
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
        ll n;
        cin>>n;
        vi a,b;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            b.pb(x);
        }
        vi c;
        for (ll i=0; i<n; i++){
            c.pb(a[i]-b[i]);
        }
        ll maxi = INT_MIN;
        for (ll i=0; i<n; i++){
            maxi = max(maxi,c[i]);
        }

        ll ci = 0;
        for (ll i=0; i<n; i++){
            ci += (c[i]==maxi);
        }

        cout<<ci<<endl;
        for (ll i=0; i<n; i++){
            if (c[i]==maxi){
                cout<<i+1<<' ';
            }
        }

        cout<<endl;

    }
    return 0;
}