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


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;

        vi a;
        ll j=-1;
        ll m=-1;
        bool f=false;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(x==0 && !f){
                j=i;
                f=true;
            }
            if(x==0){
                m=i;
            }
        }
        vi ans(n,0);
        for(ll i=0; i<n; i++){
            if(a[i]!=0)
                continue;

            if(i+1<n && a[i+1]!=0){
                ll t=a[i+1]/k + (a[i+1]%k!=0);
                ans[i+1]=t;
            }    
            if(i-1 >= 0 && a[i-1]!=0){
                ll t=a[i-1]/k + (a[i-1]%k!=0);
                ans[i-1]=t;
            }
        }

        ll mini1=LLONG_MIN;
        vi v1(n,LLONG_MAX),v2(n,LLONG_MAX);
        for(ll i=j; i<n; i++){
            if(a[i]==0){
                mini1=0;
                // continue;
            }
            mini1=max(mini1,a[i]);
            v1[i]=mini1;
        }
        ll mini2=LLONG_MIN;        
        for(ll i=j; i>=0; i--){
            if(a[i]==0){
                mini2=0;
            }
            mini2=max(mini2,a[i]);
            v2[i]=mini2;
        }

        if(j!=m){
            ll k1=LLONG_MIN;
            for(ll i=m; i<n; i++){
                if(a[i]==0){
                    k1=0;
                }
                k1=max(k1,a[i]);
                v1[i]=min(v1[i],k1);
            }
            ll k2=LLONG_MIN;
            for(ll i=m; i>=0; i--){
                if(a[i]==0){
                    k2=0;
                }
                k2=max(k2,a[i]);
                v2[i]=min(v2[i],k2);
            }
        }
        for(ll i=0; i<n; i++){
            if(a[i]!=0 && ans[i]==0){
                ll p1=v1[i],p2=v2[i];
                // cout<<p1<<' '<<p2<<"j ";
                ll mn=min(p1,p2);
                ll mx=max(p1,p2);
                if(mn>=a[i]){
                    ll t=mn/k+(mn%k!=0);
                    ans[i]=t;
                }
                else if(mx>=a[i] && a[i]>mn){
                    ll t=mx/k+(mx%k==0);
                    ans[i]=t;
                }
                else{
                    ll t=a[i]/k+(a[i]%k!=0);
                    ans[i]=t;
                }
            }
        }

        for(auto i:ans)
            cout<<i<<' ';
        cout<<endl;    
    }
    return 0;
}