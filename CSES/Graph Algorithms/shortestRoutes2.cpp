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


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,m,q;
        cin>>n>>m>>q;

        vector<vi>a(n,vi(n,LLONG_MAX));
        // cout<<INT_MAX;
        for(ll i=0; i<n; i++){
            a[i][i]=0;
        }

        for(ll i=0; i<m; i++){
            ll u,v,d;
            cin>>u>>v>>d;
            u--,v--;
            a[u][v]=min(d,a[u][v]);
            a[v][u]=a[u][v];
        }

        for(ll t=0; t<n; t++){
            for(ll i=0; i<n; i++){
                for(ll j=0; j<n; j++){
                    // cout<<a[i][j]<<' ';
                    if(a[i][t]!=LLONG_MAX && a[t][j]!=LLONG_MAX)
                        a[i][j]=min(a[i][j],a[i][t]+a[t][j]);
                    a[j][i]=a[i][j];
                }
                // cout<<endl;
            }
        }

        while(q--){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            if(a[u][v]==LLONG_MAX){
                cout<<-1<<endl;
            }
            else{
                cout<<a[u][v]<<endl;
            }
        }
    }
    return 0;
}