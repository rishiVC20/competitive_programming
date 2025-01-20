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
ll n;
void check(queue<tuple<ll,ll,char>> &q, vector<vector<char>> &v, ll k){
        ll curr=1;
        ll p=-1;
        for(ll i=1; i<n; i++){
            if(v[i][k]==v[i-1][k]){
                if(p==-1){
                    p=i-1;
                }
                curr++;
                if(i==n-1){
                    q.push({p,i,v[i][k]});
                    curr=1;
                }
            }
            else{
                if(curr>1){
                    q.push({p,i-1,v[i-1][k]});
                }
                curr=1;
                p=-1;
            }
        }
}

void newupdate(queue<tuple<ll,ll,char>> &q, vector<vector<char>> &v, ll j){
    queue<tuple<ll,ll,char>>nq;

    while(!q.empty()){
        auto fir=q.front();
        q.pop();
        ll curr=1;
        ll p=-1;
        for(ll i=get<0>(fir)+1; i<=get<1>(fir); i++){
            if(v[i-1][j]==v[i][j]){
                if(p==-1){
                    p=i-1;
                }
                curr++;
                if(i==get<1>(fir)){
                    nq.push({p,i,v[i][j]});
                    curr=1;
                }
            }
            else{
                if(curr>1){
                    nq.push({p,i-1,v[i-1][j]});
                }
                curr=1;
                p=-1;
            }
        }
    }
    q=nq;
}

ll solve(queue<tuple<ll,ll,char>> &q, vector<vector<char>> &a, ll j){

    queue<tuple<ll,ll,char>> pq=q;
    while(!pq.empty()){

        auto fir=pq.front();
        pq.pop();
        char ch=get<2>(fir);
        bool f=true;
        for(ll i=get<0>(fir)+1; i<=get<1>(fir); i++){
            if(a[i-1][j] > a[i][j]){
                f=false;
                break;
            }
        }
        if(!f){
            return 0;
        }
    }

    // while(!q.empty())
    //     q.pop();

    newupdate(q,a,j);

    if(q.size()==0){
        return 2;
    }

    return 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll m;
        cin>>n>>m;
        vector<vector<char>>v(n,vector<char>(m));

        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cin>>v[i][j];
            }
        }

        ll k=-1;
        ll cn=0;
        for(ll i=0; i<m; i++){
            bool f=true;
            for(ll j=1; j<n; j++){
                if(v[j][i] < v[j-1][i]){
                    f=false;
                    cn++;
                    break;
                }
            }
            if(f){
                k=i;
                break;
            }
        }
        // cout<<k<<' ';
        if(k==-1){
            cout<<m<<endl;
            continue;
        }

        queue<tuple<ll,ll,char>>q;

        check(q,v,k);
        

        if(q.size()==0){
            cout<<cn<<endl;
            continue;
        }

        for(ll i=k+1; i<m; i++){
            ll t=solve(q,v,i);
            if(t==0){
                cn++;
                continue;
            }
            if(t==2)
                break;

        }

        cout<<cn<<endl;

    }
    return 0;
}