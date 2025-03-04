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
        n+=n;
        vi a;
        map<ll,ll>mp;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            mp[x]++;
        }

        sort(a.rbegin(),a.rend());
        // for(auto i:a)
        //     cout<<i<<' ';
        // cout<<endl;    
        ll t=a[0];

        vvp v;
        for(ll i=1; i<n; i++){
            ll m=a[i];
            vvp k;
            map<ll,ll>m1=mp;
            k.pb({t,m});
            m1[m]--,m1[t]--;
            for(ll j=1; j<n; j++){
                if(m1[a[j]]==0)
                    continue;
                // if(j==i){
                //     continue;
                // }
                // cout<<j<<' ';
                ll x=max(k.back().first,k.back().second);
                ll p=a[j];
                ll r=x-p;
                // cout<<p<<' '<<x<<' '<<r<<"x ";
                m1[p]--;
                if(m1.find(r)!=m1.end() && m1[r]>0){
                    // cout<<i<<' '<<j<<"j ";
                    m1[r]--;
                    k.pb({p,r});
                }
                else{
                    // cout<<i<<' '<<j<<endl;
                    break;
                }
            }
            // cout<<(ll)k.size()<<"t ";
            if(k.size()==n/2){
                
                v=k;
                break;
            }
        }

        if((ll)v.size()==n/2){
            YES;
            cout<<v[0].first+v[0].second<<endl;
            for(ll i=0; i<(ll)v.size(); i++){
                cout<<v[i].first<<' '<<v[i].second<<endl;
            }
            continue;
        }

        NO;
    }
    return 0;
}