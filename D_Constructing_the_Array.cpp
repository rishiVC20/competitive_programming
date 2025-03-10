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
        ll n;
        cin>>n;

        auto comp=[](tuple<ll,ll,ll> &a, tuple<ll,ll,ll> &b){
            if(get<0>(a) != get<0>(b))
                return get<0>(a) < get<0>(b);
            return get<1>(a) > get<1>(b);    
        };
        vi ans(n+1,0);
        priority_queue<tuple<ll,ll,ll>,vvt,decltype(comp)>q(comp);
        q.push({n,1,n});
        ll op=1;
        while(!q.empty()){
            auto i=q.top();
            q.pop();
            ll len=get<0>(i);
            ll l=get<1>(i),r=get<2>(i);
            // cout<<len<<' '<<l<<' '<<r<<endl;
            if(len%2){
                ll mid=(l+r)/2;
                // cout<<mid<<"o ";
                ans[mid]=op;
                op++;
                ll t1=mid-1,t2=mid+1;
                if(t1>=l){
                    // cout<<"hi ";
                    ll lp=t1-l+1;
                    q.push({lp,l,t1});
                }
                if(t2<=r){
                    // cout<<"hie ";
                    ll lp=r-t2+1;
                    q.push({lp,t2,r});
                }
            }
            else{
                ll mid=(l+r-1)/2;
                // cout<<mid<<"e ";
                ans[mid]=op;
                op++;
                ll t1=mid-1,t2=mid+1;
                if(t1>=l){
                    ll lp=t1-l+1;
                    q.push({lp,l,t1});
                }
                if(t2<=r){
                    // cout<<"hie ";
                    ll lp=r-t2+1;
                    q.push({lp,t2,r});
                }
            }
            
        }

        for(ll i=1; i<=n; i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}