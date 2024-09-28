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
        vi a,b;
        a.pb(1);
        for(ll i=0; i<n-1; i++){
            ll x;cin>>x;
            a.pb(x);
        }       
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            b.pb(x);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        // for(auto i:a)
        //     cout<<i<<' ';
        vector<bool>vis(n,false);
        // ll j=-1;
        // ll i=0;
        // while(i<n){
        //     // cout<<a[i]<<' ';
        //     ll k=upper_bound(b.begin(),b.end(),a[i])-b.begin();
        //     // cout<<k<<' ';
        //     if(k<n && !vis[k]){
        //         vis[k]=true;
        //         // i++;
        //         j=i;
        //         // continue;
        //     }
        //     else{
        //         while(k<n && vis[k]==true){
        //             k++;
        //         }
        //         j=i;
        //         // i++;
        //         if(k<n){
        //             vis[k]=true;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     i++;
        //     // cout<<'l';
            
        // }
        // i--;
        ll i=0,j=0;
        while(i<n && j<n){
            while(b[j] <= a[i] && j<n){
                j++;
            }
            if(j<n){
                i++;
            }
            else{
                break;
            }
            j++;
        }
        // cout<<i<<' ';
        // cout<<i<<' ';
        cout<<n-i<<endl;
    }
    return 0;
}