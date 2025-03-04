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

        set<ll>st;vi b(n,0);
        for(ll i=0; i<n; i++){
            if(st.find(a[i])==st.end()){
                st.insert(a[i]);
                b[i]=a[i];
            }
        }
        vi d;
        ll cn=st.size();
        for(ll i=1; i<=n; i++){
            if(st.find(i)==st.end()){
                d.pb(i);
            }
        }
        sort(d.rbegin(),d.rend());
        ll j=0;
        vector<bool>ff(d.size(),false);
        for(ll i=0; i<n; i++){
            if(b[i]==0){
                while(j<d.size() && (i+1)==d[j]){
                    j++;
                }
                if(j<d.size()){
                    b[i]=d[j];
                    ff[j]=true;
                    j++;
                }
            }
        }
        j=0;
        for(ll i=0; i<n; i++){
            if(b[i]==0){
                while(j<d.size() && ff[j]==true){
                    j++;
                }
                if(j<d.size()){
                    b[i]=d[j];
                    j++;
                }
            }
        }
        // for(auto i:b)
        //     cout<<i<<' ';
        bool f=true;
        for(ll i=1; i<=n; i++){
            if(b[i-1]==i || b[i-1]==0 || b[i-1]>n){
                f=false;
                break;
            }
        }
        // cout<<f<<' ';
        if(f){
            // cout<<"hi ";
            cout<<st.size()<<endl;
            for(auto i:b)
                cout<<i<<' ';
            cout<<endl;
            continue;    
        }

        set<ll>p;
        vi k1(n,0);
        vi d1;
        for(ll i=n-1; i>=0; i--){
            if(p.find(a[i])==p.end()){
                p.insert(a[i]);
                k1[i]=a[i];
            }
        }
        for(ll i=1; i<=n; i++){
            if(p.find(i)==p.end()){
                d1.pb(i);
            }
        }
        sort(d1.begin(),d1.end());
        // for(auto i:d1)
        //     cout<<i<<' ';
        j=0;
        vector<bool>fd(d1.size(),false);
        for(ll i=n-1; i>=0; i--){
            if(k1[i]==0){
                while(j<d1.size() && (i+1)==d[j]){
                    // cout<<i<<' ';
                    j++;
                }
                if(j<d1.size()){
                    k1[i]=d1[j];
                    fd[j]=true;
                    j++;
                }
            }
        }
        // for(auto i:k1)
        //     cout<<i<<' ';
        j=0;
        for(ll i=n-1; i>=0; i--){
            if(k1[i]==0){
                while(j<d1.size() && fd[j]==true){
                    j++;
                }
                if(j<d1.size()){
                    k1[i]=d1[j];
                    j++;
                }
            }
        }
        cout<<p.size()<<endl;
        for(auto i:k1)
            cout<<i<<' ';
        cout<<endl;    
    }
    return 0;
}