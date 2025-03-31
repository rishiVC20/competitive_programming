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
struct TrieNode{
    bool flag=false;
    map<char, TrieNode*> children;
    int cnt=0;
    void setEnd(){
        flag=true;
    }
    bool isEnd=false;
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* current = root;
        for (int i=0; i<word.size(); i++) {
            if (current->children.find(word[i]) == current->children.end()) {
                current->children[word[i]] = new TrieNode();
            }
            current = current->children[word[i]];
        }
        current->isEnd = true;
    }

    void erase(string &word) {
        TrieNode *current = root;
        for(int i=0; i<word.size(); i++){
            current=current->children[word[i]];
            current->cnt--;
        }
        current->isEnd=true;
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
        ll n,m;
        cin>>n>>m;
        map<pair<ll,ll>,ll>mp;
        vector<vector<ll>>adj(n);
        for(ll i=0; i<m; i++){
            ll u,v,k;
            cin>>u>>v>>k;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
            mp[{u,v}]=k;
        }

        vector<ll>par(n);
        vector<ll>dis(n,LLONG_MAX);
        vector<bool>vis(n,0);
        dis[0]=0;
        par[0]=-1;
        vis[0]=1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            pair<ll,ll>fr=pq.top();
            ll s=fr.first;
            ll q=fr.second;
            pq.pop();
            // cout<<q<<' ';
            vis[q]=true;
            for(auto j:adj[q]){
                // cout<<q<<' ';
                if(!vis[j]){
                    // cout<<j<<' ';
                    ll g;
                    if(mp.find({q,j})!=mp.end()){
                        g=mp[{q,j}];
                    }
                    else{
                        g=mp[{j,q}];
                    }
                    ll d=s+g;
                    if(d<dis[j]){
                        dis[j]=d;
                        par[j]=q;
                        pq.push({d,j});
                    }
                }
            }
            // cout<<endl;
        }
        // cout<<endl;
        // for(auto i:dis){
        //     cout<<i<<' '; 
        // }
        if(dis[n-1]==LLONG_MAX){
            cout<<-1<<endl;
            continue;
        }

        vector<ll>t;
        t.pb(n-1);
        ll w=par[n-1];
        t.pb(w);
        while(w!=-1){
            ll y=par[t.back()];
            t.pb(y);
            w=y;
        }

        t.pop_back();
        reverse(t.begin(),t.end());

        for(auto i:t){
            cout<<i+1<<' ';
        }
        cout<<endl;
    }
    return 0;
}