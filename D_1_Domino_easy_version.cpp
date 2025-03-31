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
        ll n,m,k;
        cin>>n>>m>>k;
        ll t=n*m/2-k;
        if(n==1){
            ll r=k*2;
            if(r==m){
                YES;
            }
            else{
                NO;
            }
            continue;
        }
        if(m==1){
            if(k>0)
                NO;
            else if(k==0)
                YES;
            continue;
        }
        if(n&1){
            ll p=((k*2)/m);
            if(p>n){
                NO;
                continue;
            }
            k-=m/2;
            if(k<0 || k&1 || t&1){
                NO;
            }
            else{
                YES;
            }
            // cout<<p<<' ';
            // ll t=(k-p*(m/2))%m;
            // // cout<<t<<' ';
            // if(p%2==0 || t%2!=0){
            //     NO;
            // }
            // else{
            //     YES;
            // }
        }
        else if(m&1){
            
            t-=n/2;
            if(t<0 || t&1 || k&1){
                NO;
            }
            else{
                YES;
            }
        }
        else{
            ll t=k%2;
            if(k%2==0 && t%2==0){
                YES;
                
            }
            else{
                NO;
            }
        }
    }
    return 0;
}