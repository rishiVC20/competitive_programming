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


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,m,v;
        cin>>n>>m>>v;

        vi a;
        ll cn=0;
        vi pre;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            cn += a[i];
        }      
        pre.pb(a[0]);
        for(ll i=1; i<n; i++){
            pre.pb(a[i]+pre[i-1]);
        } 

        if(v*m > cn){
            cout<<-1<<endl;
            continue;
        }

        map<ll,ll>mp2;
        ll b=0;
        ll maxi=0;
        ll cur=0,per=0,r=1;
        for(ll i=0; i<n; i++){
            cur += a[i];
            if(cur >= v){
                mp2[r]=i;
                r++;
                per++;
                cur=0;
            }
            if(per==m){
                // if(i==0)
                    // maxi=max(maxi,pre[i]);
                if(i!=0)   
                    maxi=max(maxi,pre[n-1]-pre[i]);
                break;
            }
        }
        // cout<<maxi<<' ';
        ll f1=per;

        cur=0,per=0;
        map<ll,ll>mp1;
        ll h=1;
        for(ll i=n-1; i>=0; i--){
            cur += a[i];
            if(cur >= v){
                per++;
                mp1[h]=i;
                h++;
                cur=0;
            }
            if(per==m){
                if(i!=0)
                    maxi=max(maxi,pre[i-1]);
                break;
            }
        }
        // cout<<maxi<<' ';

        ll f2=per;

        if(f1<m && f2<m){
            cout<<-1LL<<endl;
            continue;
        }
        // cout<<"hi "<<endl;
        cur=0,per=0;

        per=0,cur=0;
        for(ll i=0; i<n; i++){
            if(cur=0){
                ll g=per;
                ll t=m-per;
                
                if(i==0 && mp1.find(t)!=mp1.end()){
                    ll d=mp1[t];
                    maxi=max(maxi,pre[d-1]);
                }
                else if(mp1.find(t)!=mp1.end()){
                    // if()
                    ll d=mp1[t];
                    maxi=max(maxi,pre[d-1]-pre[i-1]);
                }
            }
            cur += a[i];
            if(cur >= v){
                cur=0;
                per++;
            }
        }

        per=0,cur=0;
        for(ll i=n-1; i>=0; i--){
            if(cur==0){
                ll g=per;
                ll t=m-per;
                if(mp2.find(t)!=mp2.end()){
                    ll d=mp2[t];
                    maxi=max(maxi,pre[i]-pre[d]);
                }
            }
            cur += a[i];
            if(cur >= v){
                cur=0,per++;
            }
        }

        cout<<maxi<<endl;


    }
    return 0;
}