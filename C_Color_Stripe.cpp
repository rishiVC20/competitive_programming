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


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(k==2){
            char a='A',b='B';
            string c="";
            while(c.size()<n){
                c += a;
                if(c.size()==n)
                    break;
                c += b;    
            }

            string g="";
            while(g.size()<n){
                g+=b;
                if(g.size()==n)
                    break;
                g+=a;    
            }
            ll cn1=0,cn2=0;
            for(ll i=0; i<n; i++){
                cn1+=(c[i]!=s[i]);
                cn2+=(g[i]!=s[i]);
            }

            if(cn1>cn2){
                cout<<cn2<<endl;
                cout<<g<<endl;
                continue;
            }

            cout<<cn1<<endl;
            cout<<c<<endl;
            continue;
        }

        ll cn=0;
        for(ll i=1; i<n; i++){
            if(s[i]==s[i-1]){
                cn++;
                ll k1=s[i-1]-'A'+1;
                if(i+1==n){
                    // cout<<"Hi ";
                    ll k2;
                    if(k1==k){
                        k2=k1-2;
                    }
                    else{
                        k2=k1;
                    }
                    char ch=k2+'A';
                    s[i]=ch;
                    continue;
                }
                ll k3=s[i+1]-'A'+1;
                if(k1==k3){
                    ll k2;
                    if(k1==k){
                        k2=k1-2;
                    }
                    else{
                        k2=k1;
                    }
                    char ch=k2+'A';
                    s[i]=ch;
                    continue;
                }

                // if(abs(k1-k3)==1 && k==2){
                //     // cout<<"hi ";
                //     // cn--;
                //     if(i-1==0){
                //         s[i-1]=s[i+1];
                //     }
                //     continue;
                // }

                if(k1<k && k1+1!=k3){
                    ll k2=k1;
                    char ch=k2+'A';
                    s[i]=ch;
                    continue;
                }

                if(k1 > 1 && k1-1!=k3){
                    ll k2=k1-2;
                    char ch=k2+'A';
                    s[i]=ch;
                    continue;
                }
                if(k3<k && k3+1!=k1){
                    ll k2=k3;
                    char ch=k2+'A';
                    s[i]=ch;
                    continue;
                }

                if(k3 > 1 && k3-1!=k1){
                    ll k2=k3-2;
                    char ch=k2+'A';
                    s[i]=ch;
                    continue;
                }

                // ll k2=k3-2;
                // char ch=k2+'A';
                // s[i]=ch;
            }

            
        }

        cout<<cn<<endl;
        cout<<s<<endl;
    }
    return 0;
}