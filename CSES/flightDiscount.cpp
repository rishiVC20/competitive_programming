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

// void dfs(vector<pair<ll,ll>>a[], ll st, ll en, vector<bool> &vis, vi &c, vector<vi> &s, vi &z){
//     // if(vis[st] == true)
//     //     return;
//     if(st==en){
//         if(c.size() > 0){
//             ll p=accumulate(c.begin(),c.end(),0LL);
//             ll g=*max_element(c.begin(),c.end());
//             p-=g;
//             p += (g/2);
//             z.pb(p);
//         }
//         return;
//     }
//     vis[st]=true;
//     for(auto i:a[st]){
//         if(!vis[i.first]){
//             c.pb(i.second);
//             dfs(a,i.first,en,vis,c,s,z);
//             c.pop_back();
//         }
//     }    
//     vis[st]=false;
// }

// int main() {
//     ll tt=1;
//     // cin>>tt;
//     while (tt--)
//     {
//         ll n,m;
//         cin>>n>>m;
//         vector<pair<ll,ll>>a[n+1];

//         for(ll i=0; i<m; i++){
//             ll x,y,z;
//             cin>>x>>y>>z;
//             // x--,y--;
//             a[x].pb({y,z});

//         }
//         // for(auto i:a){
//         //     for(auto j:i)
//         //         cout<<j.first<<' '<<j.second<<' ';
//         //     cout<<endl;    
//         // }

//         vector<bool>vis(n+1,false);
//         vi c;
//         vector<vi> s;
//         vi z;
//         dfs(a,1,n,vis,c,s,z);

//         ll cn=LLONG_MAX;
//         ll p;
//         // for(auto i:s){
//         //     // cout<<i<<' ';
//         //     ll sum=0;
//         //     ll k=0;
//         //     for(auto j:i){
//         //         sum += j;
//         //         k=max(k,j);
//         //     }
//         //     sum -= k;
//         //     sum += (k/2);
//         //     cn = min(cn,sum);
                
//         //     // cout<<endl;    
//         // }

//         cout<<*min_element(z.begin(),z.end())<<endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define INF LLONG_MAX

const ll mod = 1e9 + 7;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> adj[n + 1];

    for (ll i = 0; i < m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].pb({y, z});
        // For undirected graph: adj[y].pb({x, z});
    }

    // Dijkstra's algorithm
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n + 1, INF);
    
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            ll v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF)
        cout << "No valid path found" << endl;
    else
        cout << dist[n] << endl;  // Minimum distance from node 1 to node n
}
