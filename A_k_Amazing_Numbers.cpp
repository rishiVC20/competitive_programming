// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
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
ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
ll power(ll base, ll exponent)
{
    if (exponent < 0)
    {
        return 0;
    }
    ll ans = 1;
    while (exponent)
    {
        if (exponent%2==0)
        {
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else
        {
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}


int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;

        vi a(n+1);
        vi dis(n+1,n+1);
        for(ll i=1; i<=n; i++){
            ll x;cin>>x;
            a[i]=x;
        }

        vector<vector<ll>>v(n+1);
        for(ll i=1; i<=n; i++){
            v[i].pb(0);
        }

        for(ll i=1; i<=n; i++){
            ll k=a[i];
            ll p=v[k].back();
            v[k].pb(i);
            if(p==0){
                dis[k]=i;
            }
            else{
                dis[k]=max(dis[k],i-p);
            }
        }

        for(ll i=1; i<=n; i++){
            ll k=a[i];
            ll p=v[k].back();
            dis[k]=max(dis[k],n+1-p);
        }
        // for(auto i:dis)
        //     cout<<i<<' ';

        // for(auto i:v){
        //     for(auto j:i)
        //         cout<<j<<' ';
        //     cout<<endl;    
        // }
        // cout<<endl;
        vi ans(n+1,n+100);

        for(ll i=1; i<=n; i++){
            ll m=dis[i];
            // cout<<dis[i]<<"k ";
            if(m<=n){
                ans[m]=min(ans[m],i);
            }
        }
        ll ind=-1;
        ll val=n+100;
        bool f=false;
        for(ll i=1; i<=n; i++){
            if(ans[i]!=n+100 && !f){
                val=ans[i];
                f=true;
            }
            if(f){
                if(ans[i]<val){
                    val=ans[i],ind=i;
                }
                else{
                    ans[i]=val;
                }
            }
        }
        for(ll i=1; i<=n; i++){
            if(ans[i]==n+100)
                ans[i]=-1;
        }
        for(ll i=1; i<=n; i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}