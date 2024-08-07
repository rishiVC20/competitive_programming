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
//         ll l,r;
//         cin>>l>>r;
//         // ll k=(l)/3;
//         // k++;
//         // ll u=(l*powl(3,k);
//         // ll sum=0;
//         // for (ll i=l+2; i<=r; i++){
//         //     sum += (i/3)+1;
//         // }       
//         // sum += k;
//         // sum += (u/3)+1;
//         // cout<<sum<<endl;
//         ll k = floor(log2(l)/log2(3)) + 1;
//         // cout<<log2(3)<<' ';
//         ll sum = 2*k;
//         while (l<r){
//             ll q = log2(r)/log2(3);
//             ll e = powl(3,q);
//             q++;
//             ll cn = r-max(e,l+1);
//             sum += (q)*(cn+1);
//             r = e-1;
//         }

//         cout<<sum<<endl;
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
    vi pre;
    pre.pb(0);
    pre.pb(1);
    pre.pb(1);
    pre.pb(2);
    pre.pb(2);
    pre.pb(2);
    pre.pb(2);
    pre.pb(2);
    pre.pb(2);
    pre.pb(2);
    pre.pb(3);
    pre.pb(3);
    pre.pb(3);
    pre.pb(3);
    for (ll i=14; i<1e7; i++){
        ll t=i/3;
        pre.pb(pre[t]+1);
    }
    while (t--)
    {
        ll l,r;
        cin>>l>>r;
        ll k = pre[l+1];
        ll j = l*pow(3,k);
        ll sum = 0;
        sum += pre[j];
        for (ll i=l+2; i<=r; i++){
            sum += pre[i];
        }

        cout<<sum<<endl;
    }
    return 0;
}