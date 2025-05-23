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
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        sort(all(a));

        vi dk(32,0);
        ll mk=0,ele=a[0];
        vi df(n);
        ll prev;
        for(ll i=0; i<n; i++){
            bitset<32>b(a[i]);
            ll cn=0;
            ll mx=0;
            for(ll j=0; j<(ll)b.size(); j++){
                // cn+=(b[j]==1);
                dk[j]+=(b[j]==1);
                cn+=(b[j]==1);
                if(b[j]==1){
                    mx=max(mx,j);
                }
                // cout<<b[j]<<' ';
            }
            // cout<<mx<<' ';
            // cout<<endl;

            // if(mx>mk){
            //     ele=a[i];
            //     mk=mx;
            //     prev=i;
            // }
            // else if(mk==mx){
            //     if(df[prev]>cn){
            //         prev=i;
            //         ele=a[i];
            //     }
            // }
            // df[i]=cn;
            // cout<<a[i]<<' '<<log2(a[i])<<' ';
            
        }
        // for(auto i:dk){
        //     cout<<i<<' ';
        // }
        // cout<<endl;
        ll jp=0;
        for(ll i=n-1; i>=0; i--){
            bitset<32>b(a[i]);
            vi kp=dk;
            ll cn=0;
            for(ll j=0; j<(ll)b.size(); j++){
                ll lp=1LL << j;
                ll on=kp[j];
                ll ze=n-on;
                if(b[j]==1){
                    cn+=ze*lp;
                }
                else{
                    cn+=on*lp;
                }
            }
            // cout<<a[i]<<' '<<cn<<' ';
            if(cn>jp){
                jp=cn,ele=a[i];
            }
        }
        cout<<jp<<endl;
        // cout<<ele<<' ';
        // ll ans=0;
        // for(ll i=0; i<n; i++){
        //     ans+=ele^a[i];
        // }

        // cout<<ans<<endl;
    }
    return 0;
} 