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

void dfs(ll v, ll c,vector<bool>&vis,vector<vector<vi>>& adj){
    vis[v]=true;
    for(auto u:adj[v][c]){
        if(!vis[u])
            dfs(u,c,vis,adj);
    }
}

int main() {
    ll t=1;
    // cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<vi>> adj(n+1, vector<vi>(m+1));
        for(ll i=0; i<m; i++){
            ll u,v,c;
            cin>>u>>v>>c;
            adj[u][c].pb(v);
            adj[v][c].pb(u);
        }
        
        ll q;
        cin>>q;
        while(q--){
            ll u,v;
            cin>>u>>v;
            ll cn=0;
            for(ll i=1; i<=m; i++){
                vector<bool>vis(n,false);
                dfs(u,i,vis,adj);
                if(vis[v])
                    cn++;
            }
            cout<<cn<<endl;
        }

        
        

    }
    return 0;
}