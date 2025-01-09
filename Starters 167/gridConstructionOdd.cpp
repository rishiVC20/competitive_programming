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
ll mAdd(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mSub(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mul (ll a, ll b, ll m=mod){
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b){
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
ll power(ll base, ll exponent){
    if (exponent < 0){
        return 0;
    }
    ll ans = 1;
    while (exponent){
        if (exponent%2==0){
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else{
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}
ll invmod(ll a, ll m = mod){
    return power(a, m - 2);
}
ll div(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return mul(a, invmod(b, m), m);
}

bool solve1(ll ch, ll i, ll j, vector<vi> &v){
    ll n=v.size();
    ll row=i,col=j;
    for(ll col=1; col<=n; col++){
        if(v[row][col]==ch){
            return false;
        }
    }
    row=i,col=j;
    for(ll row=1; row<=n; row++){
        if(v[row][col]==ch){
            return false;
        }
    }

    return true;
}
// bool solve2(ll ch, ll i, ll j, vector<vi> &v){
//     ll n=v.size();

//     for(ll i=1; i<=n; i++){
//         if(v[i][j]==ch){
//             return false;
//         }
//     }

//     return true;
// }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;

        vector<vi>v(n+10,vi(n+10,0));

        ll cn=1;
        // while(i<=n && j<=n){
        //     v[i++][j++]=cn++;
        // }

        ll i=1;
        while(cn<=n){

            ll j=1;
            ll k=i;
            while(k>=1 && j<=n){
                v[k][j]=cn;
                k--,j++;
            }

            if(j <= n){
                k=n;
                while(k>=1 && j<=n){
                    v[k][j]=cn;
                    k--,j++;
                }
            }
            i+=2;
            if(i==n+2){
                i=2;
            }
            cn++;
        }

        

        

        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                cout<<v[i][j]<<' ';
            }
            cout<<endl;
        }
        // cout<<endl;
    }
    return 0;
}