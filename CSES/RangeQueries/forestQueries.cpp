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

ll check(ll u, ll v, ll w, ll x, vector<vi> &a){
    ll p=x;
    ll ch=a[w][x];
    ll t,s;
    if(u>0){
        t=a[u-1][p];
    }
    else{
        t=0;
    }
    if(v>0){
        s=a[w][v-1];
    }
    else{
        s=0;
    }

    ll m=0;

    if(u>0 && v>0){
        m=a[u-1][v-1];
    }

    return ch - t - s + m;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,q;
        cin>>n>>q;

        vector<vi>a(n,vi(n));

        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                char x;cin>>x;
                if(x=='*'){
                    a[i][j]=1;
                }
                else{
                    a[i][j]=0;
                }
            }
        }       

        for(ll i=0; i<n; i++){
            for(ll j=1; j<n; j++){
                a[i][j] += a[i][j-1];
            }
        }

        for(ll i=0; i<n; i++){
            for(ll j=1; j<n; j++){
                a[j][i] += a[j-1][i];
            }
        }
        // for(auto i:a){
        //     for(auto j:i){
        //         cout<<j<<' ';
        //     }
        //     cout<<endl;
        // }
        while(q--){
            ll u,v,w,x;
            cin>>u>>v>>w>>x;
            u--,v--,w--,x--;

            ll k=check(u,v,w,x,a);

            cout<<k<<endl;
        }
    }
    return 0;
}