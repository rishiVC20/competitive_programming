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


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,x;
        cin>>n>>x;
        x--;
        vector<vi>adj(n);
        vi deg(n,0);
        for(ll i=0; i<n-1; i++){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
            deg[u]++;
            deg[v]++;
        }

        queue<ll>q;
        bool m=false;
        for(ll i=0; i<n; i++){
            if(deg[i]==1){
                q.push(i);
                if(i==x){
                    m=true;
                }
            }
        }
        if(m){
            cout<<"Ayush"<<endl;
            continue;
        }

        bool f=true;
        while(!q.empty()){
            queue<ll>t;
            bool gg=true;
            while(!q.empty()){
                ll p=q.front();
                q.pop();
                // if()
                bool d=true;
                for(auto i:adj[p]){
                    if(i==x){
                        d=false;
                        break;
                    }
                }
                if(d){
                    gg=false;
                    f=!f;
                    for(auto i:adj[p]){
                        deg[i]--;
                        if(deg[i]==1){
                            t.push(i);
                        }
                    }
                }
                else{
                    t.push(p);
                }
            }
            if(gg){
                // cout<<"j ";
                for(ll i=0; i<(ll)t.size()-1; i++){
                    f=!f;
                }
                break;
            }
            q=t;
        }

        if(f){
            cout<<"Ayush"<<endl;
        }
        else{
            cout<<"Ashish"<<endl;
        }

    }
    return 0;
}