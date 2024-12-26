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
        string s;
        cin>>s;
        if(n==1){
            YES;
            continue;
        }
        bool f=true;
        vi d(26,0);
        map<char,ll>mp;
        for(ll i=0; i<n; i++){
            if(s[i]!='.'){
                f=false;
            }
            mp[s[i]]++;
        }       
        if(f){
            YES;
            continue;
        }

        if(mp.find('s')==mp.end() || mp.find('p')==mp.end()){
            YES;
            continue;
        }

        bool gg=false;
        bool mm=false;
        for(ll i=0; i<n; i++){
            if(s[i]=='s' && gg){
                mm=true;
                break;
            }
            if(s[i]=='p'){
                gg=true;
            }
        }

        if(mm){
            NO;
            continue;
        }
        // cout<<"j ";

        ll j=-1;
        for(ll i=n-1; i>=0; i--){
            if(s[i]=='s'){
                j=i;
                break;
            }
        }

        vi dd(n);
        ll vn=1;
        for(ll k=j; k<n; k++){
            dd[k]=vn;
            vn++;
        }

        for(ll k=j-1; k>=0; k--){
            dd[k]=vn;
            vn++;
        }

        bool ff=true;
        ll maxi=1;
        for(ll i=0; i<n; i++){
            maxi=max(maxi,dd[i]);
            if(s[i]=='p'){
                if(maxi>(i+1)){
                    ff=false;
                    break;
                }
            }
        }

        if(ff)
            YES;
        else
            NO;    

    }
    return 0;
}