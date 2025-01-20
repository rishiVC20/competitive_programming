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

bool cs=false;
vi dx={1,-1,0,0};
vi dy={0,0,1,-1};
ll n,m;
void dfs(ll i, ll j, vector<string> &s, ll pi, ll pj, vector<vi> &v, char ch){
    if(i>=n || j>=m || i<0 || j<0){
        return;
    }
    if(s[i][j] != ch)
        return;

    if(v[i][j]==1){
        cs=true;
        return;
    }

    v[i][j]=1;

    for(ll k=0; k<4; k++){
        ll fx=i+dx[k],fy=j+dy[k];

        if(fx==pi && fy==pj)
            continue;
        dfs(fx,fy,s,i,j,v,ch);    
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        // ll n,m;
        cin>>n>>m;

        vector<string>s;
        for(ll i=0; i<n; i++){
            string k;
            cin>>k;
            s.pb(k);
        }

        bool f=false;
        for(ll i=0; i<n; i++){
            // vector<vi>v(n,vi(m,0));
            for(ll j=0; j<m; j++){
                // if(v[i][j]==0)
                vector<vi>v(n,vi(m,0));
                dfs(i,j,s,-1,-1,v,s[i][j]);
                // queue<pair<ll,ll>>q;
                // vector<vi>v(n,vi(m,0));
                // vector<vi>ss(n,vi(m,0));
                // q.push({i,j});
                // v[i][j]=0;
                // while(!q.empty()){
                //     auto fr=q.front();
                //     ll x=fr.first,y=fr.second;
                //     q.pop();
                //     ss[x][y]=1;
                //     v[x][y]=1;
                //     if(x+1 < n && s[x+1][y]==s[x][y] && ss[x+1][y]==0){
                //         if(v[x+1][y]==0){
                //             f=true;
                //             break;
                //         }
                //         q.push({i+1,j});
                //     }
                //     if(x-1>=0 && s[x-1][y]==s[x][y] && ss[x-1][y]==0){
                //         if(v[x-1][y]==0){
                //             f=true;
                //             break;
                //         }
                //         q.push({i-1,j});
                //     }

                // }
            }
        }

        if(cs)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}