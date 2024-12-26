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

//         string s;
//         cin>>s;

//         ll x=0,y=0;
//         for(auto i:s){
//             x += (i=='0');
//             y += (i=='1');
//         }

//         ll u=x,v=y;
//         ll sc=0;
//         if(s[0]=='0') x--;
//         if(s[0]=='1') y--;

//         ll m=-1;
//         for(ll i=1; i<n; i++){
//             ll p=sc+(i*y-i*x);

//             if(p >= k){
//                 m=i;
//                 break;
//             }
//             if(s[i]=='0'){
//                 sc -= 1;
//                 x--;
//             }
//             if(s[i]=='1'){
//                 sc++;
//                 y--;
//             } 

//         }

//         if(m==-1){
//             cout<<-1<<endl;
//             continue;
//         }


//         if(s[0]=='0') u--;
//         if(s[0]=='1') v--;

//         ll j=1;
//         ll pk=0;
//         ll c=0,d=0;
//         while(j<n && s[j]=='0'){
//             u--;
//             j++;
//         }
//         ll cp=1;
//         bool f=false;
//         for(ll i=j; i<n;){
//             ll p=pk+(cp*v-cp*u);
//             cp++;
//             if(p>=k){
//                 break;
//             }
//             if(s[i]=='0'){
//                 pk-=(cp-1);
//                 u--;
//             }
//             else{
//                 pk+=(cp-1);
//                 v--;
//             }
//             i++;
//             while(i<n && s[i]=='0'){
//                 pk-=(cp-1);
//                 u--;
//                 i++;
//             }
//         }

//         // cout<<m<<" "<<cp<<" "; 

//         cout<<cp<<endl;
        
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

        string s;
        cin>>s;

        vi a;

        ll p=0;
        for(ll i=n-1; i>0; i--){
            if(s[i]=='0'){
                p--;
            }
            else{
                p++;
            }
            a.pb(p);
        }       
        sort(a.rbegin(),a.rend());
        // for(auto i:a)
        //     cout<<i<<' ';
        ll cn=0;
        ll sum=0;
        for(ll i=0; i<a.size(); i++){
            if(sum>=k){
                break;
            }
            if(a[i]>=0){
                cn++;
                sum+=a[i];
            }
            else{
                break;
            }
        }

        if(sum>=k)
            cout<<cn+1<<endl;
        else
            cout<<-1<<endl;    
    }
    return 0;
}