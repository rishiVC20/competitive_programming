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
        ll n;
        cin>>n;
        vi a;
        bool f=true;
        bool k=true;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(i!=0){
                if(a[i]!=a[i-1])
                    f=false;
            }
            if(i!=0){
                if(a[i]>a[i-1])
                    k=false;
            }
        }       
        if(f || k){
            cout<<0<<endl;
            continue;
        }
        vi c,d;
        c.pb(a[0]);
        d.pb(INT_MAX);
        ll j=0;
        while(a[j]<=c.back()){
            c.pb(a[j]);
            j++;
        }
        for(ll i=j; i<n; i++){
            if(c.back() > d.back()){
                if(d.back() >= a[i]){
                    d.pb(a[i]);
                }
                else if(a[i] > c.back()){
                    d.pb(a[i]);
                }
                else{
                    c.pb(a[i]);
                }
            }
            else{
                if(c.back() >= a[i]){
                    c.pb(a[i]);
                }
                else if(a[i] > d.back()){
                    c.pb(a[i]);
                }
                else{
                    d.pb(a[i]);
                }
            }
            
        }
        ll ans=0;
        for(ll i=0; i<c.size()-1; i++){
            if(c[i]<c[i+1])
                ans++;
        }
        for(ll i=0; i<d.size()-1; i++){
            if(d[i]<d[i+1])
                ans++;
        }

        cout<<ans<<endl;

    }
    return 0;
}