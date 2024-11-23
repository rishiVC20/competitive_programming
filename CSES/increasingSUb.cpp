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


// ll solve(vi &a, ll i, vi &dp){
//     if(i==0)
//         return 1;
//     if(dp[i] != -1)
//         return dp[i];
//     ll cn=1;
//     for(ll j=0; j<i; j++){
//         if(a[j] < a[i]){
//             cn = max(cn,1+solve(a,j,dp));
//         }
//     }

//     return dp[i]=cn;
// }
int main() {
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        // ll maxi=1;
        // vi dp(n+1,-1);
        // for(ll i=0; i<n; i++){
        //     maxi=max(maxi,solve(a,i,dp));
        // }

        // cout<<maxi<<endl;
        vi lis;

        for (ll i = 0; i < n; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            if (it == lis.end()) {
                lis.push_back(a[i]);
            } else {
                *it = a[i];
            }
            for(auto i:lis)
                cout<<i<<' ';
            cout<<endl;    
        }
        
        cout << lis.size() << endl;
    }
    return 0;
}