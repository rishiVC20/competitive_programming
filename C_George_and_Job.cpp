// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
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
ll maxi=INT_MIN;
ll solve(vi &p, ll k, vi &t, ll j, ll m, vi &dp){
    if(t.size() == k){
        // cout<<"hi ";
        ll s=accumulate(t.begin(),t.end(),0LL);
        // cout<<s<<' ';
        // maxi=max(maxi,s);
        return s;
    }
    if(j>=p.size()){
        return 0;
    }

    if(dp[j] != -1)
        return -1;

    t.pb(p[j]);
    ll x=solve(p,k,t,j+m,m,dp);
    t.pop_back();
    ll y=solve(p,k,t,j+1,m,dp);

    return dp[j]=max(x,y);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,m,k;
        cin>>n>>m>>k;

        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        vi pre;
        pre.pb(a[0]);
        for(ll i=1; i<n; i++){
            pre.pb(pre.back()+a[i]);
        }

        vi p;
        for(ll i=m-1; i<n; i++){
            ll x;
            if(i==m-1)
                x=pre[i];
            else    
                x=pre[i]-pre[i-m];
            p.pb(x);        
        }
        // for(auto i:p)
        //     cout<<i<<' ';
        // cout<<endl;    
        ll r=p.size();
        vi t;
        vector<vi> dp(r+1,vi(k+1,-1));
        for(ll i=0; i<=r; i++)
            dp[i][0]=0;
        // dp[1][1]=p[0];
        for(ll i=1; i<=r; i++){
            for(ll j=1; j<=k; j++){
                dp[i][j]=max(p[i-1],dp[i-1][j]);
                if(i>=m){
                    // cout<<"hi";
                    dp[i][j]=max(dp[i][j],dp[i-m][j-1]+p[i-1]);
                }
            }
        }

        // for(auto i:dp){
        //     for(auto j:i)
        //         cout<<j<<' ';
        //     cout<<endl;    
        // }

        cout<<dp[r][k]<<endl;
    }
    return 0;
}   