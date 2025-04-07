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


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vi a(n+1),b(n+1);
        Disjoint d(n);
        for(ll i=1; i<=n; i++){
            ll x;cin>>x;
            a[i]=x;
        }
        set<ll>st;
        vi cp(n+1);
        ll tp=0;
        for(ll i=1; i<=n; i++){
            ll k=a[i],p=a[k];
            d.unionBySize(k,p);
            
        }
        for(ll i=1; i<=n ;i++){
            ll k=a[i],p=a[k];
            ll r=d.findParent(k);
            if(st.find(r)==st.end()){
                tp++;
                cp[k]=tp,cp[p]=tp;
                cp[r]=tp;
            } 
            else{
                cp[k]=cp[r],cp[p]=cp[r];
            }
            st.insert(r);
        }
        for(ll i=1; i<=n; i++){
            ll x;cin>>x;
            b[i]=x;
        }
        map<ll,ll>mp;
        for(ll i=1; i<=n; i++){
            ll m=cp[a[i]];
            mp[m]++;
        }
        // for(ll i=1; i<=n; i++){
        //     cout<<cp[a[i]]<<' ';
        // }
        // vvp dp;
        // for(auto i:mp){
        //     dp.pb({i.first,i.second});
        //     // cout<<i.first<<' '<<i.second<<' ';
        // }
        // for(ll i=1; i<(ll)dp.size(); i++){
        //     dp[i].second+=dp[i-1].second;
        // }
        // map<ll,ll>m2;
        // for(auto i:dp){
        //     m2[i.first]=i.second;
        //     // cout<<i.first<<' '<<i.second<<' ';
        // }
        vi ans(n+1);
        set<ll>sp;
        ll ff=0;
        for(ll i=1; i<=n; i++){
            ll k=b[i];
            ll t=cp[k];
            if(sp.find(t)==sp.end()){
                ff+=mp[t];
            }
            sp.insert(t);
            ans[i]=ff;
        }
        for(ll i=1; i<=n; i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}