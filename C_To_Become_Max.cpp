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
//     return a.first > b.first;
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
//         ll j=-1;
//         ll maxi=INT_MIN;
//         vector<pair<ll,ll>>v;
//         // priority_queue<pair<ll,ll>>pq;

//         auto cmp = [](pair<ll, ll> a, pair<ll, ll> b) {
//             if (a.first == b.first) {
//                 return a.second > b.second; 
//             }
//             return a.first < b.first;
//         };

//         priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq(cmp);
//         for(ll i=0; i<n; i++){
//             // cout<<'j';
//             ll x;cin>>x;
//             a.pb(x);
//             if(x>maxi){
//                 maxi=x,j=i;
//             }
//             v.pb({x,i});
//             pq.push({x,i});

//         }

//         sort(v.begin(),v.end(),customComparator);

//         // while(!pq.empty()){
//         //     cout<<pq.top().first<<' '<<pq.top().second<<endl;
//         //     pq.pop();
//         // }
//         ll h=0;

//         while(k>0 && !pq.empty()){
//             // ll v1=v[h].first,v2=v[h].second;
//             auto d=pq.top();
//             ll v1=d.first,v2=d.second;
//             v1=max(v1,a[v2]);
//             cout<<v1<<' '<<v2<<endl;
//             bool f=false;
//             for(ll j=v2-1; j>=0; j--){
//                 if(a[j] <= v1){
//                     ll p=(v1-a[j]+1);
//                     if(k>=p){
//                         a[j]+=p;
//                         k-=p;
//                     }
//                     else{
//                         a[j]+=k;
//                         k=0;
//                     }
//                     // pq.push({a[j],j});
//                     v1=a[j];
//                 }
//                 if(k==0){
//                     break;
//                 }
//             }
//             pq.pop();
//             if(k==0){
//                 break;
//             }
//         }

//         ll ans=*max_element(a.begin(),a.end());

//         // for(auto i:a){
//         //     maxi=max(maxi,i);
//         // }

//         cout<<ans<<endl;

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

bool check(vi &a, ll val, ll ind, ll ops){
    if(ind==a.size()){
        return false;
    }

    if(a[ind] >= val){
        return true;
    }

    ll req=val-a[ind];

    if(req>ops){
        return false;
    }

    return check(a,val-1,ind+1,ops-req);
}

ll solve(vi &a, ll ind, ll k){
    if(ind+1==a.size()){
        return a[ind];
    }
    ll low=a[ind],high=a[ind]+k;

    while(low < high){
        ll mid=(low+high)/2 + 1;
        if(check(a,mid,ind,k)){
            low=mid;
        }
        else{
            high=mid-1;
        }
    }

    return low;
}


int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;

        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        ll maxi=0;

        for(ll i=0; i<n; i++){
            maxi=max(maxi,solve(a,i,k));
        }

        cout<<maxi<<endl;
    }
    return 0;
}