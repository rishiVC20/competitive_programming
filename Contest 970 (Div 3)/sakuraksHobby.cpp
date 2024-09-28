// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long 
// // #define pb push_back 
// // #define onebit(x) __builtin_popcountll(x)
// // #define vi vector<ll>
// // #define YES cout<<'Y'<<'E'<<'S'<<endl
// // #define NO cout<<'N'<<'O'<<endl  

// // const ll mod = 1e9+7;

// // class Disjoint{
// //     vector<ll>size,rank,parent;
// // public:
// //     Disjoint(ll n){
// //         size.resize(n+1,1);
// //         parent.resize(n+1);
// //         rank.resize(n+1,0);
// //         for(ll i=0; i<=n; i++)
// //             parent[i]=i;
// //     }
// //     ll findParent(ll node){
// //         if(node==parent[node])
// //             return node;
// //         return parent[node]=(findParent(parent[node]));
// //     }
// //     void unionByRank(ll u, ll v){
// //         ll ulp_u=findParent(u);
// //         ll ulp_v=findParent(v);
// //         if(ulp_u == ulp_v) return;
// //         if(rank[ulp_u]<rank[ulp_v]){
// //             parent[ulp_u]=ulp_v;
// //         }
// //         else if(rank[ulp_u]>rank[ulp_v]){
// //             parent[ulp_v]=ulp_u;
// //         }
// //         else{
// //             parent[ulp_v]=ulp_u;
// //             rank[ulp_u]++;
// //         }
// //     }
// //     void unionBySize(ll u, ll v){
// //         ll ulp_u=findParent(u);
// //         ll ulp_v=findParent(v);
// //         if(ulp_u == ulp_v) return;
// //         if(size[ulp_u]<size[ulp_v]){
// //             parent[ulp_u]=ulp_v;
// //             size[ulp_v]+=size[ulp_u];
// //         }
// //         else{
// //             parent[ulp_v]=ulp_u;
// //             size[ulp_u]+=size[ulp_v];
// //         }
// //     }
// // };
// // ll mul (ll a, ll b, ll m=mod)
// // {
// //     a = a % m;
// //     b = b % m;
// //     return (((a * b) % m) + m) % m;
// // }
// // ll LCM(ll a, ll b)
// // {
    
// //     a = (a*b)/(__gcd(a,b));
// //     return a;
// // }
// // bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
// // {
// //     return a.second < b.second;
// // }
// // ll power(ll base, ll exponent)
// // {
// //     if (exponent < 0)
// //     {
// //         return 0;
// //     }
// //     ll ans = 1;
// //     while (exponent)
// //     {
// //         if (exponent%2==0)
// //         {
// //             base = (base*base) % mod;
// //             exponent = exponent/2;
// //         }
// //         else
// //         {
// //             ans = (ans*base) % mod;
// //             exponent--;
// //         }
// //     }
// //     return ans;
// // }

// // void dfs(vi &dp, vi &a, ll &cn, vector<bool> &vis, string s,ll i){
// //     if(vis[i]==true){
// //         return;
// //     }
// //     // if(dp[a[i]] != -1){
// //     //     // cout<<'k';
// //     //     // if(s[i]=='0')
// //     //     //     cn++;
// //     //     cn += dp[a[i]];
// //     //     return;
// //     // }
// //     vis[i]=true;
// //     ll p=a[i];
// //     if(!vis[p]){
// //         if(s[p]=='0')
// //             cn++;
// //         dfs(dp,a,cn,vis,s,p);    
// //     }
// //     dp[p]=cn;
// // }

// // int main() {
// //     ll t;
// //     cin>>t;
// //     while (t--)
// //     {
// //         ll n;
// //         cin>>n;
// //         vi a;
// //         for(ll i=0; i<n; i++){
// //             ll x;cin>>x;
// //             x--;
// //             a.pb(x);
// //         }
// //         string s;
// //         cin>>s;

// //         vi dp(n,-1);
// //         for(ll i=0; i<n; i++){
// //             if(dp[i]==-1){
// //                 vector<bool>vis(n,false);
// //                 ll cn=(s[i]=='0')?1:0;
// //                 dfs(dp,a,cn,vis,s,i);
// //             }
            
// //             // cout<<cn<<' ';
// //             // if(s[i]=='0')
// //             //     cn--;
// //             // dp[a[i]]=cn;
// //         }

// //         for(auto i:dp)
// //             cout<<i<<' ';
// //         cout<<endl;    
// //     }
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define vi vector<ll>

// const ll mod = 1e9+7;

// void iterativeDFS(vi &dp, vi &a, string &s, ll start) {
//     stack<ll> stk;
//     vector<bool> vis(dp.size(), false);
//     stk.push(start);
//     ll black_count = 0;

//     // Start DFS using stack
//     while (!stk.empty()) {
//         ll node = stk.top();
//         stk.pop();

//         if (vis[node]) continue;
//         vis[node] = true;

//         if (s[node] == '0') black_count++;

//         ll next_node = a[node];
//         if (!vis[next_node]) {
//             stk.push(next_node);
//         }
//     }

//     // Set dp values for all visited nodes
//     for (ll i = 0; i < vis.size(); i++) {
//         if (vis[i]) {
//             dp[i] = black_count;
//         }
//     }
// }

// int main() {
//     ll t;
//     cin >> t;
//     while (t--) {
//         ll n;
//         cin >> n;
//         vi a(n);
//         for (ll i = 0; i < n; i++) {
//             cin >> a[i];
//             a[i]--; // Convert to 0-based indexing
//         }
//         string s;
//         cin >> s;

//         vi dp(n, -1);

//         // Calculate F(i) for each index
//         for (ll i = 0; i < n; i++) {
//             if (dp[i] == -1) {
//                 iterativeDFS(dp, a, s, i);
//             }
//         }

//         // Output results
//         for (auto i : dp) {
//             cout << i << ' ';
//         }
//         cout << endl;
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
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            x--;
            a.pb(x);
        }
        string s;
        cin>>s;
        vector<bool>vis(n,false);
        vi d(n);
        for(ll i=0; i<n; i++){
            if(vis[i])
                continue;
            ll x=i;
            vi c;
            while(!vis[x]){
                c.pb(x);
                vis[x]=true;
                x=a[x];
            }
            ll cn=0;
            for(auto i:c){
                cn += (s[i]=='0');
            }
            for(auto i:c){
                d[i]=cn;
            }
        }
        for(ll i=0; i<n; i++)
            cout<<d[i]<<' ';
        cout<<endl;    
    }
    return 0;
}