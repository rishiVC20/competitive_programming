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
        ll ck=0;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            ck+=(x==0);
        }
        if(ck==0){
            cout<<1<<endl;
            cout<<1<<' '<<n<<endl;
            continue;
        }
        if(ck==n){
            cout<<3<<endl;
            cout<<1<<' '<<2<<endl;
            cout<<2<<' '<<n-1<<endl;
            cout<<1<<' '<<2<<endl;
            continue;
        }

        if(ck==1){
            ll j;
            bool f=false;
            for(ll i=0; i<n; i++){
                if(a[i]==0){
                    f=true;
                    // break;
                }
                j=i;
                if(i==0){
                    continue;
                }
                if(f){
                    break;
                }
            }
            vvp v;
            if(j!=n-1){
                v.pb({1,j+1});
                // v.pb({1,})
                ll r=n-j;
                v.pb({1,r});
            }
            else{
                v.pb({n-1,n});
                v.pb({1,n-1});
            }
            cout<<(ll)v.size()<<endl;
            for(auto i:v){
                cout<<i.first<<' '<<i.second<<endl;
            }
            continue;
        }
        ll cur=1;
        ll mx=0;
        for(ll i=1; i<n; i++){
            if(a[i]==a[i-1] && a[i]==0){
                cur++;
            }
            else{
                cur=1;
            }
            mx=max(mx,cur);
        }
        // cout<<mx<<"hi ";
        if(mx==ck){
            ll st=-1,en=-1;
            for(ll i=0; i<n; i++){
                if(st==-1 && a[i]==0){
                    st=i;
                }
                if(a[i]==0){
                    en=i;
                }
            }
            ll r=en-st+1;
            ll q=n-r;
            // cout<<q<<' ';
            cout<<2<<endl;
            cout<<st+1<<' '<<en+1<<endl;
            cout<<1<<' '<<q+1<<endl;
            continue;
        }
        bool f=false;
        ll j;
        for(ll i=0; i<n; i++){
            if(a[i]==0){
                f=true;
            }
            j=i;
            if(i==0){
                continue;
            }
            if(f){
                break;
            }
        }
        // cout<<"hi "<<j<<' ';
        cout<<3<<endl;
        cout<<1<<' '<<j+1<<endl;
        ll r=n-j;
        cout<<2<<' '<<r<<endl;
        cout<<1<<' '<<2<<endl;
        // continue;
    }
    return 0;
}