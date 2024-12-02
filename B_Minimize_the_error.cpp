// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>
// #define YES cout<<'Y'<<'E'<<'S'<<endl
// #define NO cout<<'N'<<'O'<<endl  

// const ll mod = 1e9+7;

// class Disjoint{
//     vector<ll>size,rank,parent;
// public:
//     Disjoint(ll n){
//         size.resize(n+1,1);
//         parent.resize(n+1);
//         rank.resize(n+1,0);
//         for(ll i=0; i<=n; i++)
//             parent[i]=i;
//     }
//     ll findParent(ll node){
//         if(node==parent[node])
//             return node;
//         return parent[node]=(findParent(parent[node]));
//     }
//     void unionByRank(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u]<rank[ulp_v]){
//             parent[ulp_u]=ulp_v;
//         }
//         else if(rank[ulp_u]>rank[ulp_v]){
//             parent[ulp_v]=ulp_u;
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             rank[ulp_u]++;
//         }
//     }
//     void unionBySize(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(size[ulp_u]<size[ulp_v]){
//             parent[ulp_u]=ulp_v;
//             size[ulp_v]+=size[ulp_u];
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             size[ulp_u]+=size[ulp_v];
//         }
//     }
// };
// ll mul (ll a, ll b, ll m=mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll LCM(ll a, ll b)
// {
    
//     a = (a*b)/(__gcd(a,b));
//     return a;
// }
// bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
// {
//     return a.second < b.second;
// }
// ll power(ll base, ll exponent)
// {
//     if (exponent < 0)
//     {
//         return 0;
//     }
//     ll ans = 1;
//     while (exponent)
//     {
//         if (exponent%2==0)
//         {
//             base = (base*base) % mod;
//             exponent = exponent/2;
//         }
//         else
//         {
//             ans = (ans*base) % mod;
//             exponent--;
//         }
//     }
//     return ans;
// }


// int main() {
//     ll tt=1;
//     // cin>>tt;
//     while (tt--)
//     {
//         ll n,k1,k2;
//         cin>>n>>k1>>k2;

//         vector<tuple<ll,ll,ll>>v;
//         vi a;
//         for(ll i=0; i<n; i++){
//             ll x;cin>>x;
//             a.pb(x);
//         }
//         ll p=0;
//         for(ll i=0; i<n; i++){
//             ll y;cin>>y;
//             v.pb(make_tuple(a[i],y,abs(a[i]-y)));
//             p += (get<2>(v[i]) != 0);
//         }
//         // cout<<p<<"h ";
//         sort(v.begin(),v.end(),[&](const tuple<ll,ll,ll>&a, const tuple<ll,ll,ll>&b){
//             return get<2>(a) > get<2>(b);
//         });
//         // cout<<p<<" ";
//         ll j=0;
//         while(k1>0 && j<n){
//             ll x=get<0>(v[j]),y=get<1>(v[j]),z=get<2>(v[j]);
//             // if(z==0 && j==n-1){
//             //     get<0>(v[j])+=k1;
//             //     k1=0;
//             //     break;
//             // }
//             if(z==0 || p==0){
//                 ll m=n-j;
//                 ll t=k1%m;
//                 if(k1%2!=0){
//                     get<0>(v[j])++;
//                 }
//                 break;
//             }
//             ll k=(k1/p)+((k1%p!=0)?1:0);
//             p--;
//             // cout<<k<<' ';
//             if(z<k){
//                 if(x>y){
//                     get<0>(v[j])-=z;
//                 }
//                 else{
//                     get<0>(v[j])+=z;
//                 }
//                 k1 -= z;
//             }
//             else{
//                 if(x>y){
//                     get<0>(v[j]) -= k;
//                 }
//                 else{
//                     get<0>(v[j])+=k;
//                 }
//                 k1-=k;
//             }
//             j++;
//         }
//         p=0;
//         for(ll i=0; i<n; i++){
//             get<2>(v[i])=abs(get<0>(v[i])-get<1>(v[i]));
//             p += (get<2>(v[i])!=0);
//         }

//         sort(v.begin(),v.end(),[&](const tuple<ll,ll,ll>&a, const tuple<ll,ll,ll>&b){
//             return get<2>(a) > get<2>(b);
//         });

//         j=0;
//         // cout<<p<<"k ";
//         while(k2>0 && j<n){
//             ll x=get<0>(v[j]),y=get<1>(v[j]),z=get<2>(v[j]);
//             // if(z==0 && j==n-1){
//             //     get<1>(v[j])+=k2;
//             //     k2=0;
//             //     break;
//             // }
//             // cout<<x<<' '<<y<<' '<<z<<endl;
//             if(z==0 || p==0){
//                 ll m=n-j;
//                 ll t=k2%m;
//                 if(k2%2!=0){
//                     get<1>(v[j])++;
//                 }
//                 break;
//             }
//             ll k=(k2/p)+((k2%p!=0)?1:0);
//             p--;
//             if(z<k){
//                 if(x>y){
//                     get<1>(v[j])+=z;
//                 }
//                 else{
//                     get<1>(v[j])-=z;
//                 }
//                 k2 -= z;
//             }
//             else{
//                 if(x>y){
//                     get<1>(v[j]) += k;
//                 }
//                 else{
//                     get<1>(v[j])-=k;
//                 }
//                 k2-=k;
//             }
            
//             j++;
//         }

//         ll cn=0;
//         for(ll i=0; i<n; i++){
//             ll x=get<0>(v[i]),y=get<1>(v[i]);
//             // cout<<x<<' '<<y<<endl;
//             cn += (powl(x-y,2));
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
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,k1,k2;
        cin>>n>>k1>>k2;

        vi a,b;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }   
        priority_queue<ll>pq;    
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            b.pb(x);
            pq.push(abs(a[i]-b[i]));
        }

        ll k=k1+k2;

        while(k>0){
            ll p=pq.top();
            pq.pop();
            p--;
            pq.push(abs(p));
            k--;
        }

        ll cn=0;
        while(!pq.empty()){
            ll k=pq.top();
            pq.pop();
            cn += powl(k,2);
        }

        cout<<cn<<endl;
    }
    return 0;
}