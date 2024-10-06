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
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<pair<ll,ll>>a,b;
        for(ll i=0; i<n+m+1; i++){
            ll x;cin>>x;
            a.pb({i+1,x});
        }       
        for(ll i=0; i<n+m+1; i++){
            ll x;cin>>x;
            b.pb({i+1,x});
        }
        sort(b.begin(),b.end(),customComparator);
        sort(a.begin(),a.end(),customComparator);

        vi u,v;
        unordered_set<ll>x,y;
        ll p=0;
        ll cc=0,dd=0;
        while(p<(n+m+1)){
            if(a[p].second>=b[p].second){
                if(cc<n){
                    u.pb(a[p].second);
                    x.insert(a[p].first);
                    cc++;
                }
                else{
                    v.pb(b[p].second);
                    y.insert(b[p].first);
                    dd++;
                }
            }
            else{
                if(dd<m){
                    v.pb(b[p].second);
                    y.insert(b[p].first);
                    dd++;
                }
                else{
                    u.pb(a[p].second);
                    x.insert(a[p].first);
                    cc++;
                }
            }
            p++;
        }
        ll s1=accumulate(u.begin(),u.end(),0LL);
        ll s2=accumulate(v.begin(),v.end(),0LL);
        ll j=max(n,m);
        
        for(auto i:u)
            cout<<i<<' ';
        for(auto i:v)
            cout<<i<<' ';    
        ll cn=0;
        for(ll i=0; i<n+m+1; i++){
            ll ck=0;
            ck += s1+s2;
            if(x.find(i+1)!=x.end()){
                ll k=a[i+1].second;
                ck -= k;
                ck += u.back();
            }
            else if(y.find(i+1)!=y.end()){
                ll k=b[i+1].second;
                ck -= k;
                ck += v.back();
            }

           cout<<ck<<' '; 
        }
        cout<<endl;
    }
    return 0;
}