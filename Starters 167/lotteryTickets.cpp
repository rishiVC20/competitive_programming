// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
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
    return a.first < b.first;
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

        vector<pair<ll,ll>>v;

        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            v.pb({x,i});
        }

        sort(v.begin(),v.end(),customComparator);

        ll j;

        for(ll i=0; i<n; i++){
            if(v[i].second == 0){
                j=i;
                break;
            }
        }

        if(j==0){
            ll m=(v[j].first+v[j+1].first)/2;

            // ll f=m-v[j].first+1;
            // f+=v[j].first-1;
            ll f=m;
            cout<<f<<endl;
            continue;
        }
        if(j==n-1){
            ll m=(v[j].first+v[j-1].first+1)/2;
            // if(m-v[j-1].first > m-v[j].first)
            //     m++;
            // ll f=v[j].first-m+1;

            ll f=(1e6-m+1);

            cout<<f<<endl;
            continue;
        }

        ll m=(v[j].first+v[j-1].first+1)/2;
        // if(m-v[j-1].first < v[j].first-m)
        //     m++;
        // ll f=v[j].first-m+1;
        ll k=(v[j+1].first+v[j].first)/2;
        
        // if(v[j+1].first-k < k-v[j].first){
        //     k--;
        // }

        ll f=k-m+1;
        // cout<<m<<' '<<k<<' ';
        // f += (k-v[j].first);

        cout<<f<<endl;
    }
    return 0;
}