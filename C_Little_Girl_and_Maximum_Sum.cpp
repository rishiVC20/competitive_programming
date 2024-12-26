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
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,q;
        cin>>n>>q;

        vi a(n+1);
        for(ll i=1; i<=n; i++){
            cin>>a[i];
        }
        // for(auto i:a)
        //     cout<<i<<' ';
        // cout<<endl;    
        vector<pair<ll,ll>>v;
        vi b(n+2);
        for(ll i=1; i<=q; i++){
            ll x,y;
            cin>>x>>y;
            v.pb({x,y});
            b[x]++,b[y+1]--;
        }


        for(ll i=1; i<=b.size(); i++){
            b[i]+=b[i-1];
        }
        // for(auto i:b)
        //     cout<<i<<' ';
        // cout<<endl;    
        vector<pair<ll,ll>>t;
        for(ll i=1; i<b.size()-1; i++){
            t.pb({i,b[i]});
        }

        sort(t.begin(),t.end(),[&](pair<ll,ll>&a, pair<ll,ll> &b){
            return a.second < b.second;
        });
        // for(auto i:t)
        //     cout<<i.first<<" "<<i.second<<"j ";
        vi ans(n+1);
        sort(a.rbegin(),a.rend());
        ll j=0;
        // for(auto i:a)
        //     cout<<i<<" ";
        // cout<<endl; 
        for(ll i=t.size()-1; i>=0; i--){
            // cout<<a[j]<<' ';
            ans[t[i].first]=a[j++];
        }
        // for(auto i:t)
        //     cout<<i.first<<" "<<i.second<<"j ";
        // for(ll i=1; i<=n; i++){
        //     cout<<ans[i]<<' ';
        // }
        vi pre(n+1);
        pre[0]=0;
        pre[1]=ans[1];
        for(ll i=1; i<=n; i++){
            pre[i]=pre[i-1]+ans[i];
        }
        ll sum=0;

        for(ll i=0; i<v.size(); i++){
            ll x=v[i].first,y=v[i].second;
            sum += pre[y]-pre[x-1];
        }

        cout<<sum;
        cout<<endl;

    }
    return 0;
}