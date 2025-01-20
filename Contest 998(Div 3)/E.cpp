// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>
// #define vvp vector<pair<ll,ll>>
// #define vvt vector<tuple<ll,ll,ll>>
// #define YES cout<<'Y'<<'E'<<'S'<<endl
// #define NO cout<<'N'<<'O'<<endl  

// const ll mod = 1e9+7;

// class Disjoint{
//     vector<ll>size,rank,parent;
// public:
//     Disjoint(ll n){
//         size.resize(n+1,1);
//         parent.resize(n+1);
//         rank.resize(n+1,0);
//         for(ll i=0; i<=n; i++)
//             parent[i]=i;
//     }
//     ll findParent(ll node){
//         if(node==parent[node])
//             return node;
//         return parent[node]=(findParent(parent[node]));
//     }
//     void unionByRank(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u]<rank[ulp_v]){
//             parent[ulp_u]=ulp_v;
//         }
//         else if(rank[ulp_u]>rank[ulp_v]){
//             parent[ulp_v]=ulp_u;
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             rank[ulp_u]++;
//         }
//     }
//     void unionBySize(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(size[ulp_u]<size[ulp_v]){
//             parent[ulp_u]=ulp_v;
//             size[ulp_v]+=size[ulp_u];
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             size[ulp_u]+=size[ulp_v];
//         }
//     }
// };
// ll mAdd(ll a, ll b, ll m = mod){
//     a = a % m;
//     b = b % m;
//     return (((a + b) % m) + m) % m;
// }
// ll mSub(ll a, ll b, ll m = mod){
//     a = a % m;
//     b = b % m;
//     return (((a - b) % m) + m) % m;
// }
// ll mul (ll a, ll b, ll m=mod){
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll LCM(ll a, ll b){
    
//     a = (a*b)/(__gcd(a,b));
//     return a;
// }
// bool customComparator(const pair<int, int> &a, const pair<int, int> &b){
//     return a.second < b.second;
// }
// ll power(ll base, ll exponent){
//     if (exponent < 0){
//         return 0;
//     }
//     ll ans = 1;
//     while (exponent){
//         if (exponent%2==0){
//             base = (base*base) % mod;
//             exponent = exponent/2;
//         }
//         else{
//             ans = (ans*base) % mod;
//             exponent--;
//         }
//     }
//     return ans;
// }
// ll invmod(ll a, ll m = mod){
//     return power(a, m - 2);
// }
// ll div(ll a, ll b, ll m = mod){
//     a = a % m;
//     b = b % m;
//     return mul(a, invmod(b, m), m);
// }


// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr); std::cout.tie(nullptr);


//     ll tt;
//     cin>>tt;
//     while (tt--)
//     {
//         ll n,m1,m2;
//         cin>>n>>m1>>m2;

//         vvp v1,v2;
//         map<ll,vi>mp;
//         // vector<vector<ll>>vv(n,vi(n,0));
//         Disjoint d1(n),d2(n);
//         vi a(n);
//         for(ll i=0; i<m1; i++){
//             ll u,v;
//             cin>>u>>v;
//             u--,v--;
//             a[u]++,a[v]++;
//             // d1.unionBySize(u,v);
//             v1.pb({u,v});
//             // vv[u][v]=1,vv[v][u]=1;
//             // ll d1=min(u,v);
//             // ll d2=max(u,v);
//             // mp[d1].pb(d2);
//         }

//         ll cp=0;
//         // ll p=0;
//         for(ll i=0; i<m2; i++){
//             ll u,v;
//             cin>>u>>v;
//             // ll d1=min(u,v),d2=max(u,v);
//             // if(mp.find)
//             u--,v--;
//             v2.pb({u,v});
//             d2.unionBySize(u,v);
//             // if(vv[u][v] != 1){
//             //     cp++;
//             // }   
//             // else{
//             //     p++;
//             // }
//         }
//         set<ll>ss;
//         for(ll i=0; i<m1; i++){
//             ll t1=d2.findParent(v1[i].first);
//             ll t2=d2.findParent(v1[i].second);
//             if(t1 != t2){
//                 cp++;
//             }
//             else{
//                 d1.unionBySize(v1[i].first,v1[i].second);
//             }
//         }
//         // cout<<cp<<' ';
//         // if(cp==0){
//         //     cout<<0<<endl;
//         //     continue;
//         // }
//         // for(ll i=0; i<m1; i++){
//         //     d1.unionBySize(v1[i].first,v1[i].second);
//         // }
//         // for(ll i=0; i<n; i++){
//         //     if(d1.findParent(i) != d2.findParent(i)){
//         //         cp++;
//         //     }
//         // }
//         // cp += m2;
//         set<ll>s1,s2;
//         for(ll i=0; i<n; i++){
//             s1.insert(d1.findParent(i));
//             s2.insert(d2.findParent(i));
//         }
//         cp += abs((ll)s1.size()-(ll)s2.size());
//         // ll t=m1-p;
//         // cp += t;

//         cout<<cp<<endl;

//     }
//     return 0;
// }   



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
        ll n,m1,m2;
        cin>>n>>m1>>m2;

        vvp v1,v2;
        Disjoint d1(n),d2(n);

        for(ll i=0; i<m1; i++){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            v1.pb({u,v});
        }

        for(ll i=0; i<m2; i++){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            v2.pb({u,v});
            d2.unionBySize(u,v);
        }

        ll cn=0; 
        for(ll i=0; i<m1; i++){
            ll p=d2.findParent(v1[i].first),q=d2.findParent(v1[i].second);
            if(p!=q){
                cn++;
            }
            else{
                d1.unionBySize(v1[i].first,v1[i].second);
            }
        }

        set<ll>s1,s2;
        for(ll i=0; i<n; i++){
            s1.insert(d1.findParent(i));
            s2.insert(d2.findParent(i));
        }

        cn += abs((ll)s1.size()-(ll)s2.size());

        cout<<cn<<endl;
    }
    return 0;
}