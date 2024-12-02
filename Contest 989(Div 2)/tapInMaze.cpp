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

// class Disjoint{
//     vector<ll>size,rank,parent;
// public:
//     Disjoint(ll n){
//         size.resize(n+1,1);
//         parent.resize(n+1);
//         rank.resize(n+1,0);
//         for(ll i=0; i<=n; i++)
//             parent[i]=i;
//     }
//     ll findParent(ll node){
//         if(node==parent[node])
//             return node;
//         return parent[node]=(findParent(parent[node]));
//     }
//     void unionByRank(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u]<rank[ulp_v]){
//             parent[ulp_u]=ulp_v;
//         }
//         else if(rank[ulp_u]>rank[ulp_v]){
//             parent[ulp_v]=ulp_u;
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             rank[ulp_u]++;
//         }
//     }
//     void unionBySize(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(size[ulp_u]<size[ulp_v]){
//             parent[ulp_u]=ulp_v;
//             size[ulp_v]+=size[ulp_u];
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             size[ulp_u]+=size[ulp_v];
//         }
//     }
// };
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
// vi a={1,-1,0,0};
// vi b={0,0,-1,1};
// ll solve(char c){
//     if(c=='D') return 0;
//     if(c=='U') return 1;
//     if(c=='L') return 2;
//     if(c=='R') return 3;

//     return 4;
// }
// bool dfs(vector<vector<char>> &v, vector<vector<bool>> &vis, ll i, ll j, ll n, ll m){
//     if(i<0 || i>=n  || j<0 || j>=m ){
//         return false;
//     }
//     if(vis[i][j]){
//         return true;
//     }
//     vis[i][j]=true;
//     ll dd=solve(v[i][j]);

//     if(dd!=4){
//         ll x=i+a[dd],y=j+b[dd];
//         if(dfs(v,vis,x,y,n,m)){
//             return true;
//         }

//     }
//     else{
//         for(ll k=0; k<4; k++){
//             ll x=i+a[k],y=j+b[k];
//             if(dfs(v,vis,x,y,n,m)){
//                 if(k==0) v[x][y]='U';
//                 if(k==1) v[x][y]='D';
//                 if(k==2) v[x][y]='R';
//                 if(k==3) v[x][y]='L';
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main() {
//     ll tt;
//     cin>>tt;
//     while (tt--)
//     {
//         ll n,m;
//         cin>>n>>m;

//         vector<vector<char>>v(n,vector<char>(m));

//         for(ll i=0; i<n; i++){
//             for(ll j=0; j<m; j++){
//                 cin>>v[i][j];
//             }
//         }      


//         ll cn=0;
//         for(ll i=0; i<n; i++){
//             for(ll j=0; j<m; j++){
//                 vector<vector<bool>>vis(n,vector<bool>(m,false));
//                 if(dfs(v,vis,i,j,n,m)){
//                     cn++;
//                 }
//             }
//             // cout<<endl;
//         }
//         // for(ll i=0; i<n; i++){
//         //     for(ll j=0; j<m; j++){
//         //         cout<<v[i][j];
//         //     }
//         //     cout<<endl;
//         // }

//         cout<<cn<<endl;
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


int main() {
    ll n;
    cin>>n;
    int p=log2(n)<<' ';
    cout<<powl(2,n+1)-1<<endl;
    return 0;
}
