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

bool check(ll p, set<ll> &st, vi &v2, vi &v1, ll md, ll sp1, ll sp2){
    ll tp=md+sp1-sp2;
    for(ll i=0; i<(ll)v1.size(); i++){
        ll m=tp-v1[i];
        ll g=v1[i]+sp2-(sp1-v1[i]);
        cout<<g<<' ';
        if(m==g){
            p=v1[i];
            v1[i]=md;
            return true;
        }
    }

    return false;
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
        set<ll>st;
        for(ll i=0; i<n*2; i++){
            ll x;cin>>x;
            a.pb(x);
            st.insert(x);
        }

        sort(rall(a));
        ll sp1=0,sp2=0;
        vi v1,v2;
        vi k1,k2;
        ll d1=0,d2=0;
        for(ll i=0; i<n; i++){
            sp1+=a[i];
            v1.pb(a[i]);
        }
        for(ll i=n; i<n*2; i++){
            sp2+=a[i];
            v2.pb(a[i]);
        }
        for(ll i=0; i<n*2; i+=2){
            k1.pb(a[i]);
            d1+=a[i];
        }
        for(ll i=1; i<n*2; i+=2){
            k2.pb(a[i]);
            d2+=a[i];
        }

        ll dif=sp1-sp2;
        if(st.find(dif)!=st.end()){
            ll ans=-1;
            for(ll i=0; i<n; i++){
                ll k=v1[i]+sp2-(sp1-v1[i]);
                if(k>0 && st.find(k)==st.end()){
                    ans=v1[i];
                    v1[i]=k;
                    break;
                }
            }
            if(ans==-1){
                // cout<<"p1";
                for(ll i=0; i<n; i++){
                    ll k=k1[i]+d2-(d1-k1[i]);
                    if(k>0 && st.find(k)==st.end()){
                        ans=k1[i];
                        k1[i]=k;
                        break;
                    }
                }
                cout<<ans<<' ';
                for(ll i=0; i<n; i++){
                    cout<<k1[i]<<' '<<k2[i]<<' ';
                }   
                cout<<endl;
                continue;
            }
            cout<<ans<<' ';
            for(ll i=0; i<n; i++){
                cout<<v1[i]<<' '<<v2[i]<<' ';
            }   
            cout<<endl;
            continue;

        }
        cout<<dif<<' ';
        for(ll i=0; i<n; i++){
            cout<<v1[i]<<' '<<v2[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}