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
ll mdiv(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return mul(a, invmod(b, m), m);
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    set<pair<ll,ll>>st;
    ll t=2;
    ll k=3;
    while(t<=1e16 && k<=1e6){
        t=(t*k)%mod;
        k++;
        st.insert({t,k});
    }

    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        // for(auto i:st){
        //     cout<<i.first<<' '<<i.second<<' ';
        //     if(i.first==120){
        //         break;
        //     }
        // }
        // cout<<endl;
        auto it=st.upper_bound({n,LLONG_MAX});
        ll ans=0;
        ll p=(n+1)/2;
        ans += mul(p,2)%mod;
        ans += (mul((n/2),3))%mod;

        if(it!=st.begin()){
            it--;
            ll jj=it->second;
            ll r=mul(jj,mdiv((jj+1),2))%mod - mul(jj,mdiv((jj-1),2))%mod;
            ll m=jj-3;
            // ll p=mdiv(2LL,3LL);
            ans -= mul(mdiv((m+1),(ll)2),3)%mod;
            ans -= mul(mdiv(m,2),2)%mod;
            ans += (r)%mod;
            // ans=(ans-(((m + 1)/2)*3)%mod+mod)%mod;
            // ans=(ans-((m / 2)*2)%mod+mod) % mod;
            // ans=(ans+r) % mod;
        }

        cout<<ans<<endl;
    }
    return 0;
}