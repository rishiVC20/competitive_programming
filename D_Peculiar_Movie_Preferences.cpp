// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long 
// // #define pb push_back 
// // #define onebit(x) __builtin_popcountll(x)
// // #define vi vector<ll>
// // #define vvp vector<pair<ll,ll>>
// // #define vvt vector<tuple<ll,ll,ll>>
// // #define all(a) (a).begin(),(a).end()
// // #define rall(a) (a).rbegin(),(a).rend()
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
// // ll mAdd(ll a, ll b, ll m = mod){
// //     a = a % m;
// //     b = b % m;
// //     return (((a + b) % m) + m) % m;
// // }
// // ll mSub(ll a, ll b, ll m = mod){
// //     a = a % m;
// //     b = b % m;
// //     return (((a - b) % m) + m) % m;
// // }
// // ll mul (ll a, ll b, ll m=mod){
// //     a = a % m;
// //     b = b % m;
// //     return (((a * b) % m) + m) % m;
// // }
// // ll LCM(ll a, ll b){
    
// //     a = (a*b)/(__gcd(a,b));
// //     return a;
// // }
// // bool customComparator(const pair<int, int> &a, const pair<int, int> &b){
// //     return a.second < b.second;
// // }
// // ll power(ll base, ll exponent){
// //     if (exponent < 0){
// //         return 0;
// //     }
// //     ll ans = 1;
// //     while (exponent){
// //         if (exponent%2==0){
// //             base = (base*base) % mod;
// //             exponent = exponent/2;
// //         }
// //         else{
// //             ans = (ans*base) % mod;
// //             exponent--;
// //         }
// //     }
// //     return ans;
// // }
// // ll invmod(ll a, ll m = mod){
// //     return power(a, m - 2);
// // }
// // ll div(ll a, ll b, ll m = mod){
// //     a = a % m;
// //     b = b % m;
// //     return mul(a, invmod(b, m), m);
// // }


// // int main() {
// //     std::ios::sync_with_stdio(false);
// //     std::cin.tie(nullptr); std::cout.tie(nullptr);


// //     ll tt;
// //     cin>>tt;
// //     while (tt--)
// //     {
// //         ll n;
// //         cin>>n;
// //         vector<string>a;
// //         map<string,ll>mp;
// //         bool f=false;
// //         for(ll i=0; i<n; i++){
// //             string  x;
// //             cin>>x;
// //             a.pb(x);
// //             // mp[x]++;
// //             if(x.size()==1){
// //                 f=true;
// //             }
// //             if(x.size()==2 ){
// //                 if(x[0]==x[1]){
// //                     f=true;
// //                 }
// //             }
// //             if(x.size()==3 && x[0]==x[1] && x[1]==x[2]){
// //                 f=true;
// //             }
// //         }
// //         if(f){
// //             YES;
// //             continue;
// //         }
// //         mp[a[n-1]]++;
// //         for(ll i=n-1; i>=0; i--){
// //             // cout<<i<<' '; 
// //             string s=a[i];
            
// //             reverse(s.begin(),s.end());
// //             bool t=false;
// //             if(s.size()==2){
// //                 string p1="";
// //                 p1.pb(s[0]);
// //                 string p2="";
// //                 p2.pb(s[1]);
// //                 if(mp.find(p1)!=mp.end()){
// //                     if(mp.find(p2)!=mp.end()){
// //                         t=true;
// //                     }
// //                 }
// //                 if(mp.find(s)!=mp.end()){
// //                     f=true;
// //                 }
// //             }
// //             if(s.size()==3){
// //                 string w=a[i];
// //                 string j1="";
// //                 j1.pb(w[0]);
// //                 string j2="";
// //                 j2.pb(w[1]),j2.pb(w[2]);
// //                 mp[j2]++;
// //                 if(mp.find(j1)==mp.end() && mp.find(j2)!=mp.end()){
// //                     f=true;
                
// //                 }
// //                 string p1="";
// //                 p1.pb(s[0]);
// //                 string p2="";
// //                 p2.pb(s[1]);
// //                 string p3="";
// //                 p3.pb(s[2]);
// //                 string p4="";
// //                 p4.pb(s[0]),p4.pb(s[1]);
// //                 string p5="";
// //                 p5.pb(s[1]),p5.pb(s[2]);
// //                 // mp[p5]++;
// //                 if(mp.find(p1)!=mp.end()){
// //                     if(mp.find(p2)!=mp.end()){
// //                         if(mp.find(p3)!=mp.end()){
// //                             t=true;
// //                         }
                        
