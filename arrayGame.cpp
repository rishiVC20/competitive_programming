// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long int
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>
// #define YES cout<<'Y'<<'E'<<'S'<<endl
// #define NO cout<<'N'<<'O'<<endl  




// signed main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,k;
//         cin>>n>>k;
//         vi a;
//         for(ll i=0; i<n; i++){
//             ll x;cin>>x;
//             a.pb(x);           
//         }
//         if(k>=3){
//             cout<<0<<endl;
//             continue;
//         }
//         sort(a.begin(),a.end());
//         ll ans=a[0];
//         for(ll i=0; i<n-1; i++){
//             ans=min(ans,min(a[i],a[i+1]-a[i]));
//         }
//         if(k==1){
            
//             cout<<ans<<endl;
//             continue;
//         }

//         ll cn=(a[0]);
//         for(ll i=0; i<n; i++){
//             for(ll j=0; j<i; j++){
//                 ll v=a[i]-a[j];
//                 // cout<<v<<' ';
//                 ll up=lower_bound(a.begin(),a.end(),v)-a.begin();
//                 // if(up==0){
//                 //     // cout<<'k';
//                 //     cn=min(cn,p);
//                 //     continue;
//                 // }
//                 // cout<<up<<' ';
//                 if(up<n){
//                     cn=min(cn,a[up]-v);
//                 }
//                 if(up>0){
//                     cn=min(cn,v-a[up-1]);
//                 }
//                 // cout<<cn<<' ';
//                 // cn=min(cn,min(a[i],a[j]));
//                 cn=min(cn,v);
                    
//             }
//         }

//         cout<<cn<<endl;

//     }
//     return 0;
// }



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
        
    }
    return 0;
}