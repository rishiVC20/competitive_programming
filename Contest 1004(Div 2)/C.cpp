// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
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
ll mAdd(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mSub(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mul (ll a, ll b, ll m=mod){
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b){
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
ll power(ll base, ll exponent){
    if (exponent < 0){
        return 0;
    }
    ll ans = 1;
    while (exponent){
        if (exponent%2==0){
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else{
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}
ll invmod(ll a, ll m = mod){
    return power(a, m - 2);
}
ll div(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return mul(a, invmod(b, m), m);
}

bool see(string f){
    for(auto i:f){
        if(i=='7')
            return true;
    }

    return false;
}
ll check(vector<ll> &v, ll p){
    // ll p=stol(d);
    // cout<<p<<' ';
    ll mini=INT_MAX;
    for(ll i=0; i<v.size(); i++){
        ll m=v[i];
        ll t=p;
        // cout<<m<<"h ";
        for(ll j=1; j<=10; j++){
            t+=m;
            if(see(to_string(t))){
                // cout<<j<<"j ";
                mini=min(j,mini);
                break;
            }
        }
    }
    return mini;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll k;
        cin>>k;
        string s=to_string(k);
        bool f=false;
        for(auto i:s){
            if(i=='7'){
                f=true;
                break;
            }
        }
        if(f){
            cout<<0<<endl;
            continue;
        }
        vector<string>v;
        vector<ll>vp;
        string d="";
        ll r=0;
        ll n=s.size();
        for(ll i=0; i<n; i++){
            d+="9";
            r*=10;
            r+=9;
            v.pb(d);
            vp.pb(r);
        }
        // for(auto i:vp)
        //     cout<<i<<' ';
        ll cn=INT_MAX;
        ll t=1;
        ll e=1;
        for(ll i=0; i<n-1; i++){
            e*=10;
        }
        // cout<<e<<' ';
        // cout<<k<<' ';
        // for(ll i=s.size()-1; i>=0; i--){
        //     ll p=k/e;
        //     e/=10;
        //     if(e==0)
        //         e=1;
        //     // cout<<p<<' ';
        //     // d+="9";
        //     // v.pb(d);
        //     ll ff=check(vp,p);
        //     // cout<<ff<<' ';
        //     cn=min(cn,ff);
        // }
        ll ff=check(vp,k);
        cn=min(cn,ff);
        // for(auto i:v)
        //     cout<<i<<' ';

        cout<<cn<<endl;
    }
    return 0;
}