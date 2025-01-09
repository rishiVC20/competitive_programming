// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
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
        ll n,x,k;
        cin>>n>>x>>k;

        string a;
        cin>>a;     

        if(n==2 && a[0]=='1' && a[1]=='0' && k==1){
            cout<<1<<endl;
            continue;
        } 

        if(n==1){
            cout<<1<<endl;
            continue;
        }

        ll u=0,v=0;
        bool f=true;
        ll h=-1,j=-1;
        for(ll i=0; i<n; i++){
            // v += (a[i]=='1');
            // if(a[i]=='0'){
            //     if(v > 0){
            //         f=false;
            //     }
            //     u++;
            // }
            if(a[i]=='1' && h==-1){
                h=i;
            }
            if(a[i]=='0'){
                // cout<<i<<' ';
                j=i;
            }
            if(a[i]=='1'){
                v++;
                f=false;
            }
            if(a[i]=='0' ){
                u++;
            }

        }
        ll m=0;
        bool g=false;
        for(ll i=0; i<n; i++){
            if(a[i]=='0' && g==true){
                m++;
            }
            if(a[i]=='1'){
                g=true;
                
            }
        }
        if(m==1){
            ll s=-1;
            for(ll i=0; i<n; i++){
                if(a[i]=='1t'){
                    s=i;
                    break;
                }
            }
            if(a[s+1]=='0'){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
            continue;
        }
        if(h==-1 || j==-1){
            cout<<1<<endl;
            continue;
        }

        if(j < h){
            cout<<1<<endl;
            continue;
        }

        // cout<<"hi";
        // if(u==1 && a[1]=='0' && x>=1 && k==1){
        //     cout<<1<<endl;
        //     continue;
        // }
        cout<<2<<endl;
    }
    return 0;
}