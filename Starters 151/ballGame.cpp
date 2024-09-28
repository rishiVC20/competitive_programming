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
        ll n;
        cin>>n;
        vector<pair<ll,ll>>v(n);
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            v[i].first=x;
        }
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            v[i].second=x;
        }
        sort(v.begin(),v.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
            return a.first<b.first;
        });
        vi m;
        ll maxi=-1;
        ll cn=0;
        for(ll i=0; i<n; i++){
            ll c=(v[i].first)/(v[i].second);
            if(v[i].first%v[i].second != 0)
                c++;
            ll p = (v[i].second)*c;    
            m.pb(c);
            // if(v[i].second > maxi){
            //     cn++;
            //     maxi=v[i].second;
            // }    
        }
        // for(auto i:m){
        //     cout<<i<<' ';
        // }
        bool lp=true;
        for(ll i=0; i<n-1; i++){
            if (v[i].first*v[i+1].second < v[i+1].first*v[i].second){
                lp=false;
                break;
            }
        }
        // if(lp){
        //     cout<<n<<endl;
        //     continue;
        // }
        ll k=m[0];
        stack<ll>sp;
        for(ll i=1; i<n; i++){
            if(m[i]<k){
                continue;
            }
            else if(m[i]==k){
                ll m=__gcd(v[i].second,k);
            }
            else{
                // cn++;
                k=m[i];
            }
        }
        
        for(ll i=0; i<n; i++){
            
        }
        cn=sp.size();
        cout<<cn<<endl;
    }
    return 0;
}
