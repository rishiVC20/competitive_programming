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

void build(ll ind, ll low, ll high, vi &a, vi &seg){
    if(low==high){
        seg[ind]=a[low];
        return;
    }

    ll mid=(low+high)/2;

    build(2*ind+1,low,mid,a,seg);    
    build(2*ind+2,mid+1,high,a,seg);

    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);    

}

ll query(ll ind, ll low, ll high, ll l, ll r, vi &seg){
    
    if(low>=l && high<=r){
        return seg[ind];
    }
    // if(dp[ind] != -1)
    //     return dp[ind];
    if(high<l || low>r){
        return INT_MAX;
    }

    ll mid=(low+high)/2;
    ll left=query(2*ind+1,low,mid,l,r,seg);
    ll right=query(2*ind+2,mid+1,high,l,r,seg);

    return min(left,right);
}
int main() {
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,q;
        cin>>n>>q;

        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        vi seg(4*n+1);

        build(0,0,n-1,a,seg);
        vi dp(n+1,-1);
        ll m=(n)/2;
        while(q--){
            ll l,r;
            cin>>l>>r;
            l--,r--;
            
            ll ans=query(0,0,n-1,l,r,seg);

            cout<<ans<<endl;
        }

    }
    return 0;
}