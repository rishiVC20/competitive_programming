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
ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
ll power(ll base, ll exponent)
{
    if (exponent < 0)
    {
        return 0;
    }
    ll ans = 1;
    while (exponent)
    {
        if (exponent%2==0)
        {
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else
        {
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}


int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);           
        }
        // vector<tuple<ll,ll,ll>>v;
        // v.pb({0,0,0});
        // ll x=0,y=0,z=0;
        // for(ll i=0; i<n; i++){
        //     x += (a[i]==1);
        //     y += (a[i]==2);
        //     z += (a[i]==3);
        //     v.pb({x,y,z});
        // }
        // for(ll i=0; i<m; i++){
        //     ll l,r;
        //     cin>>l>>r;
        //     ll b=r-l+1;
        //     if(b%2){
        //         NO;
        //         continue;
        //     }
        //     ll s1=0,s2=0,s3=0;
        //     // if(l>0){
        //         s1 += get<0>(v[r])-get<0>(v[l-1]);
        //         s2 += get<1>(v[r])-get<1>(v[l-1]);
        //         s3 += get<2>(v[r])-get<2>(v[l-1]);
        //     // }
        //     // else{
        //     //     s1 += get<0>(v[r]);
        //     //     s2 += get<1>(v[r]);
        //     //     s3 += get<2>(v[r]);
        //     // }
        //     // cout<<s1<<' '<<s2<<' '<<s3<<' ';
        //     ll c=b/2;
        //     if(s1>c || s2>c || s3>c){
        //         NO;
        //     }
        //     else{
        //         YES;
        //     }
        // }
        vector<tuple<ll, ll, ll>> v(n + 1);
        v[0] = {0, 0, 0};
        ll x = 0, y = 0, z = 0;
        for (ll i = 0; i < n; i++) {
            x += (a[i] == 1);
            y += (a[i] == 2);
            z += (a[i] == 3);
            v[i + 1] = {x, y, z};  
        }
        
        for (ll i = 0; i < m; i++) {
            ll l, r;
            cin >> l >> r;
            ll b = r - l + 1;
            if (b % 2) {
                NO;
                continue;
            }
            ll s1 = get<0>(v[r]) - get<0>(v[l - 1]);
            ll s2 = get<1>(v[r]) - get<1>(v[l - 1]);
            ll s3 = get<2>(v[r]) - get<2>(v[l - 1]);

            ll c = b / 2; 
            vi d;
            d.pb(s1);
            d.pb(s2);
            d.pb(s3);
            sort(d.begin(),d.end());
            if(d[2]==d[0]+d[1])
                YES;
            else
                NO;    
        }
    }
    return 0;
}

/*
No
No
No
Yes
No
No
No
Yes
No
Yes
No
No
No
No
Yes
No
Yes
No
No
No
No
*/