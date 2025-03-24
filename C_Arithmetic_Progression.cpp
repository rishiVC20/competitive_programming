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


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vi a;
        bool r=true;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(i!=0){
                if(a[i]!=a[i-1]){
                    r=false;
                }
            }
        }
        if(r && n>1){
            cout<<1<<endl;
            cout<<a[0]<<endl;
            continue;
        }
        sort(all(a));
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n==2){
            ll d=a[1]-a[0]-1;
            ll ans=0;
            ll md=-1;
            // if(a[1]==a[0]){
            //     cout<<1<<endl;
            //     cout<<a[0]<<endl;
            //     continue;
            // }
            if(d&1){
                ans=3;
                ll g=(a[1]+a[0])/2;
                md=g;
                ll dif=a[1]-a[0];
                ll t1=a[0]-dif;
                ll t2=a[1]+dif;
                cout<<ans<<endl;
                cout<<t1<<' '<<md<<' '<<t2<<endl;
                
            }
            else{
                ans=2;
                ll dif=a[1]-a[0];
                ll t1=a[0]-dif;
                ll t2=a[1]+dif;
                cout<<ans<<endl;
                cout<<t1<<' '<<t2<<endl;
            }

            continue;
        }

        vvt t;
        for(ll i=1; i<n; i++){
            // cout<<a[i]<<' ';
            t.pb({a[i]-a[i-1],a[i-1],a[i]});
        }
        sort(all(t));
        // for(auto i:t){
        //     cout<<get<0>(i)<<' '<<get<1>(i)<<' '<<get<2>(i)<<endl;
        // }
        ll mini=get<0>(t[0]);
        if(mini==0){
            cout<<0<<endl;
            continue;
        }

        ll ans=0;
        vi d;
        bool f=true;
        ll cp=0;
        ll j=-1;
        for(ll i=0; i<(ll)t.size(); i++){
            if(get<0>(t[i])==mini){
                cp++;
                continue;
            }
            else{
                j=i;
            }
            // ll st=get<1>(t[i]);
            // ll en=get<2>(t[i]);
            // while(st<en){
            //     st+=mini;
            //     if(st!=en){
            //         ans++;
            //         d.pb(st);
            //     }
            // }
            // if(st!=en){
            //     f=false;
            //     break;
            // }
        }

        if(!f){
            // cout<<"ho ";
            cout<<0<<endl;
            continue;
        }
        if(cp<n-2){
            cout<<0<<endl;
            continue;
        }
        if(cp==n-1){
            cout<<2<<endl;
            cout<<a[0]-mini<<' '<<a[n-1]+mini<<endl;
            continue;
        }
        ll k=get<1>(t[j])+mini;
        if(get<2>(t[j])-mini == k){
            cout<<1<<endl;
            cout<<k<<endl;
        }
        else{
            cout<<0<<endl;
        }
        // cout<<(ll)d.size()<<endl;
        // for(auto i:d){
        //     cout<<i<<' ';
        // }
        // cout<<endl;
    }
    return 0;
}