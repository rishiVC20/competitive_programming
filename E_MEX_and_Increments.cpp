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
        vi v(n+1);
        map<ll,ll>mp;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            v[x]++;
            mp[x]++;
        }
        priority_queue<ll>pq;
        vi ans;
        if(mp.find(0)!=mp.end()){
            ans.pb(mp[0]);
            for(ll i=1; i<mp[0]; i++){
                pq.push(0);
            }
        }
        else{
            ans.pb(0);
        }
        vi d(n+1,0);
        bool f=true;
        ll op=0;
        for(ll i=1; i<=n; i++){
            ll t=v[i-1];
            if(t>0){
                ans.pb(op+v[i]);
                if(v[i]==0){
                    if(pq.size()==0){
                        f=false;
                        break;
                    }
                    d[i]++;
                    ll r=pq.top();
                    pq.pop();
                    op+=i-r;
                }
                for(ll j=1; j<v[i]; j++){
                    pq.push(i);
                }
                continue;
            }
            else if(d[i-1]>0){
                if(v[i]!=0){
                    ans.pb(op+v[i]);
                }
                else{
                    ans.pb(op);
                }
                if(v[i]==0){
                    if(pq.size()==0){
                        f=false;
                        break;
                    }
                    d[i]++;
                    ll r=pq.top();
                    pq.pop();
                    op+=i-r;
                }
                for(ll j=1; j<v[i]; j++){
                    pq.push(i);
                }
            }
            else{
                break;
            }


        }

        while(ans.size()<n+1){
            ans.pb(-1);
        }

        for(auto i:ans)
            cout<<i<<' ';
        cout<<endl;    

    }
    return 0;
}