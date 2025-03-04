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
ll mAdd(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mSub(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mul (ll a, ll b, ll m=mod){
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b){
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
ll power(ll base, ll exponent){
    if (exponent < 0){
        return 0;
    }
    ll ans = 1;
    while (exponent){
        if (exponent%2==0){
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else{
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}
ll invmod(ll a, ll m = mod){
    return power(a, m - 2);
}
ll div(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return mul(a, invmod(b, m), m);
}

void dfs(vector<vi> &v, vector<vi> &adj, vector<bool> &vis, vi &vec, ll par, ll cur, bool &found){
    if(found)
        return;
    if(vis[cur]==true){
        vi m;
        bool t=false;
        for(auto i:vec){
            if(i==cur){
                t=true;
            }
            if(!t)
                continue;
            m.pb(i);    
        }
        m.pb(cur);
        if(m.size()>=4){
            v.pb(m);
            found=true;
        }
        return;
    }
    vis[cur]=true;

    vec.pb(cur);
    for(auto i:adj[cur]){
        if(i!=par){
            dfs(v,adj,vis,vec,cur,i,found);
        }
    }
    vec.pop_back();
    vis[cur]=false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vi>adj(n);
        Disjoint d(n);
        for(ll i=0; i<m; i++){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            d.unionBySize(u,v);
            adj[u].pb(v);
            adj[v].pb(u);
            
        }
        vi cn(n,0);
        // ll j=
        for(ll i=0; i<n; i++){
            ll t=d.findParent(i);
            cn[t]++;
        }
        vector<vi>v;
        vector<bool>vis(n,false);
        vi vec;
        bool f=false;
        ll j=-1;
        ll mx=0;
        for(ll i=0; i<n; i++){
            // cout<<cn[i]<<' ';
            if(cn[i]>=mx && adj[i].size()>=1){
                mx=cn[i];
                j=i;
            }
        }
        if(j!=-1)
            dfs(v,adj,vis,vec,-1,j,f);
        
        vi ans;
        for(auto i:v){
            // if(i.size()>=4 && i[0]==i.back()){
                ans=i;
            // }
        }

        if(ans.size()==0){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }

        // for(auto i:v){
        //     for(auto j:i){
        //         cout<<j+1<<' ';
        //     }
        //     cout<<endl;
        // }

        cout<<ans.size()<<endl;
        for(auto i:ans)
            cout<<i+1<<' ';
        cout<<endl;    

    }
    return 0;
}