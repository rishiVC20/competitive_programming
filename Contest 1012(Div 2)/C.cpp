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

        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>>pq;
        // map<ll,vi>mp;
        ll r=0;
        vvp s(n);
        ll x=0,y=0;
        for(ll i=0; i<n; i++){
            if(a[i]==0){
                priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>>tp;
                // cout<<i<<' '<<x<<' '<<y<<endl;
                // pq.push({2*3*r+2,3*r+1,3*r+1});
                // pq.push({3*x+1+3*y+1,3*x+1,3*y+1});
                pq.push({3*x+1+3*y+2,3*x+1,3*y+2});
                pq.push({3*x+2+3*y+1,3*x+2,3*y+1});
                pq.push({3*x+2+3*y+2,3*x+2,3*y+2});
                tp.push({3*x+1+3*y+1,3*x+1,3*y+1});
                tp.push({3*x+1+3*y+2,3*x+1,3*y+2});
                tp.push({3*x+2+3*y+1,3*x+2,3*y+1});
                tp.push({3*x+2+3*y+2,3*x+2,3*y+2});
                if(x==y){
                    y++;
                }
                else{
                    x++;
                }
                r++;
                // for(auto j:tp){
                    cout<<i<<' ';
                    cout<<get<0>(tp.top())<<' '<<get<1>(tp.top())<<' '<<get<2>(tp.top())<<endl;;
                // }
                tuple<ll,ll,ll> t=tp.top();
                s[i]={get<1>(t),get<2>(t)};
                // pq.pop();
                // tp.cl
                // pq.pop();
            }
            else{
                if(!pq.size()){
                    pq.push({3*x+1+3*y+1,3*x+1,3*y+1});
                    pq.push({3*x+1+3*y+2,3*x+1,3*y+2});
                    pq.push({3*x+2+3*y+1,3*x+2,3*y+1});
                    pq.push({3*x+2+3*y+2,3*x+2,3*y+2});
                    if(x==y){
                        y++;
                    }
                    else{
                        x++;
                    }
                    r++;
                }
                tuple<ll,ll,ll> t=pq.top();
                pq.pop();
                s[i]={get<1>(t),get<2>(t)};
        //         mp[t].pb(i);
        //         if((ll)mp[r].size()<4){
        //             pq.push(t);
        //         }

            }
        }

        // for(ll i=0; i<n; i++){
        //     cout<<s[i].first<<' '<<s[i].second<<endl;
        //     // for(auto j:i.second){
        //     //     cout<<j+1<<' ';
        //     // }
        //     // cout<<endl;
        // }
        cout<<endl;
    }
    return 0;
}