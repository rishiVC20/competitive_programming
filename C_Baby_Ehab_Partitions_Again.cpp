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

bool check(ll ind, vi &a, ll sum, ll tar, vector<vi> &dp){
    if(ind==a.size() || sum>tar){
        return false;
    }
    if(sum==tar){
        return true;
    }

    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    bool f1=check(ind+1,a,sum,tar,dp);
    bool f2=check(ind+1,a,sum+a[ind],tar,dp);

    return dp[ind][sum] = f1 || f2;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vi a;
        ll sp=0;
        ll ind=-1;
        ll p=1;
        ll l=0;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(x&1){
                ind=i;
            }
            if(l<x){
                p=i;
                l=x;
            }
            sp+=x;
        }
        // cout<<l<<' ';

        if(sp&1){
            cout<<0<<endl;
            continue;
        }
        ll tar=sp/2;
        vector<vi> dp(n+1,vi (tar+1,-1));
        bool t=check(0,a,0,tar,dp);
        if(t){
            cout<<1<<endl;
            if(ind!=-1)
                cout<<ind+1<<endl;
            else{
                ll kp=-1;
                ll sm=accumulate(all(a),0LL);
                for(ll i=0; i<n; i++){
                    ll tr=sm-a[i];
                    if((tr/2)&1){
                        kp=i+1;
                        break;
                    }
                }
                if(kp==-1){
                    vvp v(n);
                    ll mn=INT_MAX;
                    ll ele=1;
                    for(ll i=0; i<n; i++){
                        bitset<32>p=a[i];
                        for(ll j=0; j<32; j++){
                            if(p[j]){
                                if(mn>j){
                                    mn=j;
                                    ele=i+1;
                                }
                            }
                        }
                    }
                    // sort(all(v));
                    // ll md=n/2;
                    kp=ele;
                }
                cout<<kp<<endl;
            }  
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}