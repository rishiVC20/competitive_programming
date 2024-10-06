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
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,x;
//         cin>>n>>x;
//         vi a;
//         map<ll,ll>mp;
//         for(ll i=0; i<n; i++){
//             ll y;cin>>y;
//             a.pb(y);
//             mp[y]++;
//         }
//         sort(a.begin(),a.end());

//         for(ll i=0; i<n; i++){
//             if(mp[a[i]]>1){
//                 ll u=mp[a[i]]-1;
//                 mp[a[i]]--;
//                 a[i] += u*x;
//                 cout<<a[i]<<' ';
//                 mp[a[i]]++;
//             }
//             else{
//                 cout<<a[i]<<' ';
//             }
//         }       
//         sort(a.begin(),a.end());
//         // for(auto i:a)
//         //     cout<<i<<' ';
//         ll j=-1;
//         for(ll i=0; i<n; i++){
//             if(a[i]!=i){
//                 j=i;
//                 break;
//             }
//         }
//         if(j==-1)
//             j=n;
//         cout<<j<<endl;    
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
        ll n,x;
        cin>>n>>x;
        vi a;
        map<ll,ll>mp;
        for(ll i=0; i<n; i++){
            ll y;cin>>y;
            a.pb(y);
            mp[y]++;
        }       
        vi b;
        map<ll,ll>c;
        sort(a.begin(),a.end());
        ll cn=0;
        // for(ll i=0; i<n; i++){
        //     if(mp[i] > 0){
        //         // cout<<i<<' ';
        //         mp[i]--;
        //         ll k=mp[i];
        //         if(k>0)
        //             c[i%x]=k;
        //         cn++;
        //     }
        //     else if(c[i%x] > 0){
        //         // cout<<i<<' ';
        //         c[i%x]--;
        //         cn++;
        //     }
        //     else{
        //         break;
        //     }
        // }
        while(true){
            if(mp[cn] > 0){
                mp[cn]--;
                ll k=mp[cn];
                for(ll j=0; j<k; j++)
                    c[cn%x]++;
                cn++;
            }
            else if(c[cn%x]>0){
                c[cn%x]--;
                cn++;
            }
            else{
                break;
            }

        }
        cout<<cn<<endl;
        // sort(b.begin(),b.end());
        // for(auto i:b)
        //     cout<<i<<' ';
        // ll j=-1;
        // for(ll i=0; i<b.size(); i++){
        //     if(b[i]!=i){
        //         j=i;
        //         break;
        //     }
        // }
        // if(j==-1)
        //     j=n;
        // cout<<j<<endl;    
    }
    return 0;
}