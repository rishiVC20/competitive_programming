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

unordered_map<string,int>mp;

void mapping(){
    mp["1111011"]=9;
    mp["1111111"]=8;
    mp["1010010"]=7;
    mp["1101111"]=6;
    mp["0111010"]=4;
    mp["1101011"]=5;
    mp["1011011"]=3;
    mp["1011101"]=2;
    mp["0010010"]=1;
    mp["1110111"]=0;

}

bool check(string s, ll &k){
    if(mp.find(s)!=mp.end()){
        return true;
    }

    vi vt(10);
    for(auto i:mp){
        ll t=i.second;
        string g=i.first;
        ll cnt=0;
        for(ll j=0; j<7; j++){
            if(s[j]=='1' && g[j]=='0'){
                return false;
            }
            if(s[j]=='0' && g[j]=='1'){
                cnt++;
            }
            vt[t]=cnt;
        }
        
            
    }
    // if()
    ll mx=-1;
    ll d=-1;
    for(ll i=9; i>=0; i--){
        ll p=vt[i];
        if(p==-1){
            continue;
        }
        if(mx==-1){
            mx=p;
            d=i;
            continue;
        }
        if(mx>p){
            mx=p;
            d=i;
        }
        // mx=min(mx,p);
    }
    ll t=k;
    if(mx<=k){
        k-=mx;
        return true;
    }
    
    return false;
    // return mx<=k;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    mapping();
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;
        vector<string>v;
        for(ll i=0; i<n; i++){
            string s;
            cin>>s;
            v.pb(s);
        }

        bool f=true;
        for(ll i=0; i<n; i++){
            if(!check(v[i],k)){
                f=false;
                break;
            }
        }
        if(!f){
            cout<<-1<<endl;
            continue;
        }


    }
    return 0;
}