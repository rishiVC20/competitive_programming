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
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }       
        vi v(n+1,0);
        // for(ll i=1; i<n; i++){
        //     bool f=false;
        //     if(a[i-1] > a[i] && v[i-1]>0){
        //         a[i] += powl(2,v[i-1]);
        //         v[i]=v[i-1]+1;
        //         f=true;
        //     }
        //     if(a[i-1] > a[i]){
        //         ll p=1+log2(a[i-1]-a[i]);
        //         // cout<<p<<' ';
        //         a[i] += powl(2,p-1);
        //         // v[i]=max(v[i-1],p);
        //         v[i]+=v[i-1]+p;
        //     }
        //     else if(!f){
        //         v[i]=v[i-1];
        //     }
        // }

        ll maxi=a[0], ind=0;
        ll diff=0;
        vi d(n+1);
        d[0]=a[0];
        for(ll i=1; i<n; i++){
            if(a[i] >= maxi){
                maxi=a[i],ind=i;
            }
            d[i]=maxi;
            
        }
        for(ll i=0; i<n; i++)
            cout<<d[i]<<' ';
        for(ll i=0; i<n; i++){
            diff=max(diff,d[i]-a[i]);
        }
        if(diff==0){
            cout<<0<<endl;
            continue;
        }
        // cout<<diff<<' ';
        ll p=1+log2(diff);

        cout<<p<<endl;

        // for(ll i=0; i<n; i++)
        //     cout<<a[i]<<' ';

        // cout<<v[n-1]<<endl;
    }
    return 0;
}