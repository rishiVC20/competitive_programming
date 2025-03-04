// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
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


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        ll sum=n*(n+1)/2;
        ll sq=sqrt(sum);
        if(sq*sq==sum){
            cout<<-1<<endl;
            continue;
        }
        if(n==2){
            cout<<2<<' '<<1<<endl;
            continue;
        }
        vi a,b;
        vi v;
        ll cur=0;
        set<ll>st;
        // v.pb(2);
        // ll k=1;
        // for(ll i=3; i<=n/3; i+=3){
        //     v[k]=i;
        //     k+=3;
        // }
        // k=2;
        // for(ll i=2; i<=n/3; i+=3){
        //     v[k]=i;
        //     k+=3;
        // }
        // k=3;
        // for(ll i=1; i<=n/3; i+=3){
        //     v[k]=i;
        //     k+=3;
        // }
        // v.pb(1);
        // for(ll i=4; i<=n; i+=2){
        //     v.pb(i);
        // }
        for(ll i=n; i>=1; i--){
            cur+=i;
            ll p=sqrt(cur);
            if(p*p==cur){
                cur-=i;
                a.pb(i);
            }   
            else{
                v.pb(i);
            }
        }
        // reverse(a.begin(),a.end());
        for(auto i:a){
            v.pb(i);
            // cout<<i<<' ';
        }
        ll ne=0;
        for(auto i:v){
        //     ne+=i;
        //     // cout<<ne<<' ';
            cout<<i<<' ';
        }
        cout<<endl;    

        // ll j1=0,j2=0;
        // vi v;
        // ll cur=0;

        // while(j1<(ll)a.size() && j2<(ll)b.size()){
        //     cur+=a[j1];
        //     ll m=sqrt(cur);
        //     if(m*m==cur){
        //         cur-=a[j1];
        //         cur+=b[j2];
        //         v.pb(b[j2]);
        //         j2++;
        //     }
        //     else{
        //         v.pb(a[j1]);
        //         j1++;
        //     }
        // }

        // while(j1<(ll)a.size()){
        //     v.pb(a[j1]);
        //     j1++;
        // }
        // while(j2<(ll)b.size()){
        //     v.pb(b[j2]);
        //     j2++;
        // }
        // // vi d;
        // // ll p=0;
        // // for(auto i:v){
        // //     p+=i;
        // //     cout<<p<<' ';
        // // }
        // for(auto i:v)
        //     cout<<i<<' ';
        // cout<<endl;    
    }
    return 0;
}