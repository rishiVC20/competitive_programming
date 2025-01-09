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
    const ll ma=2e3+1;
    vector<vi>v(ma+1,vi(ma+1,0));
    ll cn=1;
    ll row=1;
    while(cn <= ma+1 && row<=ma+1){
        // cout<<"hi ";
        ll col=1;
        ll m=row;
        while(m>=1 && col<=row){
            v[m][col]=cn;
            cn++;
            m--,col++;
        }
        row++;
    }
    // cout<<"hi";
    vector<vi>ans(ma+1,vi(ma+1,0));
    map<ll,ll>mp;
    // for(ll i=1; i<=5; i++){
    //     for(ll j=1; j<=5; j++){
    //         cout<<v[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(ll i=1; i<=ma; i++){
        for(ll j=1; j<=ma; j++){
            // ll bb=v[i][j]*v[i][j]+ans[i-1][j]+ans[i][j-1];
            ll bb = v[i][j] * v[i][j];
            // if (i > 1) bb += ans[i - 1][j];
            if (j > 1) bb += ans[i][j - 1];
            ans[i][j]=bb;
        }
    }
    for(ll i=1; i<=ma; i++){
        for(ll j=1; j<=ma; j++){
            
            ans[i][j] += ans[i-1][j];

            mp[v[i][j]]=ans[i][j];
        }
    }

    // for(ll i=1; i<=3; i++){
    //     for(ll j=1; j<=3; j++){
    //         cout<<ans[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }


    while (tt--)
    {
        ll n;
        cin>>n;

        // cout<<mp[n]<<endl;

         if (mp.find(n) != mp.end())
            cout << mp[n] << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}