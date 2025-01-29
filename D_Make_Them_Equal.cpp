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
vi a(10000,1000);

// void f(){

//     a[1]=0;

//     queue<pair<ll,ll>>q;
//     q.push({1,0});

//     while(!q.empty()){
//         ll x=q.front().first;
//         ll y=q.front().second;
//         q.pop();

//         for(ll i=1; i<=x; i++){
//             if(x%i!=0)
//                 continue;
//             // cout<
//             ll p1=x+(x/i);
//             if(p1<1000 && a[p1]>y+1){
//                 q.push({p1,y+1});
//                 a[p1]=y+1;
//             }
//             ll p2=x+i;
//             if(p2<10000 && a[p2]>y+1){
//                 q.push({p2,y+1});
//                 a[p2]=y+1;
//             }
//         }
//     }
// }


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    a[1]=0;
    for(ll i=1; i<1001; i++){
        for(ll j=1; j<=i; j++){
            ll p=i+(i/j);
            if(p<1001){
                a[p]=min(a[p],a[i]+1);
            }
        }
    }

    ll tt;
    cin>>tt;
    // f();
    while (tt--)
    {
        ll n,t;
        cin>>n>>t;
        vvp v(n);
        ll cn=0LL;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            v[i].first=x;
            cn+=x;
        }
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            v[i].second=x;
        }

        vvp d;
        for(ll i=0; i<n; i++){
            ll k=a[v[i].first];
            d.pb({k,v[i].second});
        }

        // for(auto i:d){
        //     cout<<i.first<<' '<<i.second;
        //     cout<<endl;    
        // }
        t=min({t,cn,12*n});
        // sort(d.begin(),d.end());

        // vector<vi>dp(n+1,vi(t+1,0));
        vi dp(t+1,0);

        for(ll i=1; i<=n; i++){
            // vi ff=dp;
            // for(ll j=d[i-1].first; j<=t; j++){
                
            //     if(j-d[i-1].first >= 0){
            //         // cout<<"hi ";
            //         // dp[j]=max(dp[i-1][j],dp[i-1][j-d[i-1].first]+d[i-1].second);
            //         dp[j]=max(ff[j],ff[j-d[i-1].first]+d[i-1].second);
            //     }
            //     else{
            //         dp[j]=ff[j];
            //     }
            //     // cout<<dp[i][j]<<' ';
            // }
            for (int j = t - d[i-1].first; j >= 0; j--) {
        dp[j + d[i-1].first] = max(dp[j + d[i-1].first], dp[j] + d[i-1].second);
      }
            // cout<<endl;
        }

        // for(auto i:dp){
        //     for(auto j:i)
                // cout<<i<<' ';
        //     cout<<endl;    
        // }
        cout<<dp[t]<<endl;
    }
    return 0;
}