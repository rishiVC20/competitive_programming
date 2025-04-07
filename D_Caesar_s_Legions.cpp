// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 1e8;



ll lim_f, lim_h;
int dp[101][101][11][11];
ll solve(ll n, ll f, ll h, ll k1, ll k2){
    if(n==0){
        return 1;
    }

    if(dp[f][h][k1][k2] != -1){
        return dp[f][h][k1][k2];
    }
    ll x=0,y=0;
    if(f>0 && k1>0){
        x=solve(n-1,f-1,h,k1-1,lim_h);
    }

    if(h>0 && k2>0){
        y=solve(n-1,f,h-1,lim_f,k2-1);
    }

    return dp[f][h][k1][k2] = (x+y)%mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n1,n2;
        cin>>n1>>n2>>lim_f>>lim_h;
        memset(dp,-1,sizeof(dp));
        ll p = solve(n1+n2,n1,n2,lim_f,lim_h);
        cout<<p<<endl;
    }
    return 0;
}