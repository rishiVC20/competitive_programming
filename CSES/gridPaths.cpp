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



ll solve(vector<vector<char>> &a, ll n, vi &d, ll i, ll j, vector<vi>&dp){
    if(i<0 || j<0 ){
        return 0;
    }
    if(a[i][j]=='*')
        return 0;
    if(i==0 && j==0){
        return 1;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    ll up=solve(a,n,d,i-1,j,dp);
    ll left=solve(a,n,d,i,j-1,dp);

    return dp[i][j]=(up+left)%mod;
}

int main() {
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vector<vector<char>>v(n,vector<char>(n));
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                cin>>v[i][j];
            }
        }

        vi d;
        vector<vi>dp(n+1,vi (n+1,-1));
        ll p=solve(v,n,d,n-1,n-1,dp);
        // for(auto i:dp){
        //     for(auto j:i)
        //         cout<<j<<' ';
        //     cout<<endl;    
        // }
        // cout<<p<<' ';
        if(p == -1)
            cout<<0<<endl;
        else
            cout<<p<<endl;    
    }
    return 0;
}


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

// ll solve(vector<vi> &a, ll i, ll j){
//     if(i<0 || j<0)
//         return 0;
//     if(i==0 && j==0){
//         return a[0][0];
//     }    
//     ll up=a[i][j]+solve(a,i-1,j);
//     ll left=a[i][j]+solve(a,i,j-1);

//     return max(up,left);
// }

// int main() {
//     ll tt=1;
//     // cin>>tt;
//     while (tt--)
//     {
//         ll n=5;
//         vector<vi>a(n,vi(n));
//         for(ll i=0; i<n; i++){
//             for(ll j=0; j<n; j++){
//                 cin>>a[i][j];
//             }
//         }

//         ll p=solve(a,n-1,n-1);

//         cout<<p<<endl;
//     }
//     return 0;
// }