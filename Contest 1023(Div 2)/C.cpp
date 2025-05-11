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

const ll mod = 1e18;

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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        bool f=true;
        bool kg=true;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(x>k){
                f=false;
            }
            if(s[i]=='0'){
                kg=false;
            }
        }
        if(!f){
            cout<<"No"<<endl;
            continue;
        }

        auto sum=[&](vi &arr)->ll{
            ll sm=0;
            ll cur=0;
            for(ll i=0; i<(ll)arr.size(); i++){
                cur+=arr[i];
                if(cur<0){
                    cur=0;
                }
                sm=max(sm,cur);
            }
            return sm;
        };

       

        ll mx=0;
        vi arr;
        map<ll,ll>mp;
        for(ll i=0; i<n; i++){
            if(s[i]=='1'){
                arr.pb(a[i]);
            }
            else{
                if(arr.size()){
                    mx=max(mx,sum(arr));
                    arr.clear();
                }
            }
        }
        if(arr.size()){
            mx=max(mx,sum(arr));
            arr.clear();
        }

        if(kg){
            if(mx==k){
                cout<<"Yes"<<endl;
                for(auto x:a){
                    cout<<x<<' ';
                }
                cout<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
            continue;
        }

        if(mx>k){
            cout<<"No"<<endl;
            continue;
        }
        if(mx==k){
            cout<<"Yes"<<endl;
            for(ll i=0; i<n; i++){
                if(s[i]=='0'){
                    cout<<-1LL*mod<<' ';
                }
                else{
                    cout<<a[i]<<' ';
                }
            }
            cout<<endl;
            continue;
        }

        cout<<"Yes"<<endl;
        ll ck=0;
        ll cn=0;
        ll pt;
        for(ll i=0; i<n; i++){
            if(s[i]=='0'){
                pt=i;
                break;
            }
        }

        ll sum1=0;
        ll sum2=0;
        ll lp=0;
        for(ll i=pt-1; i>=0; i--){
            if(s[i]=='1'){
                sum1+=a[i];
                lp=max(lp,sum1);
            }
            else{
                break;
            }
        }
        ll rp=0;
        for(ll i=pt+1; i<n; i++){
            if(s[i]=='1'){
                sum2+=a[i];
                rp=max(rp,sum2);
            }
            else{
                break;
            }
        }

        ll sump=0;
        ll t1=max(lp,rp);
        ll t2=min(lp,rp);
        // cout<<t2<<' '<<t1<<" t"<<endl;
        if(t2>=0){
            sump=t1+t2;
        }
        else if(t2<=0 && t1>=0){
            sump=t1;
        }
        else{
            sump=0;
        }
        ll tk=k-sump;
        a[pt]=tk;
        // cout<<pt<<' '<<sump<<"h ";
        for(ll i=0; i<n; i++){
            if(s[i]=='0' && i!=pt){
                cout<<-1LL*mod<<' ';
            }
            else{
                cout<<a[i]<<' ';
            }
        }

        cout<<endl;

        
    }
    return 0;
}