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
        ll n,k;
        cin>>n>>k;

        string s;
        cin>>s;
        sort(s.begin(),s.end());
        if(k==1){
            cout<<s<<endl;
            continue;
        }
        bool f=true;
        char p=s[0];
        for(auto i:s){
            if(p!=i){
                f=false;
                break;
            }
        }
        if(f){
            ll d;
            if(n%k==0){
                d=n/k;
            }
            else{
                ll p=k-n%k;
                d=(n+p)/k;
            }
            // cout<<d<<' ';
            string v=s.substr(0,d);
            cout<<v<<endl;
            continue;
        }

        if(k==2){
            if(s[1]!=s[0]){
                cout<<s[1]<<endl;
                continue;
            }
            bool t=true;
            char e=s[2];
            ll cp=0;
            for(ll i=2; i<n; i++){
                if(s[i]==e){
                    cp++;
                }
                else{
                    t=false;
                    break;
                }
            }
            if(t){
                ll m=cp/2+(cp%2!=0);
                string g=s.substr(1,m+1);
                cout<<g<<endl;
                continue;
            }
            string ans="";
            if(s[0]!=s[1]){
                ans+=s[1];
            }
            else{
                // cout<<"hi ";
                ans=s.substr(1);
            }
            cout<<ans<<endl;
            continue;
        }

        set<ll>st;
        for(ll i=0; i<k; i++){
            st.insert(s[i]);
        }
        if(st.size()>1){
            cout<<s[k-1]<<endl;
        }
        else{
            set<ll>ss;
            ll cn=0;
            for(ll i=k; i<n; i++){
                ss.insert(s[i]);
                cn++;
            }
            if(ss.size()==1){
                ll b=cn/k+(cn%k!=0);
                string sp=s.substr(k-1,b+1);
                cout<<sp<<endl;
                continue;
            }
            string g=s.substr(k-1);
            cout<<g<<endl;
        }
    }
    return 0;
}
