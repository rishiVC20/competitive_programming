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

ll intPowerOfTwo(int64_t exponent) {
    int64_t result = 1;
    while (exponent--) {
        result *= 2;
        if (result > LLONG_MAX) {
            break;
        }
    }
    return result;
}

// vector<ll>ans;
ll cn=0;

pair<ll,ll> solve(ll l,ll r, ll k){
    ll p=r-l+1;

    if(p<k){
        return {0,0};
    }

    ll mid=(l+r)/2;
    if(p%2){
        pair<ll,ll>j=solve(l,mid-1,k);
        ll sum=mid+2*j.first+mid*j.second;
        ll seg=2*j.second+1;
        return {sum,seg};
    }

    else{
        pair<ll,ll>j=solve(l,mid,k);
        ll sum=2*j.first+mid*j.second;
        ll seg=2*j.second;

        return {sum,seg};
    }
}


int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;

        ll m=log2(n);
        // if(powl(2,m) == n){
        //     cout<<0<<endl;
        //     continue;
        // }
        // if(n&1)
        //     n++;

        if(k==1){
            ll b=n*(n+1)/2;
            cout<<b<<endl;
            continue;
        }

        // solve(1,n,k);

        // cn=0;

        pair<ll,ll>sum=solve(1,n,k);

        // for(auto i:ans){
        //     cn+=i;
        // }

        cout<<sum.first<<endl;

        // ll d=n;
        // while (d > k){
        //     d>>=1;
        // }
        // if(d%2==0)
        //     d++;

        // cout<<d*d*(d+1)/2<<endl;
        
   }
    return 0;
}