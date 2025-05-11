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
        ll n,x;
        cin>>n>>x;

        if(n==1 && x==0){
            cout<<-1<<endl;
            continue;
        }
        if(n==1){
            cout<<x<<endl;
            continue;
        }
        ll d=onebit(x);


        if(d>=n){
            cout<<x<<endl;
            continue;
        }

        ll df=n-d;
        ll cn=x;
        // cout<<df<<' ';
        if(df%2==0){
            for(ll i=0; i<df; i++){
                cn+=power(2,0);
            }
        }
        else{
            // cout<<"hi ";
            ll k=0;
            for(ll i=0; i<df-1; i++){
                cn+=power(2,0);
                k=1;
            }
            // cout<<cn<<' ';
            if(d>1){
                cn+=power(2,0);
                cn+=power(2,0);
            }
            else if (d==1){
                bitset<32>b(x);
                for(ll i=0; i<32; i++){
                    if(b[i]==0){
                        k=i;
                        break;
                    }
                }
                cn+=power(2,k);
                cn+=power(2,k);
            }
            else{
                if(df>1){
                    cn+=power(2,1);
                    cn+=power(2,1);
                }
                else{
                    cn+=power(2,0);
                    cn+=power(2,0);
                }
            }
            
            // else if(df==1){
            //     // cout<<"kj ";
            //     if(n>2){
            //         cn+=power(2,0);
            //         cn+=power(2,0);
            //     }
            //     else{
            //         bitset<32>b(x);
            //         ll m;
            //         for(ll i=0; i<32; i++){
            //             if(b[i]==0){
            //                 m=i;
            //                 break;
            //             }
            //         }
            //         cn+=power(2,m);
            //         cn+=power(2,m);
            //     }
            // }
            // else if(d>1){
            //     // cout<<"gh ";
            //     cn+=power(2,0);
            //     cn+=power(2,0);
            // }
            // else{
            //     bitset<32>b(x);
            //     ll m;
            //     for(ll i=1; i<32; i++){
            //         if(b[i]==0){
            //             m=i;
            //             break;
            //         }
            //     }
            //     cn+=power(2,m);
            //     cn+=power(2,m);
            // }

        }

        cout<<cn<<endl;
    }
    return 0;
}