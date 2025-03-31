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

        vi a;
        bool f=true;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            // if(i!=0 && x%2!=(ll)a.back()%2){
            //     f=false;
            // }
            a.pb(x);
        }
        for(ll i=1; i<n; i++){
            if(a[i]%2!=a[i-1]%2){
                f=false;
                break;
            }
        }
        sort(all(a));
        if(f){
            cout<<(ll)a.back()<<endl;
            continue;
        }

        vi a1,a2;
        for(ll i=0; i<n-1; i++){
            if(a[i]%2==0){
                a1.pb(a[i]);
            }
            else{
                a2.pb(a[i]);
            }                
        }
        // if((ll)a1.size()==0){
        //     ll px=accumulate(a2.begin(),a2.end(),0LL);
        //     cout<<px+(ll)a.back()<<endl;
        //     continue;
        // }
        // else if((ll)a2.size()==0){
        //     ll px=accumulate(a1.begin(),a1.end(),0LL);
        //     cout<<px+(ll)a.back()<<endl;
        //     continue;
        // }
        
        ll k=(ll)a.back();
        // ll k=accumulate(a.begin(),a.end(),0LL);
        ll cp=0;
        if(k%2==0){
            for(ll i=0; i<(ll)a2.size(); i++){
                cp+=a2[i]-1;
            }
            if((ll)a2.size()>0){
                cp++;
            }
            for(ll i=0; i<(ll)a1.size(); i++){
                cp+=a1[i];
            }
        }
        else{
            for(ll i=0; i<(ll)a1.size(); i++){
                cp+=a1[i];
            }
            // if((ll)a2.size()>0){
            //     cp--;
            // }
            for(ll i=0; i<(ll)a2.size(); i++){
                cp+=a2[i]-1;
            }
            // if((ll)a2.size()>0){
            //     cp++;
            // }
        }
        // cout<<k<<' '<<cp<<' ';
        // cout<<k-(ll)a2.size()+1<<endl;
        cout<<k+cp<<endl;
    }
    return 0;
}