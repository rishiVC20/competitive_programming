// // // // Rishikesh Chaudhari
// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // #define ll long long 
// // // #define pb push_back 
// // // #define onebit(x) __builtin_popcountll(x)
// // // #define vi vector<ll>
// // // #define YES cout<<'Y'<<'E'<<'S'<<endl
// // // #define NO cout<<'N'<<'O'<<endl  

// // // const ll mod = 1e9+7;

// // // class Disjoint{
// // //     vector<ll>size,rank,parent;
// // // public:
// // //     Disjoint(ll n){
// // //         size.resize(n+1,1);
// // //         parent.resize(n+1);
// // //         rank.resize(n+1,0);
// // //         for(ll i=0; i<=n; i++)
// // //             parent[i]=i;
// // //     }
// // //     ll findParent(ll node){
// // //         if(node==parent[node])
// // //             return node;
// // //         return parent[node]=(findParent(parent[node]));
// // //     }
// // //     void unionByRank(ll u, ll v){
// // //         ll ulp_u=findParent(u);
// // //         ll ulp_v=findParent(v);
// // //         if(ulp_u == ulp_v) return;
// // //         if(rank[ulp_u]<rank[ulp_v]){
// // //             parent[ulp_u]=ulp_v;
// // //         }
// // //         else if(rank[ulp_u]>rank[ulp_v]){
// // //             parent[ulp_v]=ulp_u;
// // //         }
// // //         else{
// // //             parent[ulp_v]=ulp_u;
// // //             rank[ulp_u]++;
// // //         }
// // //     }
// // //     void unionBySize(ll u, ll v){
// // //         ll ulp_u=findParent(u);
// // //         ll ulp_v=findParent(v);
// // //         if(ulp_u == ulp_v) return;
// // //         if(size[ulp_u]<size[ulp_v]){
// // //             parent[ulp_u]=ulp_v;
// // //             size[ulp_v]+=size[ulp_u];
// // //         }
// // //         else{
// // //             parent[ulp_v]=ulp_u;
// // //             size[ulp_u]+=size[ulp_v];
// // //         }
// // //     }
// // // };
// // // ll mul (ll a, ll b, ll m=mod)
// // // {
// // //     a = a % m;
// // //     b = b % m;
// // //     return (((a * b) % m) + m) % m;
// // // }
// // // ll LCM(ll a, ll b)
// // // {
    
// // //     a = (a*b)/(__gcd(a,b));
// // //     return a;
// // // }
// // // bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
// // // {
// // //     return a.second < b.second;
// // // }
// // // ll power(ll base, ll exponent)
// // // {
// // //     if (exponent < 0)
// // //     {
// // //         return 0;
// // //     }
// // //     ll ans = 1;
// // //     while (exponent)
// // //     {
// // //         if (exponent%2==0)
// // //         {
// // //             base = (base*base) % mod;
// // //             exponent = exponent/2;
// // //         }
// // //         else
// // //         {
// // //             ans = (ans*base) % mod;
// // //             exponent--;
// // //         }
// // //     }
// // //     return ans;
// // // }

// // // ll mem(vector<vector<ll>>v1, vector<vector<ll>>v2, ll s, ll j, ll p){
// // //     if(s <= 0 ){
// // //         return 0;
// // //     }
// // //     if(j==v2.size()){
// // //         return INT_MAX;
// // //     }
    
// // //     if(v2[j][0] > p){
// // //         return INT_MAX;
// // //     }

// // //     ll take = mem(v1,v2,s-v2[j][1],j+1,p);
// // //     if(take != INT_MAX)
// // //         take += 1;
// // //     ll nontake = mem(v1,v2,s,j+1,p);

// // //     return min(take,nontake);
// // // }

