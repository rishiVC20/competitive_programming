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
//     ll n,h;
//     cin>>n>>h;
//     vi a;
//     for (ll i=0; i<n; i++){
//         ll x; cin>>x;
//         a.pb(x);
//     }
//     if (n<=2){
//         cout<<n<<endl;
//         return 0;
//     }
//     ll qq = 1;
//     ll k;
//     if (a[0]<a[1]){
//         k=-1;
//         bool f=true;
//         ll cn=0;
//         ll sum = a[0];
//         for (ll i=1; i<n; i++){
//             if (sum+a[i] == h){
//                 k=i;
//                 f=false;
//                 cn++;
//             }
//             else if (sum+a[i] > h){
//                 k=i-1;
//                 f=false;
//                 break;
//             }
//             else{
//                 if (!f ){
//                     // k=i;
//                     break;
//                 }
//             }
//             if (cn==2)
//                 break;
//             if (i%2 == 0){
//                 sum += max(a[i],a[i-1]);
//             }    
//         }
//         if (f){
//             cout<<1<<endl;
//             return 0;
//         }
//         if (k%2==1){
//             k++;
//         }
//         k++; //k is 0 indexed ll 
//         qq = max(qq,k);
//     }
//     // else{
//         ll q=-1;
//         bool f=true;
//         ll pp=0;
//         ll res = max(a[0],a[1]);
//         for (ll i=2; i<n; i++){
//             if (res+a[i] == h){
//                 q=i;
//                 f=false;
//                 pp++;
//             }
//             else if (res+a[i] > h){
//                 q = i-1;
//                 f=false;
//                 break;
//             }
//             else{
//                 if (!f)
//                     break;
//             }
//             if (pp==2)
//                 break;
//             if (i%2 == 1){
//                 res += max(a[i],a[i-1]);
//             }    
//         }
//         if (f){
//             cout<<n<<endl;
//             return 0;
//         }
//         if (q%2 == 0)
//             q++;
//         ll ans = 2+(q-1);
//         qq = max(qq,ans);

//     // }

//     cout<<qq<<endl;


    
//     return 0;
// }

// 10 20
// 3 2 8 6 6 9 6 10 10 5
// 6

// 5 7
// 2 3 5 4 1
// 3

// 100 2000
// 12 82 30 95 4 97 12 10 75 13 98 68 54 63 62 85 15 73 15 58 2 51 38 35 74 11 67 48 42 30 75 41 59 10 42 28 6 40 88 47 58 23 81 66 64 55 71 48 69 21 21 67 50 36 14 9 74 1 38 95 56 60 97 48 83 98 54 75 21 88 8 34 72 46 53 79 28 17 31 17 94 30 85 4 65 31 70 38 67 13 41 38 23 18 5 84 14 10 15 23
// 80

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
    ll t=1;
    // cin>>t;
    while (t--)
    {
        ll n,h;
        cin>>n>>h;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }
        sort(a.rbegin(),a.rend());
        ll ans=0;
        ll k=-1;
        for(ll i=0; i<n; i+=2){
            ans += a[i];
            if(ans>h){
                ans -= a[i];
                k=i;
                break;
            }
        }
        cout<<k<<' ';
        k -= 2;
        if(k+1<n){
            if(ans+a[k+1]<h)
                k++;
        }
        cout<<k+1<<endl;


    }
    return 0;
}