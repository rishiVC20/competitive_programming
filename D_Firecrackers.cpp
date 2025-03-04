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

bool check(vi &v, ll j, ll t, ll ele){
    vi d;
    ll g=1;
    ll cn=0;
    for(ll i=j-1; i>=0; i--){
        // cout<<v[i]<<' ';
        d.pb(v[i]+g);
        g++;
        cn+=(d.back()<=t);
        if(i+1>ele)
            return false;
    }
    // cout<<endl;

    return cn==j;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,m,a,b;
        cin>>n>>m>>a>>b;

        vi v;
        for(ll i=0; i<m; i++){
            ll x;cin>>x;
            v.pb(x);
        }

        sort(v.begin(),v.end());
        ll ele=abs(a-b)-1;
        ll t=ele;
        if(a<b){
            t+=a;
        }
        else{
            t+=(n-a)+1;
        }
        // vi d,e;
        // ll g=1;
        // cout<<t<<"g ";
        ll l=0, r=m;
        while(l<r){
            ll mid=l+(r-l+1)/2;
            // cout<<mid<<' ';
            if(check(v,mid,t,ele)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }

        cout<<l<<endl;
        // for(ll i=min(m-1,ele-1); i>=0; i--){
        //     // cout<<v[i]<<' ';
        //     d.pb(v[i]+(g));
        //     g++;
        // }
        // for(ll i=0; i<min(m,ele); i++){
        //     e.pb(v[i]+(i+1));
        // }
        // // cout<<t<<' ';
        // sort(all(d));
        // sort(all(e));
        // // for(auto i:d)
        // //     cout<<i<<' ';
        // ll up=upper_bound(d.begin(),d.end(),t)-d.begin();
        // ll up2=upper_bound(e.begin(),e.end(),t)-e.begin();
        // // cout<<up<<' ';
        // // up--;
        // cout<<max(up,up2)<<endl;
    }
    return 0;
}