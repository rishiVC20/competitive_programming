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

const ll mod = 9223372036854775807;

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


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        string s;
        cin>>s;
        ll a,b;
        cin>>a>>b;
        ll n=s.size();
        vi v1;
        ll st=0;
        for(ll i=0; i<n-1; i++){
            ll ch=s[i]-'0';
            st=(st*10+ch)%mod;
            if(st%a==0 && s[i+1]!='0'){
                v1.pb(i);
            }
        }
        
        vi v2;
        ll sp=0;
        ll r=0;
        ll gk=1;
        for(ll i=n-1; i>=1; i--){
            ll ch=s[i]-'0';
            // if(ch==0)
            //     continue;
            if(i==n-1){
                sp=ch;
                
            }    
            else{
                gk=(gk*10)%mod;
                sp=(gk*ch+sp)%mod;
            }
            // cout<<sp<<' ';
            r++;
            if(sp%b==0 && ch!=0){
                v2.pb(i);
            }
        }
        // cout<<v1.size()<<' ';
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        ll j1=-1,j2=-1;
        for(ll i=0; i<(ll)v1.size(); i++){
            ll t=v1[i];
            // cout<<t<<' ';
            ll up=upper_bound(v2.begin(),v2.end(),t)-v2.begin();
            // up--;
            if(up<(ll)v2.size() && v2[up]-t==1){
                j1=t,j2=v2[up];
                break;
            }
        }
        // for(auto i:v2){
        //     cout<<i<<' ';
        // }
        if(j1==-1 || j2==-1){
            NO;
            continue;
        }

        string s1=s.substr(0,j1+1);
        string s2=s.substr(j2);

        YES;
        cout<<s1<<endl;
        cout<<s2<<endl;
    }
    return 0;
}