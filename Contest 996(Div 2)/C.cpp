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
        ll n,m;
        cin>>n>>m;

        string s;
        cin>>s;

        vector<vi>v(n,vi(m));
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cin>>v[i][j];
            }
            
        }

        vi c(n),d(m);

        for(ll i=0; i<m; i++){
            ll k=0;
            for(ll j=0; j<n; j++){
                k += v[j][i];
            }
            d[i]=k;
        }       
        for(ll i=0; i<n; i++){
            ll k=0;
            for(ll j=0; j<m; j++){
                k += v[i][j];
            }
            c[i]=k;
        }

        ll i=0,j=0;
        ll k=0;
        while(i<=n-1 && j<=m-1 && k<(n+m-2)){
            char ch=s[k];
            // cout<<ch<<' ';
            if(ch=='R'){
                v[i][j]=d[j]*(-1);
                c[i] += v[i][j];
                d[j]=0;
                j++;
            }
            else{
                v[i][j]=c[i]*(-1);
                d[j] += v[i][j];
                c[i]=0;
                i++;
            }
            k++;
        }

        if(c[n-1] != 0){
            v[n-1][m-1]= (-1)*c[n-1];
        }
        else if(d[m-1] != 0){
            v[n-1][m-1] = (-1)*d[m-1];
        }

        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cout<<v[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}