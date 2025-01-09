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

string decToBin(ll p){
    string s="";

    while (p>0){
        if(p&1)
            s = '1'+s;
        else
            s = '0'+s;
        p /= 2;        
    }

    return s;
}

ll binToDec(string s){
    ll n=s.size();

    // reverse(s.begin(),s.end());
    ll ans=0;
    ll j=0;
    for(ll i=n-1; i>=0; i--){
        ll p=s[i]-'0';
        ans += p*powl(2,j);
        j++;
    }

    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll l,r;
        cin>>l>>r;

        string aa=decToBin(l);
        string bb=decToBin(r);

        while(aa.size() < 32){
            aa = '0'+aa;
        }
        while(bb.size() < 32){
            bb = '0'+bb;
        }

        // cout<<aa<<' '<<bb<<' ';
        vi v1(32,0),v2(32,0);
        ll j=aa.size();
        for(ll i=0; i<32; i++){
            v1[i]=aa[i]-'0';
            v2[i]=bb[i]-'0';
        }

        vi a(32,0),b(32,0),c(32,0);

        ll m;
        for(ll i=0; i<32; i++){
            if(v1[i] != v2[i]){
                m=i;
                break;
            }
            a[i]=v1[i],b[i]=v2[i];
        }

        a[m]=1;

        for(ll i=m+1; i<32; i++){
            a[i]=0;
            b[i]=1;
        }
        // for(ll i=0; i<32; i++){
        //     cout<<a[i];
        // }
        // cout<<' ';
        string t1="",t2="";
        for(ll i=0; i<32; i++){
            char s1=a[i]+'0',s2=b[i]+'0';
            t1+=s1,t2+=s2;
        }
        // cout<<t1<<' '<<t2<<' ';
        ll x=binToDec(t1),y=binToDec(t2);
        ll z;
        if(x+1 <=r){
            z=r;
        }
        else{
            z=l;
        }

        cout<<x<<' '<<y<<' '<<z<<endl;


    }
    return 0;
}

/*
2,14,74,83,646
2,14,74,83,646
*/