// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>
// #define vvp vector<pair<ll,ll>>
// #define vvt vector<tuple<ll,ll,ll>>
// #define all(a) (a).begin(),(a).end()
// #define rall(a) (a).rbegin(),(a).rend()
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
// ll mAdd(ll a, ll b, ll m = mod){
//     a = a % m;
//     b = b % m;
//     return (((a + b) % m) + m) % m;
// }
// ll mSub(ll a, ll b, ll m = mod){
//     a = a % m;
//     b = b % m;
//     return (((a - b) % m) + m) % m;
// }
// ll mul (ll a, ll b, ll m=mod){
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll LCM(ll a, ll b){
    
//     a = (a*b)/(__gcd(a,b));
//     return a;
// }
// bool customComparator(const pair<int, int> &a, const pair<int, int> &b){
//     return a.second > b.second;
// }
// ll power(ll base, ll exponent){
//     if (exponent < 0){
//         return 0;
//     }
//     ll ans = 1;
//     while (exponent){
//         if (exponent%2==0){
//             base = (base*base) % mod;
//             exponent = exponent/2;
//         }
//         else{
//             ans = (ans*base) % mod;
//             exponent--;
//         }
//     }
//     return ans;
// }
// ll invmod(ll a, ll m = mod){
//     return power(a, m - 2);
// }
// ll div(ll a, ll b, ll m = mod){
//     a = a % m;
//     b = b % m;
//     return mul(a, invmod(b, m), m);
// }

// bool newCustomComparator (const pair<int, int> &a, const pair<int, int> &b){
//     return a.first < b.first;
// }


// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr); std::cout.tie(nullptr);


//     ll tt=1;
//     // cin>>tt;
//     while (tt--)
//     {
//         ll n,l,k;
//         cin>>n>>l>>k;

//         vvp v(n);
//         for(ll i=0; i<n; i++){
//             ll x;cin>>x;
//             v[i].first=x;
//         }
//         for(ll i=0; i<n; i++){
//             ll x;cin>>x;
//             v[i].second=x;
//         }
//         vvp vv=v;
//         sort(v.begin(),v.end(),customComparator);
//         vi f(n,0);
//         ll t=0;
//         for(ll i=0; i<n; i++){
//             if(t>=k)
//                 break;
//             if(v[i].first==0)
//                 continue;
//             f[i]=1;    
//             t++;
//         }
//         vvp d;
//         for(ll i=0; i<n; i++){
//             if(f[i]==1)
//                 continue;
//             d.pb({v[i].first,v[i].second});    
//         }

//         // for(auto i:d)
//         //     cout<<i.first<<' '<<i.second<<' ';

//         sort(d.begin(),d.end(),newCustomComparator);
//         vvp r1;
//         r1.pb({vv[0].first,vv[0].second});
//         t=0;
//         ll pre=0;
//         for(ll i=1; i<n; i++){
//             if(vv[i].second > vv[pre].second && t<k){
//                 // cout<<"hi "<<i<<' ';
//                 t++;
//             }
//             else{
//                 r1.pb({vv[i].first,vv[i].second});
//                 pre=i;
//             }
//             // if(t>=k)
//             //     break;
//         }
//         vvp r2;
//         // pre=
//         // for(ll i=n-1; i>=1; i--){

//         // }
//         // for(auto i:r1)
//         //     cout<<i.first<<' '<<i.second<<' ';
//         ll ans=0;
//         for(ll i=1; i<d.size(); i++){
//             ll t1=d[i-1].first,t2=d[i].first;
//             ll q=d[i-1].second;
//             ans += (t2-t1)*q;
//         }
//         ans += (l-d[d.size()-1].first)*d[d.size()-1].second;
//         ll cn=0;
//         for(ll i=1; i<r1.size(); i++){
//             ll t1=r1[i-1].first,t2=r1[i].first;
//             ll q=r1[i-1].second;
//             cn += (t2-t1)*q;
//         }
//         cn += (l-r1[r1.size()-1].first)*r1[r1.size()-1].second;
//         cout<<min(ans,cn)<<endl;
//     }
//     return 0;
// }


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool customComparator(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
   
int main(){
  // Write your code here
  int n;
  cin>>n;
  vector<string>v;
  for(int i=0; i<n; i++){
    string x;
    cin>>x;
    v.push_back(x);
  }
  vector<pair<string,int>> a;
  for(int i=0; i<n; i++){
    string d=v[i];
    int p=0;
    for(auto i:d){
      p+=i-'a';
    }
    a.push_back({d,p});
  }
  sort(a.begin(),a.end(),customComparator);
  for(int i=0; i<n; i++){
    cout<<a[i].first<<endl;
  }
  return 0;
}