// // // int main() {
// // //     ll tt;
// // //     cin>>tt;
// // //     while (tt--)
// // //     {
// // //         ll n,m,l;
// // //         cin>>n>>m>>l;
// // //         vector<vector<ll>>v1(n,vector<ll>(3,0));
// // //         vector<vector<ll>>v2(m,vector<ll>(2,0));
// // //         for(ll i=0; i<n; i++){
// // //             ll x,y;
// // //             cin>>x>>y;
// // //             v1[i][0]=x,v1[i][1]=y;
// // //             ll m=(y+1)-(x-1);
// // //             v1[i][2]=m;
// // //         }       
// // //         for(ll i=0; i<m; i++){
// // //             ll x,y;
// // //             cin>>x>>y;
// // //             v2[i][0]=x,v2[i][1]=y;
// // //         }
// // //         sort(v2.begin(),v2.end(),[](const vector<ll>x, const vector<ll>y){
// // //             if(x[0]==y[0])
// // //                 return x[1]>y[1];
// // //             return x[0] < y[0];    
// // //         });

// // //         vi a(n);
// // //         bool f=true;
// // //         for(ll i=0; i<n; i++){
// // //             ll m=(v1[i][1]+1)-(v1[i][0]-1);
// // //             ll k=mem(v1,v2,m,0,v1[i][0]);
// // //             if(m > 0 || k==INT_MAX){
// // //                 f=false;
// // //                 break;
// // //             }
// // //             if(i==0)
// // //                 a[i]=k;
// // //             else{
// // //                 a[i]=max(a[i],a[i-1]);
// // //                 // if(v1[i][2] <= v1[i-1][2]){
// // //                 //     a[i]=a[i-1];
// // //                 // }
// // //                 // else{
// // //                 //     a[i]=max(a[i],1+a[i-1]);
// // //                 // }
// // //             }    

// // //         }   
// // //         if(!f){
// // //             cout<<-1<<endl;
// // //             continue;
// // //         }

// // //         cout<<a[n-1]<<endl;
// // //     }
// // //     return 0;
// // // }


// // #include <bits/stdc++.h>
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

// // ll mem(const vector<vector<ll>> &v2, ll s, ll j, ll p, vector<vector<ll>> &dp) {
 
// //     if (s <= 0)
// //         return 0;
// //     if (j >= v2.size() || v2[j][0] > p)
// //         return INT_MAX;

// //     if (dp[j][s] != -1)
// //         return dp[j][s];

// //     ll take = mem(v2, s - v2[j][1], j + 1, p, dp);
// //     if (take != INT_MAX) 
// //         take += 1;

// //     ll nontake = mem(v2, s, j + 1, p, dp);

// //     return dp[j][s] = min(take, nontake);
// // }

// // int main() {
// //     ll tt;
// //     cin >> tt;
// //     while (tt--) {
// //         ll n, m, l;
// //         cin >> n >> m >> l;

// //         vector<vector<ll>> v1(n, vector<ll>(3, 0));
// //         vector<vector<ll>> v2(m, vector<ll>(2, 0));

// //         for (ll i = 0; i < n; i++) {
// //             ll x,y;
// //             cin>>x>>y;
// //             v1[i][0]=x,v1[i][1]=y;
// //             ll m=(y+1)-(x-1);
// //             v1[i][2]=m;
// //         }
// //         for (ll i = 0; i < m; i++) {
// //             ll x,y;
// //             cin>>x>>y;
// //             v2[i][0]=x,v2[i][1]=y;
// //         }

// //         sort(v2.begin(), v2.end(), [](const vector<ll> &x, const vector<ll> &y) {
// //             if (x[0] == y[0])
// //                 return x[1] > y[1];
// //             return x[0] < y[0];
// //         });

// //         vi a(n, 0);
// //         bool f = true;

// //         for (ll i = 0; i < n; i++) {
// //             ll m = v1[i][1] - v1[i][0] + 1;

// //             vector<vector<ll>> dp(v2.size(), vector<ll>(m + 1, -1));

// //             ll k = mem(v2, m, 0, v1[i][0], dp);

// //             if (k == INT_MAX) {
// //                 f = false;
// //                 break;
// //             }

// //             if(i==0)
// //                 a[i]=k;
// //             else{
// //                 if(v1[i][2] <= v1[i-1][2]){
// //                     a[i]=a[i-1];
// //                 }
// //                 else{
// //                     a[i]=max(k,a[i-1]);
// //                     if(a[i]==a[i-1])
// //                         a[i]++;
// //                 }
// //             }    
// //         }

