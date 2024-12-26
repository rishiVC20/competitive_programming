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

void dfsIn(vector<vi> &adj, vi &in, ll node, ll par){

    for(auto i:adj[node]){
        if(i != par){
            dfsIn(adj,in,i,node);
            in[node]=max(in[node],1+in[i]);

        }
    }
}

void makeParent(vector<vi> &adj, ll node, ll par, vi &parent){

    for(auto i:adj[node]){
        if(i != par){
            makeParent(adj,i,node,parent);
            parent[i]=node;
        }
    }
}

void dfsOut(vector<vi> &adj, vi &out, vi &in, ll node, ll par, vi &parent){
    ll mx1=-1,mx2=-1;

    // if(par != -1){
        for(auto i:adj[node]){
            if(i!=par){
                if(mx1 <= in[i]){
                    mx2=mx1,mx1=in[i];
                }
                else if(mx2 < in[i]){
                    mx2=in[i];
                }
            }
        }
    // }

    cout<<node<<' '<<mx1<<' '<<mx2<<endl;

    for(auto i:adj[node]){
        // cout<<"hi";
        
        if(i!=par){
            // cout<<node<<"k ";
            ll lng=mx1;
            if(in[i] == mx1)
                lng=mx2;

            
            // if(node!=-1)
                out[i]=1+max(out[node],1+lng);
            // else{
            //     out[i]=0;
            // }        
            dfsOut(adj,out,in,i,node,parent);
        }
        // if(in[node] == mx1)
        //         lng=mx2;

        //     // dfsOut(adj,out,in,i,node);
        //     if(par!=-1)
        //         out[node]=1+max(out[par],1+lng);
        //     else{
        //         out[node]=0;
        //     } 
    }
}


int main() {
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;

        vector<vi> adj(n);

        for(ll i=0; i<n-1; i++){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        vi parent(n,0);
        parent[0]=-1;
        makeParent(adj,0,-1,parent);
        // for(auto i:parent)
        //     cout<<i<<' ';
        // cout<<endl;    
        vi in(n,0);
        vi out(n,0);
        dfsIn(adj,in,0,-1);

        dfsOut(adj,out,in,0,-1,parent);

        for(auto i:in)
            cout<<i<<' ';
        cout<<endl;    
        for(auto i:out)
            cout<<i<<' ';
        cout<<endl;    
        for(ll i=0; i<n; i++){
            // cout<<'j';
            cout<<max(in[i],out[i])<<' ';
        }

        cout<<endl;
    }
    return 0;
}