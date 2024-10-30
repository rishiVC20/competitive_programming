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
        vi a,b;
        for(ll i=0; i<n; i++){
            if(s[i]=='1'){
                b.pb(i+1);
            }
            else{
                a.pb(i+1);
            }
        }       

        vi c;
        // cout<<a.size()<<' '<<b.size()<<' ';
        ll x=a.size(),y=b.size();
        // cout<<x<<' '<<y<<' ';
        if(x <= 0){
            // for(auto i:b)
            //     cout<<i<<' ';
            ll h=(b.size()+1)/2;
            ll sum=0;
            for(ll i=0; i<h; i++){
                sum += b[i];
            }
            cout<<sum<<endl;
            continue;
        }
        if(y<=0){
            ll sum=0;
            for(auto i:a)
                sum += i;
            cout<<sum<<endl;
            continue;    
        }
        x--,y--;
        while(x>=0 && y>=0){
            while(x>=0 && a[x] > b[y]){
                c.pb(a[x]);
                x--;
            }
            if(x>=0 && a[x] < b[y]){
                c.pb(a[x]);
                x--,y--;
            }
            else{
                break;;
            }
            // x--,y--;
        }
        // cout<<x<<' '<<y<<' ';
        ll j=(y+2)/2;
        ll t=0;
        while(t < j){
            c.pb(b[t]);
            t++;
        }
        ll h=x;
        while(h>=0){
            c.pb(a[h]);
            h--;
        }
        // for(auto i:c)
        //     cout<<i<<' ';
        ll sum=0;
        for(auto i:c)
            sum += i;
        cout<<sum<<endl;    
    }
    return 0;
}