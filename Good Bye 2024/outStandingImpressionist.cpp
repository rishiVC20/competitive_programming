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
        vector<pair<ll,ll>>v;
        map<ll,ll>mp;
        set<ll>st;
        vi a;

        for(ll i=0; i<n; i++){
            ll x,y;
            cin>>x>>y;
            if(x==y && st.find(x)==st.end()){
                a.pb(x);
                st.insert(x);
            }
            if(x==y){
                mp[x]++;
            }
            v.pb({x,y});

        }

        sort(a.begin(),a.end());

        string s="";
        for(ll i=0; i<n; i++){
            ll v1=v[i].first,v2=v[i].second;
            ll cn=v2-v1+1;
            if(v1==v2){
                if(mp[v1]>1){
                    s+='0';
                    
                }
                else{
                    s+='1';
                }
                continue;
            }

            ll up=upper_bound(a.begin(),a.end(),v2)-a.begin();
            up--;
            ll lb=lower_bound(a.begin(),a.end(),v1)-a.begin();
            // cout<<i<<" "<<up<<' '<<lb<<endl;
            if((up-lb+1)==cn && a[up]==v2 && a[lb]==v1){
                s+='0';
            }
            else{
                s+='1';
            }

        }

        cout<<s<<endl;
    }
    return 0;
}