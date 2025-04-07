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
        string s;
        cin>>s;
        ll n=(ll)s.size();

        ll i=0,j=n-1;
        vector<ll>d;
        while(i<j){
            if(s[i]!=s[j]){
                d.push_back(i);
                d.push_back(j);
            }
            i++;
            j--;
        }
        if((ll)d.size() == 0){
            cout<<0<<endl;
            continue;
        }

        vi f1,f2;
        for(ll i=0; i<(ll)d.size(); i++){
            ll g=d[i];
            if(g%2==0){
                f1.push_back(g);
            }
            else{
                f2.push_back(g);
            }
        }
        sort(all(f1));
        sort(all(f2));
        if((ll)(f1.size())%2==1 || (ll)(f2.size())%2==1){
            cout<<-1<<endl;
            continue;
        }
        // for(auto i:f1){
        //     cout<<i<<' ';
        // }
        // for(auto i:f2){
        //     cout<<i<<' ';
        // }
        ll cp=0;
        for(ll i=1; i<(ll)f1.size(); i+=2){
            char h1=s[f1[i]];
            char h2=s[f1[i-1]];
            ll pp=abs(h1-h2)/2+1;
            cp+=pp;
        }
        for(ll i=1; i<(ll)f2.size(); i+=2){
            char h1=s[f2[i]];
            char h2=s[f2[i-1]];
            ll pp=abs(h1-h2)/2+1;
            cp+=pp;
        }
        i=0,j=(ll)f1.size()-1;
        ll dp=0;
        while(i<j){
            ll h1=abs(s[f1[i]]-s[f1[j]])/2+1;
            dp+=h1;
            i++;
            j--;
        }
        i=0,j=(ll)f2.size()-1;
        while(i<j){
            ll h2=abs(s[f2[i]]-s[f2[j]])/2+1;
            dp+=h2;
            i++;
            j--;
        }
        // cout<<cp<<' '<<dp<<' ';
        cout<<min(cp,dp)/2<<endl;
    }
    return 0;
}