// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll> 

// const ll mod = 1e9+7;
// const int MAX = 200'007;
// vi bit(MAX);

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
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
    
//     ll maxi = -1;
//     ll kap;
//     ll str;
//     for (ll i=0; i<MAX; i++){
//         kap = maxi;
//         ll x = onebit(i);
//         maxi = max(maxi,x);
//         if (kap!=maxi){
//             str = i;
//             bit[i] = str;
//         }
//         else{
//             // bit.pb(str);
//             bit[i] = str;
//         }
//     }
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,k;
//         cin>>n>>k;
//         ll maxi = 0;
//         if (n==1){
//             cout<<k<<endl;
//             continue;
//         }
//         ll ans, p;
//         // for (ll i=k; i>=0; i--){
//         //     ans = maxi;
//         //     ll x = onebit(i);
//         //     maxi = max(maxi,x);
//         //     if (ans!=maxi)
//         //         p = i;
//         // }
//         // for (ll i=0; i<k; i++)
//         //     cout<<bit[i]<<" ";
//         p = bit[k];
//         cout<<p<<" ";
//         if (n >= 2)
//             cout<<k-p<<" ";
//         for (ll i=0; i<n-2; i++)
//             cout<<0<<" ";
//         cout<<"\n";    
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
        // ll n,k;
        // cin>>n>>k;
        // if (n==1){
        //     cout<<k<<"\n";
        //     continue;
        // }    
        ll n,k;
        cin>>n>>k;
        if (n==1){
            cout<<k<<endl;
            continue;
        }   
        
        ll p = log2(k+1);
        // cout<<p<<endl;
        ll temp = powl(2,p)-1;
        cout<<temp<<" ";
        if (n>=2)
            cout<<k-temp<<" ";
        for (ll i=0; i<n-2; i++)
            cout<<0<<" ";
        cout<<"\n";        
    }
    return 0;
}

/*
5
1 5
2 3
2 5
6 51
2 4
*/