// //         if (!f) {
// //             cout<<-1<<endl;
// //             continue;
// //         }

// //         cout << a[n-1] << endl;
// //     }
// //     return 0;
// // }


// #include <bits/stdc++.h>
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

// ll mem(const vector<vector<ll>> &v2, ll s, ll j, ll p, vector<vector<ll>> &dp) {
 
//     if (s <= 0)
//         return 0;
//     if (j >= v2.size() || v2[j][0] > p)
//         return INT_MAX;

//     if (dp[j][s] != -1)
//         return dp[j][s];

//     ll x = mem(v2, s - v2[j][1], j + 1, p, dp);
//     if (x != INT_MAX) 
//         x += 1;

//     ll y = mem(v2, s, j + 1, p, dp);

//     return dp[j][s] = min(x, y);
// }

// int main() {
//     ll tt;
//     cin >> tt;
//     while (tt--) {
//         ll n, m, l;
//         cin >> n >> m >> l;

//         vector<vector<ll>> v1(n, vector<ll>(3, 0));
//         vector<vector<ll>> v2(m, vector<ll>(2, 0));

//         for (ll i = 0; i < n; i++) {
//             ll x,y;
//             cin>>x>>y;
//             v1[i][0]=x,v1[i][1]=y;
//             ll m=(y+1)-(x-1);
//             v1[i][2]=m;
//         }
//         for (ll i = 0; i < m; i++) {
//             ll x,y;
//             cin>>x>>y;
//             v2[i][0]=x,v2[i][1]=y;
//         }

//         sort(v2.begin(), v2.end(), [](const vector<ll> &x, const vector<ll> &y) {
//             if (x[0] == y[0])
//                 return x[1] > y[1];
//             return x[0] < y[0];
//         });

//         vi a(n, 0);
//         bool f = true;

//         for (ll i = 0; i < n; i++) {
//             ll m = v1[i][1] - v1[i][0] + 1;

//             vector<vector<ll>> dp(v2.size(), vector<ll>(m + 1, -1));

//             ll k = mem(v2, m, 0, v1[i][0], dp);

//             if (k == INT_MAX) {
//                 f = false;
//                 break;
//             }

//             if(i==0)
//                 a[i]=k;
//             else{
//                 if(v1[i][2] <= v1[i-1][2]){
//                     a[i]=a[i-1];
//                 }
//                 else{
//                     a[i]=max(k,a[i-1]);
//                     if(a[i]==a[i-1])
//                         a[i]++;
//                 }
//             }    
//         }

//         if (!f) {
//             cout<<-1<<endl;
//             continue;
//         }

//         cout << a[n-1] << endl;
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
        ll n, m, l;
        cin >> n >> m >> l;

        vector<vector<ll>> v1(n, vector<ll>(3, 0));
        vector<vector<ll>> v2(m, vector<ll>(2, 0));

        for (ll i = 0; i < n; i++) {
            ll x,y;
            cin>>x>>y;
            v1[i][0]=x,v1[i][1]=y;
            ll m=(y+1)-(x-1);
            v1[i][2]=m;
        }
        for (ll i = 0; i < m; i++) {
            ll x,y;
            cin>>x>>y;
            v2[i][0]=x,v2[i][1]=y;
        }

        ll maxi=v1[n-1][1];
        priority_queue<ll>pq;
        ll st=1;
        ll j=0;
        ll k=0;
        ll jump=1;
        bool f=true;
        ll cn=0;
        while(j<n){
            while(k<v2.size() && v2[k][0]<v1[j][0]){
                pq.push(v2[k][1]);
                k++;
            }
            ll kk=(v1[j][1]+1)-(v1[j][0]-1);
            while(jump<kk && !pq.empty()){
                cn++;
                jump += pq.top();
                pq.pop();
            }
            if(jump<kk){
                f=false;
                break;
            }
            j++;
        }
        if(!f){
            cout<<-1<<endl;
        }
        else{
            cout<<cn<<endl;
        }
    }
    return 0;
}