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

bool dfs(ll par, ll nd, vector<vi> &adj, vector<bool> &vis,set<ll> &st, vi &v){

    if(vis[nd]==1){
        return false;
    }

    vis[nd]=1;
    st.insert(nd);
    v.pb(nd);
    // cout<<nd<<' ';
    for(auto i:adj[nd]){
        if(i!=par){
            if(!dfs(nd,i,adj,vis,st,v))
                return false;
        }
    }
    // cout<<nd<<' ';
    // for(ll i=0; i<26; i++){
    //     if(adj[nd][i]==1 && i!=par ){
    //         if(!dfs(nd,i,adj,vis,st,v)){
    //             return false;
    //         }
    //     }
    // }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        string s;
        cin>>s;

        ll n=s.size();
        set<ll>st;
        for(auto i:s){
            st.insert(i-'a');
        }
        if(n==1){
            YES;
            for(ll i=0; i<26; i++){
                char d=i+'a';
                cout<<d;
            }
            cout<<endl;
            continue;
        }
        // if(st.size()==3){
        //     vector<char>e;
        //     set<ll>p;
        //     for(ll i=0; i<n; i++){
        //         if(p.find(s[i]-'a')==p.end()){
        //             p.insert(s[i]-'a');
        //             e.pb(s[i]);
        //         }
        //     }
        //     for(ll i=0; i<26; i++){
        //         if(p.find(i)==p.end()){
        //             char d=i+'a';
        //             e.pb(d);
        //         }
        //     }
        //     for(auto i:e)
        //         cout<<i;
        //     continue;
        // }
        vector<vi>adj(26);

        for(ll i=0; i<n-1; i++){
            ll k1=s[i]-'a',k2=s[i+1]-'a';
            bool f=true;
            for(auto j:adj[k1]){
                if(j==k2){
                    f=false;
                }
            }
            if(f){
                adj[k1].pb(k2);
            }
            f=true;
            for(auto j:adj[k2]){
                if(j==k1){
                    f=false;
                }
            }
            if(f){
                adj[k2].pb(k1);
            }

        }
        ll m=-1;
        ll ck=0;
        bool r=true;

        for(auto i:adj){
            if(i.size()==1){
                m=ck;
            }   
            if(i.size()>2){
                r=false;
                break;
            }
            // for(auto j:i)
            //     cout<<j<<' ';
            // cout<<endl;    
            ck++;
        }
        // cout<<endl;
        // cout<<m<<' ';
        if(m==-1 || !r){
            NO;
            continue;
        }
        vector<bool>vis(26,0);
        set<ll>cn;
        vi v;
        
        bool d=dfs(-1,m,adj,vis,cn,v);

        if(!d){
            NO;
            continue;
        }
        // cout<<"hi ";
        vector<char>g;
        for(auto i:v){
            // cout<<i<<' ';
            g.pb(i+'a');
        }

        for(ll i=0; i<26; i++){
            if(cn.find(i)==cn.end()){
                char f=i+'a';
                g.pb(f);
            }
        }
        YES;
        for(auto i:g){
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}