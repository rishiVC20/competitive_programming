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
    
public:
vector<ll>size,rank,parent;
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

void makeList(vector<vi> &a, vi b){
    if(b.size() <= 0)
        return;
        
        
}
void solve(ll &cn, vector<vi> &a, vector<bool> &vis, ll j){
    if(vis[j] == true){
        return ;
    }
    cn++;
    vis[j] = true;

    for(auto i:a[j]){
        // cout<<i<<' ';
        if(!vis[i])
            solve(cn,a,vis,i);
    }
}

int main() {
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vi>a(n+1);
        // vi b;
        Disjoint d(n);
        for(ll i=0; i<m; i++){
            ll k;cin>>k;
            vi b;
            // b.pb(k);
            if(k==0) continue;
            ll u;cin>>u;
            for(ll j=0; j<k-1; j++){
                ll t;cin>>t;
                // b.pb(t);
                // if(j != 0){
                //     ll p=b[j-1],q=b[j];
                //     d.unionBySize(p,q);
                // }
                d.unionBySize(u,t);
            }
            // for(ll j=0; j<b.size(); j++){
            //     for(ll h=j+1; h<b.size(); h++){
            //         a[b[j]].pb(b[h]);
            //         a[b[h]].pb(b[j]);
            //     }
            // }

        }      
        // for(auto i:a){
        //     for(auto j:i){
        //         cout<<j<<' ';
        //     }
        //     cout<<endl;
        // }

        for(ll i=1; i<=n; i++){
            // cout<<d.size[d.parent[i]]<<' ';
            cout<<d.size[d.findParent(i)]<<' ';
            // ll cn=0;
            // vector<bool>vis(n+1,false);
            // solve(cn,a,vis,i);
            // if(cn==0) cn=1;
            // cout<<cn<<' ';
        }
        cout<<endl;
    }
    return 0;
}