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
        vi a,b;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }
        ll cv=0;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            b.pb(x);
            if(b[i]==a[i]){
                cv++;
            }
        }
        if(a==b){
            cout<<-1<<endl;
            continue;
        }
        if(n%2==0 && cv>=1){
            cout<<-1<<endl;
            continue;
        }
        if(n%2!=0 && cv>1){
            cout<<-1<<endl;
            continue;
        }
        map<pair<ll,ll>,ll>mp;
        for(ll i=0; i<n; i++){
            mp[{a[i],b[i]}]++;
        }
        bool f=true;
        for(ll i=0; i<n; i++){
            if(mp.find({b[i],a[i]})==mp.end()){
                f=false;
                break;
            }
        }
        // cout<<f<<' ';
        
        if(!f){
            cout<<-1<<endl;
            continue;
        }
        vvp v;
        if(cv==1){
            ll ind;
            ll p=n/2;
            for(ll i=0; i<n; i++){
                if(a[i]==b[i]){
                    ind=i;
                    break;
                }
            }
            // cout<<"g ";
            // cout<<ind<<' ';
            if(ind!=p){
                swap(a[ind],a[p]);
                swap(b[ind],b[p]);
                v.pb({ind,p});
            }
        }
        
        ll cn=0;
        map<ll,ll>m1;
        for(ll i=0; i<n; i++){
            m1[b[i]]=i;
        }
        
        for(ll i=0; i<n/2; i++){
            if(a[i]!=b[n-i-1]){
                ll t=m1[a[i]];
                ll p=b[n-i-1];
                m1[b[n-i-1]]=t;
                m1[a[i]]=n-i-1;
                // b[t]=b[n-i-1];
                // b[n-i-1]=a[i];
                swap(b[t],b[n-i-1]);
                swap(a[t],a[n-i-1]);
                v.pb({t,n-i-1});
            }
        }

        cout<<(ll)v.size()<<endl;
        for(auto i:v){
            cout<<i.first+1<<' '<<i.second+1<<endl;
        }
        // cout<<endl;
        // cout<<cn/2+(cn%2)<<endl;
    }
    return 0;
}