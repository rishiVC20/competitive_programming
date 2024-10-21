// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long 
// // #define pb push_back 
// // #define onebit(x) __builtin_popcountll(x)
// // #define vi vector<ll>
// // #define YES cout<<'Y'<<'E'<<'S'<<endl
// // #define NO cout<<'N'<<'O'<<endl  

// // const ll mod = 1e9+7;

// // class Disjoint{
// //     vector<ll>size,rank,parent;
// // public:
// //     Disjoint(ll n){
// //         size.resize(n+1,1);
// //         parent.resize(n+1);
// //         rank.resize(n+1,0);
// //         for(ll i=0; i<=n; i++)
// //             parent[i]=i;
// //     }
// //     ll findParent(ll node){
// //         if(node==parent[node])
// //             return node;
// //         return parent[node]=(findParent(parent[node]));
// //     }
// //     void unionByRank(ll u, ll v){
// //         ll ulp_u=findParent(u);
// //         ll ulp_v=findParent(v);
// //         if(ulp_u == ulp_v) return;
// //         if(rank[ulp_u]<rank[ulp_v]){
// //             parent[ulp_u]=ulp_v;
// //         }
// //         else if(rank[ulp_u]>rank[ulp_v]){
// //             parent[ulp_v]=ulp_u;
// //         }
// //         else{
// //             parent[ulp_v]=ulp_u;
// //             rank[ulp_u]++;
// //         }
// //     }
// //     void unionBySize(ll u, ll v){
// //         ll ulp_u=findParent(u);
// //         ll ulp_v=findParent(v);
// //         if(ulp_u == ulp_v) return;
// //         if(size[ulp_u]<size[ulp_v]){
// //             parent[ulp_u]=ulp_v;
// //             size[ulp_v]+=size[ulp_u];
// //         }
// //         else{
// //             parent[ulp_v]=ulp_u;
// //             size[ulp_u]+=size[ulp_v];
// //         }
// //     }
// // };
// // ll mul (ll a, ll b, ll m=mod)
// // {
// //     a = a % m;
// //     b = b % m;
// //     return (((a * b) % m) + m) % m;
// // }
// // ll LCM(ll a, ll b)
// // {
    
// //     a = (a*b)/(__gcd(a,b));
// //     return a;
// // }
// // bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
// // {
// //     return a.second < b.second;
// // }
// // ll power(ll base, ll exponent)
// // {
// //     if (exponent < 0)
// //     {
// //         return 0;
// //     }
// //     ll ans = 1;
// //     while (exponent)
// //     {
// //         if (exponent%2==0)
// //         {
// //             base = (base*base) % mod;
// //             exponent = exponent/2;
// //         }
// //         else
// //         {
// //             ans = (ans*base) % mod;
// //             exponent--;
// //         }
// //     }
// //     return ans;
// // }


// // int main() {
// //     ll tt;
// //     cin>>tt;
// //     while (tt--)
// //     {
// //         ll n,k;
// //         cin>>n>>k;
// //         vi a;
// //         a.pb(0);
// //         for(ll i=0; i<n; i++){
// //             ll x;cin>>x;
// //             a.pb(x);
// //         }       
// //         sort(a.begin(),a.end());
// //         // for(auto i:a)
// //         //     cout<<i<<' ';
// //         ll cn=0;
// //         ll j=1;
// //         ll req=k;
// //         ll sum=0;
// //         while(j<=n){
// //             ll m=(a[j]-a[j-1])*(n+1-j);
// //             if(m < req){
// //                 cn += m;
// //                 req -= m; //0
                
// //             }
// //             else{
// //                 cn += req;
// //                 break;
// //             }
// //             if(req==0)
// //                 break;
// //             // sum += a[j];    
// //             j++;    
// //             // cout<<req<<' ';
// //         }
// //         cn += (j-1);

// //         cout<<cn<<endl;
// //     }
// //     return 0;
// // }

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
//     ll tt;
//     cin>>tt;
//     while (tt--)
//     {
//         ll n,k;
//         cin>>n>>k;
//         vi a;
//         a.pb(0);
//         for(ll i=0; i<n; i++){
//             ll x;cin>>x;
//             a.pb(x);
//         }       
//         sort(a.begin(),a.end());

//         ll cn=0;
//         ll j=1;
//         ll req=k;
//         while(j<=n){
//             if(j>1)
//                 cn++;
//             ll m=(a[j]-a[j-1])*(n+1-j);
//             if(m < req){
//                 cn += m;
//                 req -= m;
//                 j++;
//             }
//             else{
//                 cn += req;
//                 break;
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
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;
        vi a;
        a.pb(0);
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }       
        sort(a.begin(),a.end());

        ll cn=0;
        ll j=1;
        ll req=k;
        while(j<=n){
            if(j>1)
                cn++;
            ll m=(a[j]-a[j-1])*(n+1-j);
            if(m < req){
                cn += m;
                req -= m;
                j++;
            }
            else{
                cn += req;
                break;
            }
            if(req==0)
                break;
        }

        cout<<cn<<endl;
    }
    return 0;
}