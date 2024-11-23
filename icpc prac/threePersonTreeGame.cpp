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

// bool dfs(vector<vi>a, ll st, ll tar, vector<bool>&vis){
//     // if(vis[st]==true)
//     //     return;

//     bool f=false;
//     for(auto i:a[st]){
//         if(vis[i]==true){
//             continue;
//         }
//         vis[i]=true;
//         if(i==tar){
//             return true;
//             break;
//         }
//         dfs(a,i,tar,vis);
//     }
//     return f|false;
// }

bool dfs(vector<vi> &a, ll st, ll tar, vector<bool> &vis) {
    if (st == tar) return true;
    vis[st] = true;
    bool found = false;
    for (auto i : a[st]) {
        if (!vis[i]) {
            // found = dfs(a, i, tar, vis);
            
            if (found) break;
        }
    }
    return found;
}

int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        ll a,b,c;
        cin>>a>>b>>c;
        vector<vi>z(n+1);
        for(ll i=0; i<n-1; i++){
            ll u,v;
            cin>>u>>v;
            z[u].pb(v);
            z[v].pb(u);
        }       
        vector<bool>vis1(n+1,false);
        bool f1=dfs(z,a,c,vis1);
        if(f1){
            cout<<"A"<<endl;
            continue;
        }
        vector<bool>vis2(n+1,false);
        bool f2=dfs(z,b,a,vis2);
        if(f2){
            cout<<"B"<<endl;
            continue;
        }
        vector<bool>vis3(n+1,false);
        bool f3=dfs(z,c,b,vis3);
        if(f3){
            cout<<"C"<<endl;
            continue;
        }

        cout<<"DRAW"<<endl;

    }
    return 0;
}
