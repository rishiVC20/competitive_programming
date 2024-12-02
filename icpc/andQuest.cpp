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

void solve(ll j, ll tar, vector<pair<ll,ll>> &v, ll sum, vi &d, vi &f){
    if(j==v.size())
        return;
    // ll p=sum&v[j].first;
    ll m=v[j].first&sum;
    // cout<<m<<' ';
    if(j==0){
        m=v[j].first,sum=v[j].first;
    }
    // m=sum&v[j].first;
    // cout<<m<<' ';
    if(m==tar){
        cout<<j<<" ";
        if(f.size() == 0)
            f=d;
        return;
    }

    
    d.pb(v[j].second);
    solve(j+1, tar, v, m,d,f);
    d.pop_back();
    solve(j+1,tar,v,sum,d,f);
}

int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;

        vector<pair<ll,ll>>v(n);

        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            v[i].second=i+1,v[i].first=x;
        }

        vi d;
        vi f;
        solve(0,k,v,(ll)0,d,f);

        if(f.size() > 0){
            YES;
            cout<<f.size()<<endl;
            for(auto i:f)
                cout<<i<<' ';
            cout<<endl;
            continue;    
        }

        NO;


    }
    return 0;
}