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
        ll n,m;
        cin>>n>>m;
        vector<vi>a(n,vi(m));
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cin>>a[i][j];
            }
        }

        set<ll>s1,s2,s3,s4;
        for(ll i=0; i<n; i+=2){
            for(ll j=0; j<m; j+=2){
                s1.insert(a[i][j]);
            }
        }
        for(ll i=0; i<n; i+=2){
            for(ll j=1; j<m; j+=2){
                s2.insert(a[i][j]);
            }
        }
        for(ll i=1; i<n; i+=2){
            for(ll j=0; j<m; j+=2){
                s2.insert(a[i][j]);
            }
        }
        for(ll i=1; i<n; i+=2){
            for(ll j=1; j<m; j+=2){
                s1.insert(a[i][j]);
            }
        }

        map<ll,ll>mp;
        for(auto i:s1){
            // cout<<i<<' ';
            mp[i]++;
        }
        // cout<<"j ";
        for(auto i:s2){
            // cout<<i<<' ';
            mp[i]++;
        }
        // for(auto i:s3){
        //     mp[i]++;
        // }
        // for(auto i:s4){
        //     mp[i]++;
        // }

        ll maxi=0,j=-1;
        for(auto i:mp){
            // cout<<i.first<<' '<<i.second<<' '; 
            if(i.second>maxi){
                maxi=i.second;
                j=i.first;
            }
        }
        ll cn=0;

        // for(auto i:s1){
        //     if(s3.find(i)!=s3.end()){
        //         continue;
        //     }
        //     if(i==j){
        //         continue;
        //     }
        //     s3.insert(i);
        //     cn++;
        // }
        // for(auto i:s2){
        //     if(s3.find(i)!=s3.end()){
        //         continue;
        //     }
        //     if(i==j){
        //         continue;
        //     }
        //     s3.insert(i);
        //     cn++;
        // }
        // if(s1.find(j)!=s1.end()){
        //     cn+=(ll)s1.size()-1;
        // }
        // else{
        //     cn+=(ll)s1.size();
        // }
        // if(s2.find(j)!=s2.end()){
        //     cn+=(ll)s2.size()-1;
        // }
        // else{
        //     cn+=(ll)s2.size();
        // }
        set<ll>sp,sk;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                bool f=false;
                ll t=a[i][j];
                if(i-1>=0){
                    if(a[i-1][j]==t){
                        f=true;
                    }
                }
                if(i+1<n){
                    if(a[i+1][j]==t){
                        f=true;
                    }
                }
                if(j+1<m){
                    if(a[i][j+1]==t){
                        f=true;
                    }
                }
                if(j-1>=0){
                    if(a[i][j-1]==t){
                        f=true;
                    }
                }
                if(f){
                    sp.insert(t);
                    sk.insert(t);
                }
                else{
                    sp.insert(t);
                }

            }
        }
        vi d;
        for(ll i=1; i<=n*m; i++){
            ll k=(sp.find(i)!=sp.end());
            ll p=(sk.find(i)!=sk.end());
            // cout<<k<<' '<<p<<' ';
            if(k==0 && p==0){
                continue;
            }
            if(k==1 && p==1){
                d.pb(2);
            }
            else if(p==1 || k==1){
                d.pb(1);
            }
        }
        // for(auto i:sp)
        //     cout<<i<<' ';
        // for(auto i:sk)
        //     cout<<i<<' ';
        sort(d.begin(),d.end());
        ll r=accumulate(d.begin(),d.end(),0LL);
        // cout<<r<<' ';
        cout<<r-d.back()<<endl;
    }
    return 0;
}