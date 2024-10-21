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

bool check(string s1,string s2, ll k){
    ll p=s2.size()-k;
    string m=s2.substr(k);
    ll b=m.size();
    string h="";
    ll j=0;
    ll c=s1.size()-1;
    while(j != b){
        h = s1[c]+h;
        c--;
        j++;
    }
    if(h==m)
        return true;
    return false;    
}

int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,m;
        cin>>n>>m;

        string s,t;
        cin>>s>>t;
        if(s[0] != t[0]){
            cout<<-1<<endl;
            continue;
        }
        bool f=true;
        if(n==m && t==s){
            cout<<0<<endl;
            continue;
        }
        ll j=-1;
        string x="",y="";
        for(ll i=0; i<min(n,m); i++){
            if(s[i] != t[i]){
                j=i;
                // if(i+1<n)
                //     x=s.substr(i);
                // if(j+1<m)    
                //     y=t.substr(i);
                break;
            }
        }
        if(j==-1 && n!=m){
            cout<<1<<endl;
            continue;
        }

        if(n>m){
            if(check(s,t,j)){
                cout<<1<<endl;
                continue;
            }
        }
        else if(m>n){
            if(check(t,s,j)){
                cout<<1<<endl;
                continue;
            }
        }

        cout<<2<<endl;
        // if(x=="" || y==""){
        //     cout<<1<<endl;
        //     continue;
        // }
        // ll k1=x.size(),k2=y.size();
        // bool f=false;
        // string h1,h2;
        // for(ll i=j+1; i<n; i++){
        //     if(s[i] == t[j]){
        //         if(i+k2 < n){
        //             h1=x.substr(i,k2);
        //         }
        //         if(i+k1 < m){
        //             h2=y.substr(i,k1);
        //         }
        //         if(h1!="" && h2!=""){
        //             f=true;
        //             break;
        //         }
        //     }
        // }
        // if(f){
            
        // }
        

    }
    return 0;
}