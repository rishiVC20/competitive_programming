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
    
public:
    vector<ll>size,rank,parent;
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

// void check(map<ll,set<ll>> &mp, ll node, vector<bool> &vis){

//     vis[node]=true;

//     for(auto i:mp[node]){
//         if(vis[i]!=true){
//             check(mp,i,vis);
//         }
//     }
    // cout<<"j";
    // ll x=node;
    // ll y=-1,z=-1;
    // for(auto i:mp[node]){
    //     if(y==-1){
    //         y=i;
    //         continue;
    //     }
    //     if(z==-1){
    //         z=i;
    //     }
    // }

    // // cout<<y<<' '<<z<<' ';

    // vi c;
    // c.pb(x);
    // for(auto i:mp[x]){
    //     c.pb(i);
    // }

    // vi d;
    // d.pb(y);
    // for(auto i:mp[y]){
    //     d.pb(i);
    // }

    // vi t;
    // t.pb(z);
    // for(auto i:mp[z]){
    //     t.pb(i);
    // }

    // sort(c.begin(),c.end());
    // sort(d.begin(),d.end());
    // sort(t.begin(),t.end());

    // if(c==d && d==t){
    //     return true;
    // }

    // return false;
// }

bool solve(map<ll,set<ll>> &mp, ll node, vector<bool> &vis, set<ll> &st, ll &cn){
    vis[node]=true;
    st.insert(node);
    cn++;

    if(mp[node].size() < 2){
        return false;
    }

    for(auto i:mp[node]){
        if(vis[i] ==false){
            return solve(mp,i,vis,st,cn);
        }
    }

    return true;

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
            x--;
            a.pb(x);
        }       

        set<ll>st;

        // ll cn=2;
        Disjoint d(n);
        map<ll,set<ll>>mp;
        for(ll i=0; i<n; i++){
            // if(st.find(a[i])!=st.end()){
            //     cn++;
            // }
            d.unionByRank(i,a[i]);
            st.insert(i);
            mp[i].insert(a[i]);
            mp[a[i]].insert(i);
            // st.insert(a[i]);
        }

        vi ans;
        set<ll>h;
        // for(auto i:mp){
        //     // set<ll>s=i.second;
        //     if(i.second.size()<2){
        //         continue;
        //     }
        //     // vi p;
        //     // for(auto i:s){
        //     //     p.pb(i);
        //     // }
        //     vector<bool>vis(n,false);
        //     if(h.find(i.first)==h.end()){
        //         h.insert(i.first);
        //         ll cn=1;
        //         check(mp,i.first,vis);
        //         for(ll j=0; j<n; j++){
        //             if(vis[j]==true){
        //                 if(h.find(j)==h.end()){
        //                     h.insert(j);
        //                     cn++;
        //                 }
        //                 // cn++;
        //             }
        //         }
        //         ans.pb(cn);
        //     }
        //     // if(check(mp,i.first,vis) && h.find(i.first)==h.end()){
        //     //     // cout<<"hi";
        //     //     ans.pb(3);
        //     //     h.insert(i.first);
        //     //     for(auto j:i.second){
        //     //         h.insert(j);
        //     //     }
        //     // }
        // }
        // set<ll>
        for(ll i=0; i<n; i++){
            vector<bool>vis(n,false);

            if(mp[i].size() < 2 || h.find(i)!=h.end()){
                continue;
            }

            // solve(mp,i,vis);

            bool f=false;
            ll cn=0;

            if(solve(mp,i,vis,h,cn)){
                ans.pb(cn);
            }
            // for(ll j=0; j<n; j++){
            //     if(vis[j]==true){
            //         if(mp[j].size()<2){
            //             f=true;
            //             break;
            //         }
            //         if(h.find(j)==h.end()){
            //             h.insert(j);
            //             cn++;
            //         }
            //     }
            // }
            // for(auto j:mp[i]){
            //     if(vis[j]==true){
            //         if(vis[j]==true){
            //             if(mp[j].size()<2){
            //                 f=true;
            //                 break;
            //             }
            //             if(h.find(j)==h.end()){
            //                 h.insert(j);
            //                 cn++;
            //             }
            //         }
            //     }
            // }
            // if(!f){
            //     ans.pb(cn);
            // }
        }



        ll cn=0;

        ll kp=0;
        for(auto i:ans){
            // cout<<i<<' ';
            kp += i;
        }

        // cout<<"j "<<kp<<' ';
        if(kp>0){
            // cn=ans.size();
            if(kp==n)
                cn = ans.size();
            else{
                cn=1+ans.size();
            }    
        }
        else{
            cn=1LL;
        }

        cout<<cn<<" ";

        
        set<ll>k;

        for(ll i=0; i<n; i++){
            ll m=d.findParent(a[i]);
            k.insert(m);
        }

        cout<<k.size()<<endl;
    }
    return 0;
}