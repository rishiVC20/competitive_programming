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

ll bs(ll st, ll en, ll re, ll s, vi &pre){
    if(st <= en){
        ll mid=st+(en-st)/2;
        // if(mid==en)
        //     return en;
        if(pre[mid]-s <= re){
            if(mid==en)
                return en;
            if(pre[mid+1]-s <= re){
                return bs(mid+1,en,re,s,pre); 
            }
            else{
                return mid;
            }
        }    
        else{
            return bs(st,mid-1,re,s,pre);
        }
    }
    return -1;
}
int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vi a,b;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }
        vi pre(n);
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            b.pb(x);
            if(i>0)
                pre[i] = pre[i-1]+x;
            else
                pre[i]=x;     
        }
        vi v;
        vi fu(n+1,0);
        vi ans(n,0);
        for(ll i=0; i<n; i++){
            ll j;
            if(i>0)
                j=bs(i,n-1,a[i],pre[i-1],pre);
            else
                j=bs(i,n-1,a[i],0,pre);   
            // cout<<j<<"h ";    
            if(j==-1){
                // ans[i] += min(a[i],b[i]);
                ans[i] += a[i];
            }     
            else{
                fu[i]++;
                if(j+1 < n){
                    fu[j+1]--;
                    ans[j+1]=ans[j+1]+(a[i]-(pre[j]-(i>0?pre[i-1]:0)));

                }
            }
        }
        for(ll i=1; i<n; i++)
            fu[i] += fu[i-1];
        // for(auto i:fu)
        //     cout<<i<<"p ";
        for(ll i=0; i<n; i++){
            ans[i]+=fu[i]*b[i];
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    return 0;
}