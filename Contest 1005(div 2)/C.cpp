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
//         ll n;
//         cin>>n;
//         vi a;
//         ll j=n;
//         ll u=-1;
//         bool f=false;
//         for(ll i=0; i<n; i++){
//             ll x;cin>>x;
//             a.pb(x);
//             if(x<0 && !f){
//                 f=true;
//                 u=i;
//             }
//             if(x>0){
//                 j=i;
//             }
//         }

//         ll c1=0,c2=0;
//         vi d;
//         ll q1=-1,q2=-1;
//         ll r=-1;
//         bool t1=false,t2=false;
//         for(ll i=0; i<n; i++){
//             if(a[i]<0){
//                 if(!t1){
//                     t1=true;
//                     q1=i;
//                 }
//                 c1+=abs(a[i]);
//                 if(c2>0){
//                     d.pb(c2);
//                 }
//                 c2=0;
//                 if(i==n-1){
//                     d.pb(c1);
//                 }
//             }
//             else{
                
//                 if(!t2){
//                     q2=i;
//                     t2=true;
//                 }
//                 c2+=abs(a[i]);
//                 if(c1>0){
                    
//                     d.pb(c1);
//                 }
//                 if(r==-1){
//                     r=(ll)d.size();
//                 }
//                 c1=0;
//                 if(i==n-1){
//                     d.pb(c2);
//                 }
//             }
//             // cout<<c1<<' '<<c2<<' ';
//         }
//         for(auto i:d)
//             cout<<i<<' ';
//         if(q1==-1 || q2==-1){
//             ll t=accumulate(d.begin(),d.end(),0LL);
//             cout<<t<<endl;
//             continue;
//         }
//         ll k1=0,k2=0;
//         if(r!=0){
//             k1=d[0];
//         }
//         // cout<<r<<' ';

//         ll rr=0;

//         // for(ll i=r; i<(ll)d.size(); i+=2){
//         //     ll kk=d[i];
//         //     if(i+1<(ll)d.size()){
//         //         kk+=d[i+1];
//         //     }
//         //     rr=max(rr,kk);
//         // }
//         ll tt=0;
//         ll cp=0;
//         for(ll i=r; i<(ll)d.size(); i+=2){
//             cp+=d[i];
//             if(i+1<(ll)d.size()){
//                 cp+=d[i+1];
//                 tt=max(tt,cp);
//                 cp-=d[i+1];
//             }
//             tt=max(tt,cp);
//         }
//         ll pp=0;
//         // for(ll i=r; i<(ll)d.size(); i+=2){
//         //     pp+=d[i];
//         // }

//         ll qq=0;
//         ll c;
//         if(r==1){
//             if((ll)d.size()&1){
//                 c=(ll)d.size()-1;
//             }
//             else{
//                 c=(ll)d.size()-2;
//             }
//         }
//         else{
//             if((ll)d.size()&1){
//                 c=(ll)d.size()-2;
//             }
//             else{
//                 c=(ll)d.size()-1;
//             }
//         }
//         // cout<<c<<' ';
//         ll ee=0;
//         ll cn=0;
//         for(ll i=c; i>=0; i-=2){
//             cn+=d[i];
//             if(i-1>=0){
//                 cn+=d[i-1];
//                 ee=max(ee,cn);
//                 cn-=d[i-1];
//             }
//             ee=max(ee,cn);
//         }
//         cout<<max({ee,tt})<<endl;
        
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
        ll n;
        cin>>n;

        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        vi v1(n),v2(n);
        ll cp=0;
        for(ll i=0; i<n; i++){
            if(a[i]>0){
                cp+=abs(a[i]);
            }
            v1[i]=cp;
        }
        cp=0;
        for(ll i=n-1; i>=0; i--){
            if(a[i]<0){
                cp+=abs(a[i]);   
            }
            v2[i]=cp;
        }

        ll maxi=0;
        for(ll i=0; i<n; i++){
            ll t=v1[i]+v2[i];
            maxi=max(maxi,t);
        }

        cout<<maxi<<endl;

    }
    return 0;
}