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
        ll n;
        cin>>n;;

        vi a,b,c;
        ll mini=LLONG_MAX,maxi=LLONG_MIN;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(x<0){
                b.pb(x);
            }
            else{
                c.pb(x);
            }
            mini=min(mini,a[i]);
            maxi=max(maxi,a[i]);
        }
        if(n==1){
            NO;
            continue;
        }
        sort(c.rbegin(),c.rend());
        sort(b.begin(),b.end());

        ll sc=accumulate(c.begin(),c.end(),0LL);
        vi d(n,-1);

        ll cp=0;
        ll ans=maxi-mini;
        // cout<<ans<<' ';
        if(sc < ans){
            YES;
            for(auto i:a)
                cout<<i<<' ';
            cout<<endl;
            continue;    
        }

        ll i=0,j=0;
        ll m=0;
        // for(ll k=0; k<n; ){
        //     if(i<c.size()){
        //         d[k++]=c[i];
        //         i++;
        //     }
        //     if(j<b.size()){
        //         d[k++]=b[j];
        //         j++;
        //     }
        // }
        while(i<c.size() && j<b.size()){
            cp += c[i];
            if(cp >= ans){
                d[m++]=b[j];
                cp -= c[i];
                cp+=b[j];
                j++;
            }
            else{
                d[m++]=c[i];
                i++;
            }
        }

        while(j<b.size()){
            d[m++]=b[j++];
        }
        bool hh=true;
        ll cn=0;
        while(i<c.size()){
            cn +=c[i];
            if(cn >= ans){
                hh=false;
                break;
            }
            d[m++]=c[i++];
        }
        if(!hh){
            NO;
            continue;
        }
        

        bool f=true;
        for(auto i:d){
            // cout<<i<<' ';
            if(i==-1){
                f=false;
                break;
            }
        }

        if(!f){
            NO;
        }
        else{
            YES;
            for(auto i:d)
                cout<<i<<' ';
            cout<<endl;    
        }


    }
    return 0;
}