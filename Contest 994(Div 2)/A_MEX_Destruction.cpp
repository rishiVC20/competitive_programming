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

        vi a;
        vi b;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(x==0){
                b.pb(i);
            }
        }

        if(b.size()==0){
            cout<<1<<endl;
            continue;
        }

        if(b.size()==n){
            cout<<0<<endl;
            continue;
        }
        bool g=false;
        for(ll i=0; i<n; i++){
            bool f=false,h=false;
            if(a[i]==0){
                for(ll j=0; j<i; j++){
                    if(a[j]!=0){
                        f=true;
                        break;
                    }
                }
                for(ll j=i+1; j<n; j++){
                    if(a[j]!=0){
                        h=true;
                        break;
                    }
                }
                if(f && h){
                    g=true;
                    break;
                }
            }
        }

        if(g)
            cout<<2<<endl;
        else
            cout<<1<<endl;    

        // bool f=false;
        
        // if(b.size()==1){
        //     if(b[0]==0 || b[0]==n-1){
        //         cout<<1<<endl;
        //     }
        //     else{
        //         cout<<2<<endl;
        //     }
        //     continue;
        // }
        // if(b.size()==2){
        //     if((b[0]==0 && b[1]==n-1) || (b[0]==0 && b[1]==1) || (b[0]==n-2 && b[1]==n-1) ){
        //         cout<<1<<endl;
            
        //     }
        //     else{
        //         cout<<2<<endl;

        //     }
        //     continue;
        // }      

        // for(ll i=0; i<b.size()-1; i++){
        //     if(b[i+1]-b[i] > 1){
        //         f=true;
        //         break;
        //     }
        // }

        // if(f)
        //     cout<<2<<endl;
        // else
        //     cout<<1<<endl;    
    }
    return 0;
}