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

        vi a,b;
        map<ll,ll>mp;
        set<ll>st;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            
            st.insert(x);
        }
        for(ll i=0; i<m; i++){
            ll x;cin>>x;
            b.pb(x);
            mp[x]++;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(auto i:a)
            cout<<i<<' ';
        cout<<endl;    
        for(auto i:b)
            cout<<i<<' ';
        cout<<endl;    
        ll p=0;
        ll cur=0;
        // if(cur==b[p]){
        //     cur=0;
        //     p++;
        // }
        bool f=true;
        ll j=-1;
        for(ll i=0; i<n; i++){
            if(abs(cur-a[i])<=1){
                cur+=a[i];
            }
            else if(cur!=0){
                f=false;
                break;
            }
            else{
                cur=a[i];
            }
            if(mp.find(cur)!=mp.end() && mp[cur]>0){
                // cout<<cur<<' ';
                mp[cur]--;
                cur=0;
                p++;
            }
            if(p==m){
                j=i;
                break;
            }
        }
        if(!f){
            cout<<"No"<<endl;
            continue;
        }
        if(p==m && j==n-1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;    
        // bool f=true;
        // for(ll i=0; i<m; i++){
        //     ll k=b[i];
        //     if(mp.find(k) != mp.end() && mp[k]>0){
        //         // cout<<"hi ";
        //         mp[k]--;
        //         continue;
        //     }
        //     bool h=false;
        //     for(auto j:mp){
        //         if(j.second <= 0)
        //             continue;
        //         if(j.first > k){
        //             f=false;
        //             break;
        //         }
        //         ll f=k-j.first;
                
        //         if(mp.find(f)!=mp.end() && abs(f-j.first)<=1 && mp[f]>0){
        //             // cout<<j.first<<' '<<f<<' ';
        //             mp[j.first]--,mp[f]--;
        //             mp[j.first+f]++;
        //             h=true;
        //             break;
        //         }
        //     }
        //     if(!h || !f){
        //         f=false;
        //         break;
        //     }

        // }

        // if(f)
        //     cout<<"Yes"<<endl;
        // else
        //     cout<<"No"<<endl;    
    }
    return 0;
}