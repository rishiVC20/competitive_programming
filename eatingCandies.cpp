// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll> 

// const ll mod = 1e9+7;

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
//         for (ll i=0; i<n; i++)
//         {
//             ll x; cin>>x;
//             a.pb(x);
//         }       
//         ll A=0, B=0;
//         ll i=0, j=n-1;
//         ll cna=-1, cnb=n;
//         while (i <= j)
//         {
//             if (A > B){
//                 B += a[j];
//                 j--;
//             }
//             if (A < B){
//                 A += a[i];
//                 i++;
//             }
//             if ((A==B) && (A != 0)){
//                 // if (A==0)
//                 //     continue;
//                 cna = i;
//                 cnb = j;
//                 i++, j--;
//                 A += a[i];
//                 B += a[j];
//             }
//             else if (A==0){
//                 A += a[i];
//                 i++;
//             }
//         }
//         cout<<cna<<" "<<cnb<<" ";
//         if (cna==-1 || cnb==n){
//             cout<<0<<endl;
//             continue;
//         }
//         cout<<(cna+1)+(n-cnb)<<endl;
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

const ll mod = 1e9+7;

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
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }    
        ll A=0, B=0;
        ll i=0, j=n-1;
        ll cna=-1, cnb=n;
        while (i <= j)
        {
            A += a[i];
            while (B < A && i<j){
                B += a[j];
                j--;
            }
            if (A==B){
                cna = i;
                cnb = j+1;
            }
            i++;
        }
        // cout<<cna<<" "<<cnb<<" ";
        if (cna==-1 || cnb ==n){
            cout<<0<<endl;
            continue;
        }
        // cnb++;
        cout<<(cna+1) + (n-cnb)<<endl;
    }
    return 0;
}