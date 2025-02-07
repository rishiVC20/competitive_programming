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

// bool f(vector<vi> &a, vi &v, map<ll,ll> &mp, ll m, ll j,vi &d, vector<vector<bool>> &dp){

//     if(j>=m || v.size()==m){
//         d=v;
//         // cout<<"hi ";
//         return true;
//     }

//     // string key=to_string(j)+"_";
//     // for(auto &k:mp){
//     //     key+=to_string(k.first)+"_"+to_string(k.second)+"_";
//     // }

//     // if(dp[j][k]){
//     //     return dp[j][key];
//     // }
//     // cout<<"hoo ";
//     // cout<<a[j][0]<<' ';
//     for(ll k=1; k<=a[j][0]; k++){
//         ll t=a[j][k];
//         mp[t]++;
//         // cout<<"hie ";
//         if(mp[t] <= (m/2)){
//             // cout<<"hi ";
//             v.pb(t);
//             if(f(a,v,mp,m,j+1,d,dp)){
//                 // return dp[j][key]=true;
//                 return dp[j][k]=true;
//             }
//             v.pop_back();
//         }
//         mp[t]--;
//     }

//     return false;
//     // return dp[j][key]=false;
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr); std::cout.tie(nullptr);


//     ll tt;
//     cin>>tt;
//     while (tt--)
//     {
//         ll n,m;
//         cin>>n>>m;

//         double b=m;
//         ll lm=ceil(b/2);
//         // cout<<m<<" "<<lm<<' ';
//         vector<vi>a(m);
//         map<ll,ll>m1;
//         for(ll i=0; i<m; i++){
//             ll x;cin>>x;
//             vi p;
//             p.pb(x);
//             a[i].pb(x);
//             for(ll j=0; j<x; j++){
//                 ll y;cin>>y;
//                 // p.pb(y);
//                 m1[y]++;
//                 a[i].pb(y);
//             }
//             // a.insert(a.end(),p.begin(),p.end());
//         }
//         bool k=true;
//         for(auto i:m1){
//             if(i.second>lm){
//                 k=false;
//                 break;
//             }
//         }
//         if(k){
//             YES;
//             for(ll i=0; i<m; i++){
//                 cout<<a[i][1]<<' ';
//             }
//             cout<<endl;
//             continue;
//         }
        
//         map<ll,ll>ct;
//         vi ans(m);
//         bool ff=true;
//         // for(ll i=0; i<m; i++){
//         //     if(a[i][0] == 1){
//         //         ct[a[i][1]]++;
//         //         ans[i]=a[i][1];
//         //         if(ct[a[i][1]] > lm){
//         //             ff=false;
                
//         //         }
//         //     }
//         // }
//         // if(!ff){
//         //     NO;
//         //     continue;
//         // }
//         ll mm=0;
//         for(ll i=0; i<m; i++){
//             ll mini=LLONG_MAX;
//             // if(a[i][0] == 1)
//             //     continue;
//             for(ll j=1; j<=a[i][0]; j++){
//                 if(ct[a[i][j]] < mini){
//                     mini=ct[a[i][j]];
//                     ans[i]=a[i][j];
//                 }
//                 // else{
//                 //     ans[i]=a[i][j];
//                 //     // ct[a[i][j]]++;
//                 // }
//             }
//             ct[ans[i]]++;
//             // cout<<ans[i]<<" "<<ct[ans[i]]<<" ";
//             mm=max(mm,ct[ans[i]]);
//         }
//         // cout<<lm<<' ';
//         if(mm > lm){
//             // cout<<"h ";
//             NO;
//             continue;
//         }
//         YES;
//         for(auto i:ans) 
//             cout<<i<<' ';
//         cout<<endl;
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
        ll n,m;
        cin>>n>>m;

        double b=m;
        ll lm=ceil(b/2);
        vector<vi>v;
        map<ll,ll>mp;
        ll maxi=0;
        for(ll i=0; i<m; i++){
            ll x;cin>>x;
            vi temp;
            for(ll j=0; j<x; j++){
                ll y;cin>>y;
                temp.pb(y);
                mp[y]++;
                maxi=max(maxi,mp[y]);
            }
            v.pb(temp);
        }

        if(maxi <= lm){
            YES;
            for(ll i=0; i<m; i++){
                cout<<v[i][0]<<' ';
            }
            cout<<endl;
            continue;
        }

        vi ans(m);
        map<ll,ll>ct;
        for(ll i=0; i<m; i++){
            if(v[i].size() == 1){
                ct[v[i][0]]++;
                ans[i]=v[i][0];
            }
        }
        auto it=ct.begin();
        bool tt=true;
        while(it != ct.end()){
            ll p=(*it).second;
            if(p > lm){
                tt=false;
            }
            it++;
        }
        if(!tt){
            NO;
            continue;
        }

        YES;
        for(ll i=0; i<m; i++){
            if(v[i].size() == 1)
                continue;
            ll mini=LLONG_MAX  ;  
            for(ll j=0; j<v[i].size(); j++){
                if(ct[v[i][j]] < mini){
                    mini=ct[v[i][j]];
                    ans[i]=v[i][j];
                }
            }
            ct[ans[i]]++;
        }

        for(auto i:ans)
            cout<<i<<' ';
        cout<<endl;    

    }
    return 0;
}