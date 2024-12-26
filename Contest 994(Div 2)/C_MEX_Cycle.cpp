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
        ll m,x,y;
        cin>>m>>x>>y;

        vi d(m+1);
        map<ll,vi>mp;
        for(ll i=2; i<m; i++){
            mp[i].pb(i-1);
            mp[i].pb(i+1);
        }
        mp[1].pb(m);
        mp[1].pb(2);
        mp[m].pb(m-1);
        mp[m].pb(1);
        if(m%2){
            bool f=false;
            for(ll i=1; i<=m; i++){
                if(f)
                    d[i]=1;
                else
                    d[i]=0;
                f=!f;        
            }
            // d[m]=2;
        }
        else{
            bool f=false;
            for(ll i=1; i<=m; i++){
                if(f)
                    d[i]=1;
                else
                    d[i]=0;
                f=!f;        
            }
        }
        // for(auto i:d)
        //     cout<<i<<' ';
        // cout<<endl;    

        if(abs(x-y)==1 || abs(x-y)==m-1){
            if(d[1]==d[m])
                d[m]=2;
            for(ll i=1; i<=m; i++){
                cout<<d[i]<<" ";
            }
            cout<<endl;
            continue;    
        }
        
        if(d[x]==d[y]){
            d[y]=2;
            bool f=false;
            for(ll i=y+1; i<=m; i++){
                if(f){
                    d[i]=1;
                }
                else{
                    d[i]=0;
                }
            f=!f;
        }
        }
        
        
        if(d[1]==d[m]){
            if(d[m-1]==1)
                d[m]=2;
            else if(d[m-1]==2)
                d[m]=1;    
            
            // if(d[1]==d[m])
            //     d[m]=2;
            // else if(d[m-1]==)
        }
        for(ll i=1; i<=m; i++){
            cout<<d[i]<<' ';
        }
        cout<<endl;
        // mp[x].pb(y);
        
        // // for(auto i:mp){
        // //     for(auto j:i.second)
        // //         cout<<j<<' ';
        // //     cout<<endl;    
        // // }
        
        // ll mini=0;
        // bool p=false,q=false,r=false;
        // for(auto i:mp[x]){
        //     // cout<<"j";
        //     if(d[i]==0) p=true;
        //     if(d[i]==1) q=true;
        //     if(d[i]==2) r=true;
        // }
        // if(!p)
        //     d[x]=0;
        // if(!q)
        //     d[x]=1;
        // if(!r)
        //     d[x]=2;

        // // cout<<"k ";
        // // for(ll i=1; i<=m; i++)
        // //     cout<<d[i]<<" ";
        // // cout<<endl;        

        // mp[y].pb(x);
        // mini=0;
        // bool c=false,e=false,f=false;
        // for(auto i:mp[y]){
        //     if(d[i]==0) c=true;
        //     if(d[i]==1) e=true;
        //     if(d[i]==2) f=true;
        // }

        // if(!c)
        //     d[y]=0;
        // if(!e)
        //     d[y]=1;
        // if(!f)
        //     d[y]=2;        

        // for(ll i=1; i<=m; i++)
        //     cout<<d[i]<<' ';
        // cout<<endl;    
    }
    return 0;
}