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

void solve(vi &a, vector<vi> &adj, ll node, ll par, vi &ans, set<ll> &st){

    for(auto i:adj[node]){
        if(i!=par){
            solve(a,adj,i,node,ans,st);
            st.insert(a[i]);
            
            // cout<<st.size()<<' ';
        }
    }
    st.insert(a[node]);
    ans[node]=st.size();
}


int main() {
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;

        vi a;
        vector<vi>adj(n);


        for(ll i=0; i<n; i++){
            ll col;
            cin>>col;
            col--;
            a.pb(col);
        }

        for(ll i=0; i<n-1; i++){
            ll x,y;
            cin>>x>>y;
            x--,y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        set<ll>st;
        vi ans(n,1);

        solve(a,adj,0,-1,ans,st);

        for(auto i:ans){
            if(i==0){
                cout<<1<<' ';
                continue;
            }
            cout<<i<<' ';
        }
    }
    return 0;
}