// //                     }
// //                 }
// //                 if(mp.find(p4)!=mp.end()){
// //                     // cout<<"hi";
// //                     if(mp.find(p3)!=mp.end()){
// //                         f=true;
// //                     }
// //                     else{
// //                         string d1=p3;
// //                         // cout<<d1<<' ';
// //                         for(ll i=0; i<26; i++){
// //                             d1.pb(i+'a');
// //                             // cout<<d1<<' ';
// //                             if(mp.find(d1)!=mp.end()){
// //                                 t=true;
// //                                 break;
// //                             }
// //                             d1.pb(i+'a');
// //                             if(mp.find(d1)!=mp.end()){
// //                                 t=true;
// //                                 break;
// //                             }
// //                             d1.pop_back();
// //                             d1.pop_back();
// //                         }
// //                     }
// //                 }
// //                 if(mp.find(p1)!=mp.end()){
// //                     if(mp.find(p5)!=mp.end()){
// //                         t=true;
// //                     }
// //                 }
// //                 if(mp.find(s)!=mp.end()){
// //                     t=true;
// //                 }
// //                 // if(mp.find(p4)!=mp.end() && mp.find(p3)==mp.end()){
// //                 //     f=true;
// //                 // }
// //                 if(mp.find(p1)==mp.end() && mp.find(p5)!=mp.end()){
// //                     f=true;
// //                 }
// //             }
// //             if(t){
// //                 f=true;
// //                 break;
// //             }
// //             mp[a[i]]++;
// //         }
// //         // for(auto i:mp)
// //         //     cout<<i.first<<' '; 

// //         if(f)
// //             YES;
// //         else
// //             NO;    
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
//     return a.second < b.second;
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


// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr); std::cout.tie(nullptr);


//     ll tt;
//     cin>>tt;
//     while (tt--)
//     {
//         ll n;
//         cin>>n;
//         vector<string>a;
//         bool f=false;
//         for(ll i=0; i<n; i++){
//             string x;cin>>x;
//             a.pb(x);
//             if(x.size()==1){
//                 f=true;
//             }
//             if(x.size()==2 ){
//                 if(x[0]==x[1]){
//                     f=true;
//                 }
//             }
//             if(x.size()==3 && x[0]==x[1] && x[1]==x[2]){
//                 f=true;
//             }
//             if(x.size()==3 && x[0]==x[2]){
//                 f=true;
//             }
//         }
//         if(f){
//             YES;
//             continue;
//         }
//         map<string,ll>mp;

//         for(ll i=n-1; i>=0; i--){
//             string s=a[i];
//             reverse(s.begin(),s.end());
//             if(mp.find(s)!=mp.end()){
//                 f=true;
//             }
//             string w="";
//             // if(s.size()==2){
//             //     string p1="";
//             //     p1.pb(s[0]);
//             //     string p2="";
//             //     p2.pb(s[1]);
//             // }
//             if(s.size()==3){
//                 w.pb(a[i][1]);
//                 // mp[w]++;
//                 w.pb(a[i][2]);
//                 mp[w]++;
//                 string p1="";
//                 p1.pb(s[0]);
//                 string p2="";
//                 p2.pb(s[1]);
//                 string p3="";
//                 p3.pb(s[2]);
//                 string p4="";
//                 p4.pb(s[0]),p4.pb(s[1]);
//                 string p5="";
//                 p5.pb(s[1]),p5.pb(s[2]);
//                 // cout<<p1<<' '<<p5<<' ';
//                 if(mp.find(p5)!=mp.end() || mp.find(p4)!=mp.end()){
//                     f=true;
//                 }
//             }
//             mp[a[i]]++;
//         }
//         for(auto i:mp)
//             cout<<i.first<<' ';

//         if(f)
//             YES;
//         else
//             NO;    
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        std::vector<string>a ;
        bool f=false;
        for(ll i=0; i<n; i++){
            string s;cin>>s;
            a.push_back(s);
            if(s.size()==1){
                f=true;
            }
            if(s.size()==2){
                if(s[0]==s[1]){
                    f=true;
                }
            }
            if(s.size()==3){
                if(s[0]==s[2]){
                    f=true;
                }
            }
        }
        if(f){
            cout<<"YES"<<endl;
            continue;
        }
        map<string,ll>m1;
        map<string,ll>m2;
        
        for(ll i=n-1; i>=0; i--){
            string s=a[i];
            reverse(s.begin(),s.end());
            if(s.size()==2){
                if(m2.find(s)!=m2.end() || m1.find(s)!=m1.end()){
                    f=true;
                }
            }
            string w="";
            if(s.size()==3){
                if(m2.find(s)!=m2.end()){
                    f=true;
                }
                w.push_back(a[i][1]);
                w.push_back(a[i][2]);
                m2[w]++;
                string p1="";
                p1.push_back(s[0]);
                string p2="";
                p2.push_back(s[1]);
                string p3="";
                p3.push_back(s[2]);
                string p4="";
                p4.push_back(s[0]),p4.push_back(s[1]);
                string p5="";
                p5.push_back(s[1]),p5.push_back(s[2]);
                if(m1.find(p5)!=m1.end()){
                    f=true;
                }
            }
            if(s.size()==2){
                m1[a[i]]++;
            }
            else{
                m2[a[i]]++;
            }
        }
        // for(auto i:m2)
        //     cout<<i.first<<' ';
        
        if(f)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

/*
10
5
zx
ab
cc
zx
ba
2
ab
bad
4
co
def
orc
es
3
a
b
c
3
ab
cd
cba
2
ab
ab
2
abc
cbk
2
add
da
2
apk
pa
3
cba
cd
dc
*/