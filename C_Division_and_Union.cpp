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

        for(ll i=0; i<n; i++){
            ll x,y;
            cin>>x>>y;
            v.pb({x,y});
        }       

        bool f=false;

        ll k1=v[0].first,k2=v[0].second;
        for( auto i:v){
            if(i.first==k1){
                continue;
            }
            if(i.first==k2){
                continue;
            }
            if(i.second==k1){
                continue;
            }
            if(i.second==k2){
                continue;
            }
            f=true;
            break;
        }
        if(!f){
            cout<<-1<<endl;
            continue;
        }
        set<ll>st1,st2;
        st1.insert(k1),st1.insert(k2);
        for(ll i=1; i<n; i++){
            k1=v[i].first,k2=v[i].second;
            if(st1.find(k1)!=st1.end()){
                st1.insert(k1);
                st1.insert(k2);
                continue;
            }
            if(st1.find(k2)!=st1.end()){
                st1.insert(k1);
                st1.insert(k2);
                continue;
            }
            if(st2.find(k1)!=st2.end()){
                st2.insert(k1);
                st2.insert(k2);
                continue;
            }
            if(st2.find(k2)!=st2.end()){
                st2.insert(k1);
                st2.insert(k2);
                continue;
            }
            st2.insert(k1),st2.insert(k2);
            
        }

        if(st2.size()==0){
            cout<<-1<<endl;
            continue;
        }

        for(ll i=0; i<n; i++){
            ll v1=v[i].first,v2=v[i].second;

            if(st1.find(v1)!=st1.end() || st1.find(v2)!=st1.end()){
                cout<<1<<" ";
            }
            if(st2.find(v1)!=st2.end() || st2.find(v2)!=st2.end()){
                cout<<2<<" ";
            }
        }

        cout<<endl;

    }
    return 0;
}