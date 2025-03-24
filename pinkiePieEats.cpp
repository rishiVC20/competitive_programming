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
    return a.second > b.second;
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

bool solve(ll n, ll mid, vvp v){
    // ll tp=v[0].second+mid*(v[0].second-1);
    // if(tp>=n)
    //     return false;
    set<pair<int, int>, greater<pair<int, int>>> ss;
    vi cn(n,0);
    for(auto i:v){
        cn[i.first]=i.second;
        ss.insert({i.second,i.first});
    }
    // for(auto i:ss){
    //     cout<<i.first<<' '<<i.second<<endl;
    // }

    vi d;
    for(ll i=0; i<n; i++){
        if(i>=mid && cn[d[i-mid]]>0){
            ss.insert({cn[d[i-mid]],d[i-mid]});
        }

        if(ss.empty())
            return 0;
        d.pb(ss.begin()->second);
        ss.erase(ss.begin());
        cn[d.back()]--;
        // for(auto i:ss){
        //     cout<<i.first<<' '<<i.second<<"H "<<endl;;
        // }
        // cout<<endl;
    }
    // for(auto i:d){
    //     cout<<i<<' ';
    // }
    return true;
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
        vi a;
        map<ll,ll>mp;
        vvp v;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            x--;
            a.pb(x);
            mp[x]++;
        }
        // if(n==1){
        //     cout<<1<<endl;
        //     continue;
        // }
        for(auto i:mp){
            v.pb({i.first,i.second});
        }
        sort(all(v),customComparator);
        // if(v[0].second>(n+2)/2){
        //     cout<<0<<endl;
        //     continue;
        // }
        // queue<ll>q;
        // for(auto i:v){
        //     q.push(i.first);
        // }

        // vi d;
        // while(!q.empty()){
        //     ll x=q.front();
        //     q.pop();
        //     mp[x]--;
        //     if(mp[x]>0){
        //         q.push(x);
        //     }
        //     // cout<<x<<' ';
        //     d.pb(x);
        // }
        // for(auto i:d)
        //     cout<<i<<' ';
        // set<ll>st;
        // vi ff(n,-1);
        // ll dis=n;
        // for(ll i=0; i<n; i++){
        //     if(ff[d[i]]==-1){
        //         ff[d[i]]=i;
        //     }
        //     else{
        //         dis=min(dis,i-ff[d[i]]-1);
        //         ff[d[i]]=i;
        //         // break;
        //     }
        // }
        ll l=0, r=n;
        ll ans=0;
        while(r-l>1){
            ll mid=l+(r-l)/2;
            // cout<<mid<<"g ";
            if(solve(n,mid,v)){
                ans=mid;
                l=mid;
            }
            else{
                // cout<<mid<<"y ";
                r=mid;
            }
        }
        // for(auto i:ff)
        //     cout<<i<<' ';
        cout<<ans-1<<endl;
    }
    return 0;
}