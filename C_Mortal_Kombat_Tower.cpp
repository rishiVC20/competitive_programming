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

class Disjoint{
    vector<ll>size,rank,parent;
public:
    Disjoint(ll n){
        size.resize(n+1,1);
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(ll i=0; i<=n; i++)
            parent[i]=i;
    }
    ll findParent(ll node){
        if(node==parent[node])
            return node;
        return parent[node]=(findParent(parent[node]));
    }
    void unionByRank(ll u, ll v){
        ll ulp_u=findParent(u);
        ll ulp_v=findParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(ll u, ll v){
        ll ulp_u=findParent(u);
        ll ulp_v=findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
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


ll solve(ll i, vi &a, ll j, vector<bool>&vis, vi &dp){
    if(i>=a.size()){
        return 0;
    }
    vis[i]=true;
    if(dp[i] != -1)
        return dp[i];
    // cout<<i<<' ';
    ll w=a[i]+min(solve(i+2,a,i,vis,dp),solve(i+3,a,i,vis,dp));

    ll x=INT_MAX;
    if(i+1<a.size()){
        x=a[i]+a[i+1]+min(solve(i+3,a,i,vis,dp),solve(i+4,a,i,vis,dp));
    }

    return dp[i]=min(w,x);
}


int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vi a;

        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }       

        vector<bool>vis(n,false);
        vi dp(n+1,-1);
        cout<<solve(0,a,0,vis,dp)<<endl;
        // ll cp=0;
        // vi b(n,-1);
        // b[0]=0;
        // ll cur1=1,cur2=0;
        // for(ll i=1; i<n; i++){
        //     if(a[i]==1){
        //         if(cur2<2){
        //             cur2++;
        //             b[i]=1;
        //             cur1=0;
        //         }
        //         else{
        //             b[i]=0;
        //             cur2=0;
        //             cur1=1;
        //         }
        //     }
        //     else{
        //         if(cur1<2){
        //             b[i]=0;
        //             cur1++;
        //             cur2=0;
        //         }
        //         else{
        //             cur1=0;
        //             cur2=1;
        //             b[i]=1;
        //         }
        //     }
        // }

        // ll cn=0;
        // for(ll i=0; i<n; i++){
        //     if(b[i]==0){
        //         cn += a[i];
        //     }
        // }

        // cout<<cn<<endl;
    }
    return 0;
}