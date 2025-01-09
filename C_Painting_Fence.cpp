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

ll f(ll l, ll r, vi &arr){
    if(l==r)
        return 1;

    ll md=(l+r)/2;
    ll left=f(l,md,arr);
    ll right=f(md+1,r,arr);

    ll mini=min(arr[md],arr[md+1]);

    ll op=0;
    for(ll i=l; i<=md; i++){
        op += mini-arr[i];
    }    

    for(ll i=md+1; i<=r; i++){
        op += mini-arr[i];
    }

    return left+right+op;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;

        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        ll d=f(0,n-1,a);

        cout<<d<<endl;

        // vi b;

        // ll mini=LLONG_MAX;
        // for(ll i=0; i<n; i++){
        //     mini=min(mini,a[i]);
        // }

        // ll t=0;
        // for(ll i=0; i<n; i++){
        //     a[i] -= mini;
        //     t += (a[i]==0);
        // }
        
        // ll cn=0;
        // if(t != 0){
        //     cn++;
        // }

        // while(t < n){
        //     for(auto i:a)
        //         cout<<i<<' '; 
        //     ll j=-1;
        //     for(ll i=0; i<n-1; i++){
        //         if(a[i]!=0 && a[i+1]!=0){
        //             j=i;
        //             break;
        //         }
        //     }
        //     if(j==-1){
        //         break;
        //     }
        //     ll m=j;
        //     ll k;
        //     for(m=j; m<n; m++){
        //         if(a[m]==0){
        //             k=m-1;
        //             break;
        //         }
        //     }
        //     if(m==n){
        //         k=n-1;
        //     }

        //     ll tp=LLONG_MAX;
        //     for(ll i=j; i<=k; i++){
        //         tp=min(tp,a[i]);
        //     }
        //     for(ll i=j; i<=k; i++){
        //         a[i] -= tp;

        //         t += (a[i]==0);
        //     }
        //     cn++;

        //     // for(ll )
        // }

        // cout<<min(n,cn)<<endl;

    }
    return 0;
}