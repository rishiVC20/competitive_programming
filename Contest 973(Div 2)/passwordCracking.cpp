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

bool query(char c, deque<char>&ans, ll tp, ll &cn, ll n){
    if(++cn > 2*n){
        return 1;
    }
    cout<<"? ";
    if(tp==0)
        cout<<c;
    for(auto i:ans)
        cout<<i;
    if(tp==1)
        cout<<c;
    ll res;
    cin>>res;
    return res;            
}

void answer(deque<char>q){
    cout<<"! ";
    for(auto i:q)
        cout<<i;
    cout<<endl;
    fflush(stdout);    
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        deque<char>q;
        ll tp=0;
        ll cn=0;
        for(ll i=0; i<n; i++){
            bool f=false;
            for(char c=0; c<=1; c++){
                if(query(c,q,tp,cn,n)==1){
                    if(tp==0)
                        q.push_back(c);
                    else
                        q.push_front(c);
                    f=true;
                    break;        
                }
            }
            if(!f){
                if(tp==0)
                    tp=1;
                else tp=0;    
            }
            answer(q);
        }       
    }
    return 0;
}