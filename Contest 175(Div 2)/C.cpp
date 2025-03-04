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

bool solve(ll k, ll op, vi &a, string s){
    // for(auto i:a)
    //     cout<<i<<' ';
    // ll i=0;
    ll n=a.size();
    ll j1=0,j2=n-1;
    while(j1<n && s[j1]=='R'){
        j1++;
    }
    while(j2>=0 && s[j2]=='R'){
        j2--;
    }
    ll t=-1;
    ll tp=0;
    bool st=true;
    // cout<<j1<<' '<<j2<<" ";
    for(ll i=j1; i<=j2; i++){
        ll p=i;
        if(a[i]>k){
            if(s[i]=='B'){
                if(st){
                    tp++;
                    st=false;
                }
            }
            else{
                st=true;
            }
        }
        
    }
    

    return tp<=op;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vi a;
        ll r=0,b=0;
        ll s1=0,s2=0;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            r+=(s[i]=='R');
            b+=(s[i]=='B');
            if(s[i]=='R')
                s1=max(s1,x);
            else
                s2=max(s2,x);    
        }

        // if(r==0 || b==0 || b<=k){
        //     cout<<0<<endl;
        //     continue;
        // }
        // if(k==0){
        //     cout<<s2<<endl;
        //     continue;
        // }
        vi vv;
        ll c=0;
        for(ll i=0; i<n; i++){
            if(s[i]=='B'){
                c++;
            }
            else if(c>0){
                vv.pb(c);
                c=0;
            }
            if(i==n-1 && c>0){
                vv.pb(c);
            }
        }
        // if((ll)vv.size()<=k){
        //     cout<<0<<endl;
        //     continue;
        // }
        vi bb=a;
        sort(bb.begin(),bb.end());

        // ll st=0,en=bb[(ll)b;
        ll st=0,en=*max_element(a.begin(),a.end());
        ll ans=INT_MAX;
        while(st<=en){
            ll mid=(st+en)/2;

            if(solve(mid,k,a,s)){
                ans=mid;
                en=mid-1;
            }
            else{
                st=mid+1;
            }
            // cout<<mid<<' ';
        }
        cout<<ans<<endl;
        
    }
    return 0;
}