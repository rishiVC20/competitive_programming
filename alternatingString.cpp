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

ll solve(string s, ll n){
    bool v1=true,v2=true;
    for(ll i=0; i<n; i+=2){
        if(s[i]!=s[0]){
            v1=false;
            break;
        }
    }
    for(ll i=1; i<n; i+=2){
        if(s[i]!=s[1]){
            v2=false;
            break;
        }
    }
    if(v1 && v2)
        return 0;
    map<char,ll>mp1;
    for(ll i=0; i<n; i+=2){
        mp1[s[i]]++;
    }
    map<char,ll>mp2;
    for(ll i=1; i<n; i+=2){
        mp2[s[i]]++;
    }
    ll maxi1=0,maxi2=0;
    char i1,i2;
    for(auto i:mp1){
        if(maxi1<i.second){
            maxi1=i.second;
            i1=i.first;
        }
    }
    // cout<<maxi1<<' '<<i1;
    for(auto i:mp2){
        if(maxi2<i.second){
            maxi2=i.second;
            i2=i.first;
        }
    }
    // cout<<i1<<' '<<i2<<' ';
    vector<char>g(n);
    for(ll i=0; i<n; i++){
        if(i%2==0)
            g[i]=i1;
        else
            g[i]=i2;    
    }
    string p="";
    for(auto i:g){
        p+=i;
    }
    // cout<<p<<' ';
    ll cn=0;
    for(ll i=0; i<n; i++){
        if(p[i]!=s[i])
            cn++;
    }
    return cn;
}

int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if(n%2==0){
            cout<<solve(s,n)<<endl;
        }       
        else{
            ll maxi=INT_MAX;
            for(ll i=0; i<n; i++){
                string k=s.substr(0,i)+s.substr(i+1);
                cout<<k<<' ';
                ll p=solve(k,n)+1;
                maxi=min(p,maxi);
            }
            cout<<maxi<<endl;
        }
    }
    return 0;
}