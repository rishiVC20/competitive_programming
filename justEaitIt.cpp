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
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         vi a;
//         bool f=true;
//         for(ll i=0; i<n; i++){
//             ll x;cin>>x;
//             a.pb(x);
//             if(x<=0)
//                 f=false;
//         }       
//         if(f){
//             YES;
//             continue;
//         }
//         ll sum1=accumulate(a.begin(),a.end(),0);
//         ll maxi=0;
//         ll sum=0;
//         int v=0;
//         f=true;
//         for(ll i=0; i<n; i++){
//             maxi += a[i];
//             // cout<<maxi<<' ';
//             if(maxi<=0){
//                 f=false;
//                 break;
//             }
//         }
//         if(!f){
//             NO;
//             continue;
//         }
//         for(ll i=n-1; i>=0; i--){
//             sum += a[i];
//             if(sum<=0){
//                 f=false;
//                 break;
//             }
//         }
//         if(!f){
//             NO;
//         }
//         else{
//             YES;
//         }
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
        ll n;
        cin>>n;
        vi a;
        bool f=true;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(x<0)
                f=false;
        }
        if(f){
            YES;
            continue;
        }
        ll maxi=0;
        ll curr=0;
        ll s=accumulate(a.begin(),a.end(),0LL);
        bool k=true;
        for(ll i=0; i<n-1; i++){
            curr+=a[i];
            maxi=max(maxi,curr);
            if(curr<0)
                curr=0;
            if(maxi>=s){
                k=false;
                break;
            }    
        }
        if(!k){
            NO;
            continue;
        }
        maxi=0,curr=0;
        for(ll i=n-2; i>=0; i--){
            curr+=a[i];
            maxi=max(maxi,curr);
            if(curr<0)
                curr=0;
            if(maxi>=s){
                k=false;
                break;
            }    
        }
        if(!k)
            NO;
        else
            YES;    

    }
    return 0;
}