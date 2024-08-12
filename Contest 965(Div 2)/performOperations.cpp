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
//         ll n,k;
//         cin>>n>>k;
//         // vi a,b;
//         ll maxi=INT_MIN;
//         vector<pair<ll,ll>>a(n);
//         for (ll i=0; i<n; i++){
//             ll x; cin>>x;
//             a[i].first=x;
//         }       
//         for (ll i=0; i<n; i++){
//             ll x; cin>>x;
//             a[i].second = x;
//         }
//         sort(a.begin(),a.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
//             return a.first<b.first;
//         });

//         // vi b,c;
//         // for (ll i=0; i<n; i++){
//         //     b.pb(a[i].first);
//         //     c.pb(a[i].second);
//         // }
//         // for (ll i=0; i<n; i++){
//         //     if (c[i]==1){
//         //         ll f=max(k,0LL);
//         //         if (f==0)
//         //             break;
//         //         k-=f;
//         //         b[i]+=f;
//         //     }
            
//         // }
//         // vi kk;
//         // for (ll i=0; i<n; i++){
            
//         //     for (ll j=0; j<n; j++){
//         //         if (i==j)
//         //             continue;
//         //         kk.pb(b[j]);
//         //     }
//         //     // for (auto i:kk)
//         //     //     cout<<i<<' ';
//         //     sort(kk.begin(),kk.end());    
//         //     ll md = kk[(n-2)/2];
//         //     maxi = max(maxi,b[i]+md);
//         //     kk.clear();
//         // }

//         // cout<<maxi<<endl;

//         ll lo=0, hi=1e9, ans=a[n-1].first;
//         while (lo<=hi){
//             ll mid = lo+(hi-lo)/2;
//             ll req = (n+1)/2+1;
//             ll rem=k;
//             for (ll i=n-1; i>=0; i--){
//                 if (a[i].first>=mid)
//                     req--;
//                 else if (a[i].second==1){
//                     if (mid-a[i].first<=rem){
//                         rem-=(mid-a[i].first);
//                         req--;
//                     }
//                 }    
//             }
//             if (req<=0){
//                 ans = max(ans,a[n-1].first+mid);
//                 lo=mid+1;
//             }
//             else{
//                 hi=mid-1;
//             }
//         }

//         ll q=-1;
//         for (ll i=n-1; i>=0; i--){
//             if (a[i].second==1){
//                 q=i;
//                 break;
//             }
//         }
//         if (q==-1){
//             cout<<ans<<endl;
//             continue;
//         }

//         if (q<=n/2-1){
//             ans=max(ans,a[n/2].first+a[q].first+k);
//         }
//         else{
//             ans=max(ans,a[n/2-1].first+a[q].first+k);
//         }

//         cout<<ans<<endl;


//     }
//     return 0;
// }

// /*
// 16
// 6
// 8
// 13
// 21
// 26
// 8
// 3000000000

// */


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
        ll n,k;
        cin>>n>>k;
        vector<pair<ll,ll>>v(n);
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            v[i].first=x;
        }       
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            v[i].second=x;
        }       

        sort(v.begin(),v.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
            return a.first<b.first;
        });
        
        ll maxi=INT_MIN;
        ll q=-1;
        for (ll i=n-1; i>=0; i--){
            if (v[i].second==1){
                q=i;
                maxi=v[i].first;
                break;
            }
        }
        if (q!=-1){
            if (q<(n/2)){
                maxi+=v[n/2].first;
            }
            else{
                maxi+=v[(n/2)-1].first;
            }
        }

        

    }
    return 0;
}