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

vector<bool>prime(1e5,true);
vi ans;
void sieve(){
    for(ll i=2; i*i<1e5; i++){
        if(prime[i]==true){
            for(ll j=i*i; j<1e5; j+=i){
                prime[j]=false;
            }
        }
    }
    for(ll i=2; i<prime.size(); i++){
        if(prime[i]==true){
            ans.pb(i);
        }
    }
}

int main() {
    ll t;
    cin>>t;
    sieve();
    // for(ll i=0; i<10; i++)
    //     cout<<ans[i]<<' ';
    // cout<<endl;    
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vi>a(n,vi(m,0));
        vi b,c;
        ll k=2;
        ll d=2;
        b.pb(k);
        for(ll i=1; i<m; i++){
            ll m=k*d+1;
            b.pb(m);
            d++;
        }
        k=3;
        d=2;
        c.pb(k);
        for(ll i=1; i<m; i++){
            ll m=k*d+1;
            c.pb(m);
            d++;
        }
        for(ll i=0; i<n; i++){
            if(i%2==0){
                for(auto j:b)
                    cout<<j<<' ';
            }
            else{
                for(auto j:c)
                    cout<<j<<' ';
            }
            cout<<endl;
        }

        


    }
    return 0;
}

boi