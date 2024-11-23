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
        if(n%2 && n<27){
            cout<<-1<<endl;
            continue;
        }
        if(n==4){
            cout<<1<<' '<<1<<' '<<2<<' '<<2<<endl;
            continue;
        }
        if(n==2){
            cout<<1<<' '<<1<<endl;
            continue;
        }
        vi a(n+1,-1);
        map<ll,ll>mp;
        if(n%2){
            a[1]=1,a[10]=1,a[26]=1;
            ll w=2;
            vi b;
            b.pb(1);
            for(ll i=3; i<=6; i++){
                b.pb(i),b.pb(i);
            }
            b.pb(1),b.pb(2);
            for(ll i=7; i<=13; i++){
                b.pb(i),b.pb(i);
            }
            b.pb(1),b.pb(2);
            ll k=b.size();
            ll e=14;
            while(b.size()<n){
                b.pb(e),b.pb(e);
                e++;
            }
            for(auto i:b)
                cout<<i<<' '; 
            cout<<endl;
            continue;
        }
        
        ll w=1,x=2,y=3,z=4;
        for(ll i=1; i<=n; i++){
            mp[w]++;
            a[i]=w;
            // cout<<w<<"h ";
            if(mp[w]==2){
                w++;
            }
        }

        for(ll i=1; i<=n; i++)  
            cout<<a[i]<<' ';
        cout<<endl;    
    }
    return 0;
}