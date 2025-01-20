// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
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

ll solve(ll c1, ll c2, ll x, ll y){
    //x->c1,y->c2;

    ll p=x*(c1/(x-1));
    ll p1=(c1%((x-1)*(c1/(x-1))));
    p+=p1;
    if(p1==0)
        p--;
    ll m=p/(x*y);
    c2 -= m;
    ll n=p+1;
    ll j=(y-(n%y))%y;
    ll f=c2;
    c2 -= j;
    if(c2 <= j){
        return p+f;
    }    
    ll q=y*(c2/(y-1));
    ll q1=(c2%((y-1)*(c2/(y-1))));
    ll t=p+j;
    if(q1==0)
        q--;
    return  t+q;   
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll c1,c2,x,y;
        cin>>c1>>c2>>x>>y;
        ll p=solve(c1,c2,x,y);
        ll q=solve(c2,c1,y,x);
        // cout<<p<<' '<<q<<" ";
        cout<<min(p,q)<<endl;
        // if(x<y)
        //     swap(x,y);
        // // cout<<d1<<' '<<d2<<" hi";
        // ll p=x*(c1/(x-1));
        // // cout<<p<<' ';
        // ll p1=(c1%((x-1)*(c1/(x-1))));
        // p+=p1;
        // if(p1==0)
        //     p--;
        // cout<<p<<' '<<p1<<' ';
        // ll l=LCM(x,y);

        // ll k=l/x;
        // ll m=p/x;
        // ll t=m/k+(m%k);
        // cout<<l<<' '<<k<<' '<<m<<' '<<t<<' '<<p<<' ';
        // c2 -= t;
        // // cout<<c2<<' ';
        // if(c2<=0){
        //     cout<<p<<endl;
        //     continue;
        // }
        // ll n=p+1;
        // ll j=(y-(n%y))%y;
        // // cout<<c2<<' '<<j<<' ';
        // if(c2<=j){
        //     // cout<<"hi";
        //     n+=c2;
        //     c2-=j;
        // }       
        // else{
        //     // cout<<"hi";
        //     n+=(j+2);
        //     c2-=j;
        // }
        // ll ans=(n-1)+y*(c2/(y-1))+(c2%((y-1)*(c2/(y-1))));

        // cout<<ans<<endl;
    }
    return 0;
}