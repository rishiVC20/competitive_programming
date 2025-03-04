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

vi dx={1,-1,0,0};
vi dy={0,0,1,-1};

void dfs(ll i, ll j, vector<vector<char>> &a, vector<vector<bool>> &vis){
    if(vis[i][j])
        return;
    
    vis[i][j]=true;

    for(ll k=0; k<4; k++){
        ll nx=dx[k]+i,ny=dy[k]+j;
        if(nx>=0 && nx<a.size() && ny>=0 && ny<a[0].size() && !vis[nx][ny]){
            dfs(nx,ny,a,vis);
        }
    }
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

        vector<vector<char>>a(n,vector<char>(m));
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                char x;cin>>x;
                a[i][j]=x;
                vis[i][j]=(x=='#');
            }
        }
        
        // auto dfs=[](ll i, ll j, auto &&dfs_ref)->void{
        //     if(vis[i][j])
        //         return;
            
        //     vis[i][j]=true;
        //     for(ll k=0; k<4; k++){
        //         ll nx=dx[k]+i,ny=dy[k]+j;
        //         if(nx>=0 && nx<n && ny>=0 && ny<m){
        //             dfs(nx,ny,dfs_ref);
        //         }
        //     }
        // };
        // for(auto i:vis){
        //     for(auto j:i){
        //         cout<<j<<' ';
        //     }
        //     cout<<endl;
        // }

        ll cn=0;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(!vis[i][j]){
                    cn++;
                    dfs(i,j,a,vis);
                }
            }
        }

        cout<<cn<<endl;
    }
    return 0;
}