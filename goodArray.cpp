// // Rishikesh Chaudhari
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>
// #define YES cout << 'Y' << 'E' << 'S' << endl
// #define NO cout << 'N' << 'O' << endl

// const ll mod = 1e9 + 7;

// ll mul(ll a, ll b, ll m = mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll LCM(ll a, ll b)
// {

//     a = (a * b) / (__gcd(a, b));
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
//     // ll t;
//     // cin>>t;
//     // while (t--)
//     // {
//     ll n;
//     cin >> n;
//     vi a;
//     unordered_map<ll, ll> mp;
//     for (ll i = 0; i < n; i++)
//     {
//         ll x;
//         cin >> x;
//         a.pb(x);
//         mp[x]++;
//     }
//     ll sum = accumulate(a.begin(), a.end(), 0LL);
//     ll maxi = *max_element(a.begin(), a.end());
//     vi d = a;
//     sort(d.begin(), d.end());
//     ll g = d[n - 1];
//     vi v;
//     // cout<<g<<' ';
//     for (ll i = 0; i < n; i++)
//     {
//         mp[a[i]]--;
//         ll diff = (sum - a[i]) / 2;
//         if (mp[diff] > 0 && (sum - a[i]) % 2 == 0)
//         {
//             v.pb(i + 1);
//         }
//         mp[a[i]]++;
//     }

//     cout << v.size() << endl;
//     for (auto i : v)
//     {
//         cout << i << ' ';
//     }

//     cout << endl;
//     // }
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
    // ll t;
    // cin>>t;
    // while (t--)
    // {
        ll n;
        cin>>n;
        vi a;
        for(ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        ll sum = accumulate(a.begin(),a.end(),0LL);
        ll maxi = *max_element(a.begin(),a.end());
        vi d=a;
        sort(d.begin(),d.end());
        ll g=d[n-1];
        vi v;
        // cout<<g<<' ';
        for(ll i=0; i<n; i++){
            if(a[i]==d[n-1]){
                g=d[n-2];
            }
            else{
                g=d[n-1];
            }
            ll diff = sum-a[i];
            if(diff%2==0 && diff/2==g){
                v.pb(i+1);
            }
        }

        cout<<v.size()<<endl;
        for(auto i:v){
            cout<<i<<' ';
        }

        cout<<endl;
    // }
    return 0;
}