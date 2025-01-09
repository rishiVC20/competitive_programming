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
ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
ll power(ll base, ll exponent)
{
    if (exponent < 0)
    {
        return 0;
    }
    ll ans = 1;
    while (exponent)
    {
        if (exponent%2==0)
        {
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else
        {
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}


int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;

        vi a;
        set<ll>st;
        st.insert(0);
        ll j=-1;
        ll t;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);    
            st.insert(x);
            if(x!=1 && x!=-1){
                t=x;
                j=i;
            }

        }
        vi pre;
        pre.pb(a[0]);
        for(ll i=1; i<n; i++){
            pre.pb(a[i]+pre[i-1]);
            st.insert(pre[i]);
        }

        // cout<<'k'<<' ';
        // for(auto i:st)
        //     cout<<i<<' ';
        
        if(j!=-1){
            ll curr=1;
            bool k=false;
            vector<pair<ll,ll>>vb;
            for(ll i=0; i<j; i++){
                if(a[i]==a[i+1]){
                    curr++;
                    if(i==n-1){
                        vb.pb({a[i],curr});
                    }
                }
                else{
                    vb.pb({a[i],curr});
                    curr=1;
                }
            }

            

            curr=1;
            vector<pair<ll,ll>>cc;
            vector<pair<ll,ll>>dd=vb;
            for(ll i=j+2; i<n; i++){
                if(a[i]==a[i-1]){
                    curr++;
                    if(i==n-1){
                        cc.pb({a[i],curr});
                        vb.pb({a[i],curr});
                    }
                }
                else{
                    cc.pb({a[i-1],curr});
                    vb.pb({a[i-1],curr});
                    curr=1;
                    if(i==n-1){
                     cc.pb({a[i],curr});   
                     vb.pb({a[i],curr});   
                    }
                }
            }
            if(j==n-2){
                cc.pb({a[n-1],1});
                vb.pb({a[n-1],1});
            }

            for(auto i:vb){
                ll v1=i.first,v2=i.second;
                ll cn=v1;
                for(ll k=0; k<v2; k++){
                    st.insert(cn);
                    cn+=v1;
                }
            }

            for(auto i:cc){
                ll v1=i.first,v2=i.second;
                ll cn=v1;
                for(ll k=0; k<v2; k++){
                    st.insert(cn);
                    cn+=v1;
                }
            }
            ll m=t;
            for(ll i=j-1; i>=0; i--){
                m+=a[i];
                st.insert(m);
            }

            m=t;
            for(ll i=j+1; i<n; i++){
                m+=a[i];
                st.insert(m);
            }
            
        }

        else{
            ll curr=1;
            vector<pair<ll,ll>>vb;
            for(ll i=1; i<n; i++){
                if(a[i]==a[i-1]){
                    curr++;
                    if(i==n-1){
                        vb.pb({a[i],curr});
                    }
                }
                else{
                    vb.pb({a[i],curr});
                    curr=1;
                }
                // if(i==n-1)
            }

            for(auto i:vb){
                ll c1=i.first,c2=i.second;
                ll cc=i.first;
                for(ll h=0; h<c2; h++){
                    st.insert(cc);
                    cc+=c1;
                }
            }

        }

        cout<<st.size()<<endl;
        for(auto i:st){
            cout<<i<<' ';
        }
        cout<<endl;


    }
    return 0;
}