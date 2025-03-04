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
        ll n,l,r;
        cin>>n>>l>>r;

        vi a;
        vi v;
        a.pb(-1),v.pb(-1);
        ll t=0;
        for(ll i=1; i<=n; i++){
            ll x;cin>>x;
            a.pb(x);
            t+=(x==1);
            v.pb(t);
            // if(t%2){
            //     v.pb(1);
            // }
            // else{
            //     v.pb(0);
            // }
        }

        if(n%2==0){
            ll p=n/2;
            if(v[p]%2){
                a.pb(1);
                v.pb(v.back()+1);
            }
            else{
                a.pb(0);
                v.pb(v.back());
            }
            // v.pb(v[p]);
            n++;
        }

        for(ll i=n+1; i<=2*n; i++){
            ll k=i/2;
            // cout<<k<<' ';
            // a.pb(a[k]);
            if(v[k]%2){
                a.pb(1);
                v.pb(v.back()+1);
            }
            else{
                a.pb(0);
                v.pb(v.back());
            }
        }
        // for(auto i:v)
        //     cout<<i<<' ';
        if(l<=2*n){
            if(v[l/2]%2){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
            // cout<<v[l]<<endl;
            continue;
        }
        ll m=2*n;
        ll q=v.back();
        // cout<<q<<' ';
        ll d=l/2;
        // cout<<d<<' ';
        if((d-n)%2==0){
            // cout<<"ho ";
            if(v[n]%2){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
            // cout<<a[n]<<endl;
            continue;
        }
        // cout<<"hi ";

        ll k=v.size();
        ll cn=0;
        while(d>=m){
            d/=2;
            cn++;
        }
        // cout<<d<<' ';
        ll f=v[n];
        if(v[d]%2==1){
            if(cn%2==1)
                f++;
        }
        ll ans;
        if(f%2)
            ans=1;
        else
            ans=0;    
        deque<ll>dq;
        dq.
        cout<<ans<<endl;
    }
    return 0;
}