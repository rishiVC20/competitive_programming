// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>

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

        vvp v1,v2;
        map<ll,ll>d1,d2;
        for(ll i=0; i<n; i++){
            ll c,s;
            cin>>c>>s;

            if(c==0){
                v1.pb({i,s});
                d1[i]=c;
            }
            else{
                v2.pb({i,s});
                d2[i]=c;
            }
        }       

        vvp x1,x2;
        if(v1.size() > v2.size()){
            x1=v1,x2=v2;
        }
        else{
            x1=v2,x2=v1;
        }
        Disjoint d(n);

        vvt ans;
        for(auto i:x1){
            ll y=i.first,z=i.second;

            while(z > 0){
                for(auto j:x2){
                    ll u=j.first,v=j.second;
                    if(v>0 && z>0){
                        ans.pb({y,u,min(z,v)});
                        d.unionByRank(y,u);
                        // i.second -= min(z,v);
                        j.second -= min(z,v);
                        z -= min(z,v);
                    }
                }
            }
        }

        set<ll>st;

        for(ll i=0; i<n; i++){
            st.insert(d.findParent(i));
        }

        if(st.size() > 1){
            // cout<<"hoi";

            map<ll,vi>mp;
            for(ll i=0; i<n; i++){
                ll b=d.findParent(i);
                mp[b].pb(b);
            }
            vi b;
            for(auto i:mp){
                // cout<<"j ";
                ll p=i.second[0];
                b.pb(p);
            }
            vi qq,ww;
            for(ll i=0; i<b.size(); i++){
                // cout<<b[i]<<' ';
                if(d1.find(b[i]) != d1.end()){
                    // cout<<"m ";
                    qq.pb(b[i]);
                }
                if(d2.find(b[i]) != d2.end()){
                    // cout<<"n ";

                    ww.pb(b[i]);
                }
            }
            vi hh,aa;
            if(qq.size() > ww.size()){
                hh=qq,aa=ww;
            }
            else{
                hh=ww,aa=qq;
            }

            // for(auto i:b){
            //     cout<<i<<' ';
            // }
            // cout<<endl;
            // for(auto i:hh){
            //     cout<<i<<' ';
            // }
            // cout<<endl;
            // for(auto i:aa){
            //     cout<<i<<' ';
            // }
            // cout<<endl;
            // cout<<hh.size()<<' '<<aa.size()<<" j"<<endl;
            for(ll i=0; i<hh.size(); i++){
                if(i==aa.size())
                    break;
                ans.pb({hh[i],aa[i],0});
                if(i+1==hh.size())
                    break;
                ans.pb({aa[i],hh[i+1],0});
            }
        }


        

        

        for(auto i:ans){
            cout<<get<0>(i)+1<<' '<<get<1>(i)+1<<' '<<get<2>(i)<<endl;
        }
    }
    return 0;
}