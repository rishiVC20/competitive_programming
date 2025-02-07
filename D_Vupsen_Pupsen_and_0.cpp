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


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vvp a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb({x,i});
        }
        vvp v=a;
        sort(all(a));
        vi b;
        for(ll i=0; i<n; i+=2){
            if(i==n-3){
                break;
            }
            ll k1=abs(a[i].first),k2=abs(a[i+1].first);
            // ll t=LCM(k1,k2);
            // ll p1=t/k1,p2=t/k2;
            if(a[i].first<0 && a[i+1].first<0){
                b.pb(-1LL*a[i+1].first),b.pb(a[i].first);
            }
            else if(a[i].first<0 && a[i+1].first>0){
                b.pb(k2),b.pb(k1);
            }
            else{
                b.pb(-1LL*a[i+1].first),b.pb(a[i].first);
            }
        }

        if(n&1){
            if((a[n-3].first<0 && a[n-2].first<0) || (a[n-2].first>0 && a[n-3].first>0)){
                // cout<<"ho ";
                b.pb(a[n-1].first);
                b.pb(a[n-1].first);
                b.pb(-1LL*(a[n-2].first+a[n-3].first));
            }
            else{
                b.pb(-1LL*(a[n-2].first+a[n-1].first));
                b.pb(a[n-3].first);
                b.pb(a[n-3].first);
            }
            
        }
        // for(auto i:b)
        //     cout<<i<<' ';
        // cout<<"r ";    
        vi ans(n);
        for(ll i=0; i<n; i++){
            ans[a[i].second]=b[i];
            // cout<<ans[i]<<' ';
        }
        for(auto i:ans)
            cout<<i<<' ';
        // ll m=0;    
        // for(ll i=0; i<n; i++){
        //     m+=v[i].first*ans[i];
        // }    
        // cout<<m<<' ';
        cout<<endl;
    }
    return 0;
}