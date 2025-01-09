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

void dfs1(vector<vi> &adj, vi &in, ll node, ll par){

    for(auto i:adj[node]){
        if(i!=par){
            dfs1(adj,in,i,node);
            in[node]+=(in[i]+1);
        }
    }
}

void dfs2(vector<vi> &adj, vi &out, vi &in, ll node, ll par){

    ll cn=0;
    for(auto i:adj[node]){
        if(i!=par){
            cn += in[i]+1;
        }
    }

    for(auto i:adj[node]){
        if(i!=par){
            out[i]=1+out[node]+(cn-in[i]-1);
            dfs2(adj,out,in,i,node);
        }
    }
}

void dfs3(vector<vi> &adj, vi &in, vi &down, ll node, ll par){

    for(auto i:adj[node]){
        if(i!=par){
            dfs3(adj,in,down,i,node);
            down[node] += (down[i]+in[i]+1);
        }
    }
}

void dfs4(vector<vi> &adj, vi &up, vi &down, vi &in, vi &out, ll node, ll par){

    for(auto i:adj[node]){
        if(i!=par){
            up[i]=(down[node]-down[i]-in[i]-1)+(in[node]-in[i]-1)+up[node] + (out[node]+1);
            dfs4(adj,up,down,in,out,i,node);
        }
    }
}

int main() {
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;

        vector<vi>adj(n);

        for(ll i=0; i<n-1; i++){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);

        }

        vi in(n,0);
        vi out(n,0);
        vi down(n,0);
        vi up(n,0);

        dfs1(adj,in,0,-1);

        dfs2(adj,out,in,0,-1);

        dfs3(adj,in,down,0,-1);

        dfs4(adj,up,down,in,out,0,-1);

        // for(auto i:up)
        //     cout<<i<<' ';
        // cout<<endl;    
        // for(auto i:down)
        //     cout<<i<<' ';
        // cout<<endl;    
        // for(auto i:in)
        //     cout<<i<<' ';
        // cout<<endl;    
        // for(auto i:out)
        //     cout<<i<<' ';
        // cout<<endl;    

        for(ll i=0; i<n; i++){
            cout<<up[i]+down[i]<<' ';
        }

        cout<<endl;
    }
    return 0;
}