// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>
// #define vvp vector<pair<ll,ll>>
// #define vvt vector<tuple<ll,ll,ll>>
// #define all(a) (a).begin(),(a).end()
// #define rall(a) (a).rbegin(),(a).rend()
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
//         ll n,k,z;
//         cin>>n>>k>>z;

//         vi a;
//         for(ll i=0; i<n; i++){
//             ll x;cin>>x;
//             a.pb(x);
//         }

//         ll cur=a[0];
//         vi pre(n);
//         pre[0]=a[0];
//         for(ll i=1; i<n; i++){
//             pre[i]=pre[i-1]+a[i];
//         }
//         ll maxi=pre[k];
//         for(ll i=0; i<n; i++){
//             ll t=pre[i];
//             ll p=k-i;

//             for(ll j=0; j<=z; j++){
//                 ll f=j*a[i];
//                 ll r=p;
//                 r-=j;
//                 cout<<r<<"t ";
//                 if(j+1>=r){
//                     f+=(j+1)*a[i+1];
//                     r-=(j+1);
//                 }
//                 else{
//                     f+=(j+1)*a[i+1];
//                     r=0;
//                     // r-=r;
//                 }
//                 // f+=(j+1)*a[i+1];
//                 // ll r=p;
//                 // r-=(2*j+1);
//                 // cout<<i<<' '<<j<<' '<<t<<' '<<f<<' '<<' '<<maxi<<"j "<<endl;;
//                 // maxi=max(maxi,t+f);
//                 // if(r<=0)
//                 //     continue;
//                 ll m=0;
//                 if(r>=0 && r+1+i < n)
//                     m+=pre[r+i+1]-pre[i+1];
//                 maxi=max(maxi,t+f+m);  
//                 cout<<i<<' '<<j<<' '<<t<<' '<<f<<' '<<m<<' '<<maxi<<"k "<<endl;  
//             }
//         }
//         // maxi=max(maxi,pre[k]);
//         cout<<maxi<<endl;
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
        ll n,k,z;
        cin>>n>>k>>z;

        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        ll cur=a[0];
        vi pre(n);
        pre[0]=a[0];
        for(ll i=1; i<n; i++){
            pre[i]=pre[i-1]+a[i];
        }
        ll maxi=pre[k];
        for(ll i=0; i<k; i++){
            ll t=pre[i];
            ll p=k-i;

            for(ll j=0; j<=min(z,p/2); j++){
                ll f=j*a[i];
                ll r=p;
                r-=j;
                // cout<<r<<"t ";
                if(r>0 && (j+1)<=r){
                    f+=(j+1)*a[i+1];
                    r-=(j+1);
                    // cout<<"ho ";
                }
                else if(r>0){
                    f+=(r)*a[i+1];
                    r=0;
                    // r-=r;
                    // cout<<"hi ";
                }
                else{
                    continue;
                }
                // f+=(j+1)*a[i+1];
                // ll r=p;
                // r-=(2*j+1);
                // cout<<i<<' '<<j<<' '<<t<<' '<<f<<' '<<' '<<maxi<<"j "<<endl;;
                // maxi=max(maxi,t+f);
                // if(r<=0)
                //     continue;
                ll m=0;
                // cout<<r<<" "<<(r+1+i)<<"r ";
                if(r>=0 && r+1+i < n)
                    m+=pre[r+i+1]-pre[i+1];
                // cout<<m<<" gg";    
                maxi=max(maxi,t+f+m);  
                // cout<<i<<' '<<j<<' '<<t<<' '<<f<<' '<<m<<' '<<maxi<<"k "<<endl;  
            }
        }
        // maxi=max(maxi,pre[k]);
        cout<<maxi<<endl;
    }
    return 0;
}