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
    if(a.first == b.first)
        return a.second<b.second;
    return a.first < b.first;
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
        vi a,b;
        vector<pair<ll,ll>>v;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }       
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            b.pb(x);
        }
        for(ll i=0; i<n; i++){
            v.pb({a[i],b[i]});
        }
        // sort(a.rbegin(),a.rend());
        sort(v.begin(),v.end(),customComparator);


        ll j=n-1;
        bool f=false;
        for(ll i=n-2; i>=0; i--){
            // if(i==n-2)
            //     continue;
            ll k=max(v[i].first,v[i].second); 
            ll q=max(v[j].first,v[j].second);   
            if(k>q){
                f=true;
                break;
            }
        }
        if(f){
            YES;
            continue;
        }

        j=n-2;
        f=false;
        ll k=max(v[n-1].first,v[n-1].second);
        ll q=max(v[j].first,v[j].second);
        if(k>q)
            f=true;

        if(f)
            YES;
        else
            NO;    



        
    }
    return 0;
}