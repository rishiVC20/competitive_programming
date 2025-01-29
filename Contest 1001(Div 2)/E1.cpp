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
    return a.first > b.first;
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
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        vvp v;
        vector<vi>adj(n);
        ll maxi=0;
        ll m1=0;
        for(ll i=0; i<n-1; i++){
            ll x,y;
            cin>>x>>y;
            x--,y--;
            adj[x].pb(y);
            adj[y].pb(x);
            v.pb({x,y});
            if(x==0){
                if(a[y] < a[x]){
                    maxi=max(maxi,a[y]);
                }
                m1=max(m1,a[y]);
            }
            if(y==0){
                if(a[x] < a[y]){
                    maxi=max(maxi,a[x]);
                }
                m1=max(m1,a[x]);
            }
            
        }

        
        if(m1 > a[0] && m1 != maxi && maxi!=0){
            ll j;
            for(ll i=0; i<n-1; i++){
                if(v[i].first == 0){
                    if(a[v[i].second] == maxi){
                        j=v[i].second;
                        break;
                    }
                }
                if(v[i].second == 0){
                    if(a[v[i].first] == maxi){
                        j=v[i].first;
                        break;
                    }
                }
            }

            cout<<j<<endl;
            continue;
        }

        vvp d;
        for(ll i=0; i<n; i++){
            d.pb({a[i],i});
        }
        sort(d.begin(),d.end(),customComparator);

        if(d[n-1].first == d[0].first){
            cout<<0<<endl;
            continue;
        }

        ll g;
        ll mm=0;
        for(ll i=0; i<n; i++){
            if(mm < v[i].first){
                mm=v[i].first;
                g=i;
            }
        }
        if(g==0){
            ll t=0,r;
            for(ll i=0; i<n; i++){
                if(i==g)
                    continue;
                if(mm!=v[i].first){
                    t=max(t,mm);
                    r=i;
                }    
            }
            if(t==0){
                cout<<0<<endl;
            }
            else{
                cout<<r<<endl;
            }
            continue;
        }

        


    }
    return 0;
}