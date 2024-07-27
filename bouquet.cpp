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
//         ll n,m;
//         cin>>n>>m;
//         vi a;
//         map<ll,ll>mp;
//         for (ll i=0; i<n; i++){
//             ll x; cin>>x;
//             a.pb(x);
//             mp[x]++;
//         }       

//         sort(a.begin(),a.end());
//         vector<pair<ll,ll>>v;
//         for (auto i:mp){
//             v.pb({i.first,i.second});
//         }
//         sort(v.begin(),v.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
//             return a.first < b.second;
//         });

//         ll sum = v[0].second;
//         for (ll i=1; i<v.size(); i++){
//             if (v[i].first*v[i].second <= m)
//                 sum = max(sum,v[i].first*v[i].second);
//             if (v[i].first-v[i-1].first <= 1){
//                 if (v[i].first*v[i].second + v[i-1].first*v[i-1].second <= m)
//                     sum = max(sum,v[i].first*v[i].second + v[i-1].first*v[i-1].second);
//             }
//         }
//         cout<<sum<<endl;
//     }
//     return 0;
// }


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

// ll solve(ll x, ll y, ll m, ll n, ll limit, ll ans){
//     vi b;
//     for (ll i=1; i<=y; i++){
//         for (ll j=0; j<=n; j++){
//             ll sum = x*i+m*j;
//             b.pb(sum);
//         }
//     }
//     for (ll i=1; i<=n; i++){
//         for (ll j=0; j<=y; j++){
//             ll sum = m*i+x*j;
//             b.pb(sum);
//         }
//     }
//     ll maxi = 0;
//     for (ll i=0; i<b.size(); i++){
//         ll z = ans;
//         z -= b[i];
//         if (z<=limit){
//             maxi = max(maxi,z);
//         }
//     }

//     return maxi;
// }
// ll single (ll x, ll y, ll limit){
//     ll s = x*y;
//     while (s>0 && s>limit){
//         s -= x;
//     }
//     return s;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,m;
//         cin>>n>>m;
//         vi a;
//         map<ll,ll>mp;
//         for (ll i=0; i<n; i++){
//             ll x; cin>>x;
//             a.pb(x);
//             mp[x]++;
//         }       
//         // for (auto i:mp)
//         //     cout<<i.first<<' '<<i.second<<' ';
//         // cout<<endl;    
        
//         auto it=mp.begin();
//         ll maxi=0;
//         ll k = single(it->first,it->second,m);
//         maxi = max(maxi,k);    
//         if (it!=mp.end())
//             it++;
        
//         for (auto i=mp.begin(); it!=mp.end(); i++,it++){
//             ll diff = it->first-i->first;
//             ll k = single(it->first,it->second,m);
//             maxi = max(maxi,k);
//             // cout<<maxi<<' ';
//             // cout<<it->first<<' ';
//             if (diff == 1){
//                 ll sum = i->first*i->second + it->first*it->second;
//                 if (sum <= m){
//                     maxi = max(sum,maxi);
//                 }
//                 else{
//                     ll ans = solve(i->first,i->second,it->first,it->second,m,sum);
//                     maxi = max(maxi,ans);
//                 }
//             }
//             // if (i->first*i->second <= m)
//             //     maxi = max(maxi,i->first*i->second);
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
        ll n,m;
        cin>>n>>m;
        vi a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }       
        ll sum = 0;
        ll maxi = 0;
        ll i=0,j=0;
        bool f = true;
        sort(a.begin(),a.end());
        while (i<n && j<n){
            if (a[i]-a[j] <= 1){
                sum += a[i];
                if (sum<=m){
                    i++;
                }
                else{
                    sum -= a[j];
                    j++;
                    i++;
                }
            }
            else{
                // sum-=a[j];
                // j++;
                while (a[i]-a[j] > 1){
                    sum-=a[j];
                    j++;
                }
            }
            maxi = max(maxi,sum);
            if (maxi==m){
                f=false;
                break;
            }
        }
        if (!f){
            cout<<m<<endl;
            continue;
        }
        cout<<maxi<<endl;
    }
    return 0;
}