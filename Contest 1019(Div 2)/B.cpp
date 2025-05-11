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
        string s;
        cin>>s;

        vi a,b;
        ll cur=0;
        ll mx=0;
        ll j=-1;
        bool dd=false;
        for(ll i=0; i<n; i++){
            if(s[i]=='0'){
                cur++;
            }
            else{
                cur=0;
            }
            if(cur>mx){
                mx=cur;
                j=i;
            }
            if(s[i]=='1'){
                dd=true;
            }
        }
        if(j==-1){
            cout<<n+1<<endl;
            continue;
        }
        if(dd==false){
            cout<<n<<endl;
            continue;
        }
        
        // if(j==n-1){
        //     reverse(s.begin(),s.end());
        // }
        // else{
            // ll m=0;
            // for(ll i=0; i<n; i++){
            //     if(s[i]=='1'){
            //         m=i;
            //         break;
            //     }
            // }
            // // cout<<m<<' '<<j<<' ';
            // if(m<j){
            //     // string r=s.substr(m,j-m+1);
            //     reverse(s.begin()+m,s.begin()+j+1);
                // cout<<"ho ";
                // string p=s.substr(j+1);
                // s=r+p;
            // }
        // }
        // cout<<s<<' ';
        // cout<<"gi ";
        ll cn=0;
        ll ck=n;
        for(ll i=1; i<n; i++){
            if(s[i]!=s[i-1]){
                cn++;
            }
            if(i==n-1){
                cn++;
            } 
        }
        // if(s[n-1]==s[n-2]){
        //     cn++;
        // }
        // cn++;
        // cout<<cn<<' ';

        if(cn<=2){
            cout<<n+1<<endl;
        }
        else if(cn==3){
            cout<<n+1<<endl;
        }
        else{
            if(s[0]=='0'){
                cn--;
            }
            cout<<n+cn-2<<endl;
        }
    }
    return 0;
}