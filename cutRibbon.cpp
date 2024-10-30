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
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        map<ll,ll>mp;           
        vi v(3);
        cin>>v[0]>>v[1]>>v[2];
        mp[v[0]]++,mp[v[1]]++,mp[v[2]]++;
        sort(v.begin(),v.end());

        vi dp(n+1,-1);
        dp[0]=0;
        for(ll i=1; i<=n; i++){
            ll p1=0,p2=0,p3=0;
            if((i-v[0])>=0){
                if(dp[i-v[0]] != -1)
                    dp[i]=max(dp[i],1+dp[i-v[0]]);
            }
            if(i-v[1] >= 0){
                if(dp[i-v[1]] != -1)
                    dp[i]=max(dp[i],1+dp[i-v[1]]);
            }
            if(i-v[2] >= 0){
                if(dp[i-v[2]] != -1)
                    dp[i]=max(dp[i],1+dp[i-v[2]]);
            }
            // if(dp[i]==-1)
            //     dp[i]=0;

            // dp[i] = max(p1,max(p2,p3));   
            // if(dp[i] != 0)
            //     dp[i]++;         
        }

        for(ll i=0; i<=24; i++) 
            cout<<dp[i]<<' ';

        cout<<dp[n] <<endl;

    }
    return 0;
}