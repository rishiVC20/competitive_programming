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
    if(a.first==b.first)
        return a.second<b.second;
    return a.first > b.first;
}
bool cpp(const pair<int, int> &a, const pair<int, int> &b){
    // if(a.first==b.first)
    //     return a.second<b.second;
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
        ll n,k;
        cin>>n>>k;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        vvp v1,v2;
        for(ll i=0; i<n; i++){
            v1.pb({a[i],i});
        }
        for(ll i=1; i<n; i+=2){
            v2.pb({a[i],i});
        }
        if(k>=n-1){
            ll p=accumulate(a.begin(),a.end(),0LL);
            cout<<p<<endl;
            continue;
        }
        sort(v1.begin(),v1.end(),customComparator);
        sort(v2.begin(),v2.end(),customComparator);
        if(k>((n+1)/2)){
            vvp s;
            for(ll i=0; i<n; i++){
                s.pb({a[i],i});
            }
            sort(s.begin(),s.end(),customComparator);
            vvp dd;
            ll st=0;
            for(ll i=0; i<min(k,(ll)s.size()); i++){
                dd.pb({s[i].first,s[i].second});
                st+=s[i].first;
            }
            sort(dd.begin(),dd.end(),cpp);
            ll mq=0;
            for(ll i=0; i<(ll)dd.size(); i++){
                if(i==0 ){
                    for(ll j=0; j<dd[i].second; j++){
                        mq=max(mq,a[j]);
                    }
                }
                if(i==(ll)dd.size()-1){
                    for(ll j=dd[i].second+1; j<n; j++){
                        mq=max(mq,a[j]);
                    }
                }
                if(i>0){
                    for(ll j=dd[i-1].second+1; j<dd[i].second; j++){
                        mq=max(mq,a[j]);
                    }
                }
            }
            st+=mq;
            cout<<st<<endl;
            continue;

        }
        vvp d1,d2;
        ll sp1=0,sp2=0;
        for(ll i=0; i<min(k,(ll)v1.size()); i++){
            d1.pb({v1[i].first,v1[i].second});
            sp1+=v1[i].first;
        }
        for(ll i=0; i<min(k,(ll)v2.size()); i++){
            d2.pb({v2[i].first,v2[i].second});
            sp2+=v2[i].first;
        }

        sort(d1.begin(),d1.end(),cpp);
        sort(d2.begin(),d2.end(),cpp);
        // for(auto i:d1){
        //     cout<<i.first<<' '<<i.second<<endl;
        // }
        // for(auto i:d2){
        //     cout<<i.first<<' '<<i.second<<endl;
        // }
        ll mx1=0,mx2=0;
        for(ll i=0; i<(ll)d1.size(); i++){
            if(i==0 ){
                for(ll j=0; j<d1[i].second; j++){
                    mx1=max(mx1,a[j]);
                }
            }
            if(i==(ll)d1.size()-1){
                for(ll j=d1[i].second+1; j<n; j++){
                    mx1=max(mx1,a[j]);
                }
            }
            if(i>0){
                for(ll j=d1[i-1].second+1; j<d1[i].second; j++){
                    mx1=max(mx1,a[j]);
                }
            }
        }
        sp1+=mx1;
        for(ll i=0; i<(ll)d2.size(); i++){
            if(i==0 && d2[i].second!=0){
                for(ll j=0; j<d2[i].second; j++){
                    mx2=max(mx2,a[j]);
                }
            }
            if(i==(ll)d2.size()-1){
                for(ll j=d2[i].second+1; j<n; j++){
                    mx2=max(mx2,a[j]);
                }
            }
            if(i>0){
                for(ll j=d2[i-1].second+1; j<d2[i].second; j++){
                    mx2=max(mx2,a[j]);
                }
            }
        }
        sp2+=mx2;

        // cout<<sp1<<' '<<sp2<<' ';
        cout<<max(sp1,sp2)<<endl;
    }
    return 0;
}