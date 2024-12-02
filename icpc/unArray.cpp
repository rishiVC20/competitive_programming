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

//         vector<vi> v(k,vi(3));

//         for(ll i=0; i<k; i++){
//             ll x,y,z;
//             cin>>x>>y>>z;
//             v[i][0]=x,v[i][1]=y,v[i][2]=z;
//         }   

//         segment

//         vi a(n,n);
//         sort(v.begin(),v.end(),[&](vi &a, vi &b){
//             if(a[2]==b[2])
//                 return a[0]<b[0];
//             return a[2]>b[2];
//         });
//         for(ll i=0; i<k; i++){
//             ll k=INT_MAX;
//             for(ll j=v[i][0]-1; j<v[i][1]; j++){
//                 k=min(k,a[j]);
//             }
//             if(k==v[i][2]){
//                 for(ll j=v[i][0]-1; j<v[i][1]; j++){
//                     if(a[j]==k){
//                         a[j]--;
//                     }
//                 }
//             }
            
//         }

//         bool f=true; 
//         for(auto i:a){
//             if(i<=0){
//                 f=false;
//                 break;
//             }
//         }
//         if(!f){
//             cout<<-1<<endl;
//             continue;
//         }

//         for(ll i=0; i<n; i++)
//             cout<<a[i]<<' ';
//         cout<<endl;    


//     }
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;
 
 
#define all(v) v.begin(), v.end()
#define sorti(v) sort(all(v))
#define rsorti(v) sort(v.rbegin(), v.rend())
#define MAXI(a) (*std::max_element((a).begin(), (a).end()))
#define MINI(a) (*std::min_element((a).begin(), (a).end()))
#define pp pair<int, int>
#define ff first
#define ss second
#define cy cout << "Yes" << endl
#define cn cout << "No" << endl
#define cinall(v)     \
    for (auto &i : v) \
    {                 \
        cin >> i;     \
    }
 
#define coutall(v)        \
    for (auto &i : v)     \
    {                     \
        cout << i << " "; \
    }                     \
    cout<<endl
 
#define ll long long
#define ld long double
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pb push_back
#define ppb pop_back
#define read(a)       \
    for (auto &i : a) \
    cin >> i
#define gcd __gcd
 
const ll mod = 1000007;

int main()
{   
    
    // prenCr();  
    ios::sync_with_stdio(0);
    cin.tie(0);  
    int tc = 1;
    cin >> tc;
    while(tc--){
        ll n,k;
        cin>>n>>k;
        vector<vector<ll>> vec(k,vector<ll> (3));
        for(int i=0;i<k;i++){
            ll l,r,m;
            cin>>l>>r>>m;
            vec[i][0] = l;
            vec[i][1] = r;
            vec[i][2] = m;
        }

        vector<set<ll>> ind(n);
        for(ll i=0;i<k;i++){
            for(ll j=vec[i][0]-1;j<vec[i][1];j++){
                ind[j].insert(vec[i][2]);
            }
        }

        vector<ll> ans;
        for(int i=0;i<n;i++){
            if(ind[i].size() != n){
                for(ll no=1;no<=n;no++){
                    if(ind[i].find(no) == ind[i].end()){
                        ans.push_back(no);
                        break;
                    }
                }   
            }
            else{
                break;
            }
        }

        if(ans.size() == n){
            for(auto i:ans)cout<<i<<" ";
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        
    }
    return 0;
}
 
/* 
 
 
*/