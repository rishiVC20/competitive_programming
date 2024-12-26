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
//         ll n;
//         cin>>n;

//         vi a(n);
//         for(ll i=0; i<n; i++){
//             cin>>a[i];

//         }

//         vector<pair<ll,ll>>v(n);
//         v[n-1].first=a[n-1];
//         v[n-1].second=n-1;
//         ll mini=a[n-1];
//         ll j=n-1;
//         for(ll i=n-2; i>=0; i++){
//             if(a[i] <= mini){
//                 j=i;
//                 mini=a[i];
                
//             }
//             v[i].first=mini,v[i].second=j;
//         }       

//         vi f;
//         ll k=INT_MAX;
//         for(ll i=0; i<n; i++){
//             if(v[i].second == i){
//                 if(k!=INT_MAX){
//                     f.pb(a[i]+1);
//                 }
//                 else{
//                     f.pb(a[i]);
//                 }
//                 // b.pb(a[i]);
//                 continue;
//             }

//             if(v[i].second > i){
//                 k=min(k,a[i]+1);
//                 f.pb(a[i]+1);
//             }
//             for(auto i:f)
//                 cout<<i<<' ';
//         }
//         // for(auto i:f)
//         //     cout<<i<<' ';
//         sort(f.begin(),f.end());

//         for(auto i:f)
//             cout<<i<<' ';
//         cout<<endl;    
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define vi vector<ll>

const ll mod = 1e9+7;

int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;

        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<ll, ll>> v(n);
        v[n - 1].first = a[n - 1];
        v[n - 1].second = n - 1;
        ll mini = a[n - 1];
        ll j = n - 1;
        for (ll i = n - 2; i >= 0; i--) {
            if (a[i] <= mini) {
                j = i;
                mini = a[i];
            }
            v[i].first = mini;
            v[i].second = j;
        }

        vi f;
        ll k = INT_MAX;
        for (ll i = 0; i < n; i++) {
            if (v[i].second == i) {
                if (a[i] > k) {
                    f.pb(a[i] + 1);
                } else {
                    f.pb(a[i]);
                }
                continue;
            }

            if (v[i].second > i) {
                k = min(k, a[i] + 1);
                f.pb(a[i] + 1);
            }
        }


        sort(f.begin(), f.end());

        for (auto i : f) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
