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

        vector<vi>v(2,vi(n));
        for(ll i=0; i<2; i++){
            for(ll j=0; j<n; j++){
                cin>>v[i][j];
            }
        }

        vector<pair<ll,ll>>a,b;
        ll x=INT_MIN,y=INT_MIN;
        for(ll i=0; i<n; i++){
            ll k=v[0][i],p=v[1][i];
            x=max(x,k);
            y=max(y,p);
            if(k>p){
                a.pb({k,p});
            }
            else{
                b.pb({k,p});
            }
        }

        ll sum=0;
        for(ll i=0; i<a.size(); i++){
            sum += a[i].first;
        }
        for(ll i=0; i<b.size(); i++){
            sum += b[i].second;
        }
        ll mini=INT_MIN;
        for(ll i=0; i<b.size(); i++){
            mini=max(mini,b[i].first);
        }
        for(ll i=0; i<a.size(); i++){
            mini=max(mini,a[i].second);
        }

        if(a.size()==0){
            sum+=x;
            cout<<sum<<endl;
            continue;
        }
        if(b.size()==0){
            sum+=y;
            cout<<sum<<endl;
            continue;
        }
        sum += mini;
        cout<<sum<<endl;

        
    }
    return 0;
}