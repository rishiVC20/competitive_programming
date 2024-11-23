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
        string s;
        cin>>s;
        ll q;
        cin>>q;
        vector<pair<ll,ll>>v;
        for(ll i=0; i<q; i++){
            ll x,y;
            cin>>x>>y;
            v.pb({x,y});
        }  
        ll n=s.size();     
        if(n < 4){
            for(ll i=0; i<q; i++)
                NO;
            continue;    
        }
        set<ll>st;
        string g="1100";
        for(ll i=0; i<=n-4; i++){
            string p=s.substr(i,4);
            if(p==g){
                st.insert(i);
            }
        }
        // for(auto i:st)
        //     cout<<i<<' ';
        if(st.size() > 1){
            for(ll i=0; i<q; i++)
                YES;
            continue;    
        }
        for(ll i=0; i<q; i++){
            ll p=v[i].first-1, z=v[i].second;
            // s[p]=z;
            if(st.size()>1){
                YES;
                continue;
            }
            if(s[p] == z+'0' && st.size()>=1){
                YES;
                s[p]=z+'0';
                continue;
            }
            if(s[p]==z+'0' && st.size()==0){
                NO;
                s[p]=z+'0';
                continue;
            }
            // cout<<'h'<<' ';
            if(st.size() == 1){
                if(st.find(p-3) != st.end() || st.find(p-2) != st.end() || st.find(p-1) != st.end() || st.find(p)!=st.end()){
                    NO;
                    st.clear();
                }
                else{
                    YES;
                }
                s[p] = z+'0';
                continue;
            }
            else{
                if(z==0){
                    if(p-2>=0 && p+1<n){
                        string m=s.substr(p-2,4);
                        m[2]='0';
                        if(g==m){
                            YES;
                            s[p]='0';
                            continue;
                        }
                            
                    }
                    if(p-3>=0 && p<n){
                        string m=s.substr(p-3,4);
                        // cout<<m<<' ';
                        m[3]='0';
                        // cout<<m<<' ';
                        if(g==m){
                            YES;
                            s[p]='0';
                            continue;
                        }
                    }
                    s[p]='0';
                    if(p-2>=0 && p+1<n){
                        string m=s.substr(p-2,4);
                        if(g==m){
                            st.insert(p-2);
                        }
                            
                    }
                    if(p-3>=0 && p<n){
                        string m=s.substr(p-3,4);
                        if(g==m){
                            st.insert(p-3);
                        }
                    }
                }
                if(z==1){
                    if(p-1>=0 && p+2<n){
                        string m=s.substr(p-1,4);
                        m[1]='1';
                        if(g==m){
                            YES;
                            s[p]='1';
                            continue;
                        }
                    }
                    if(p+3<n){
                        string m=s.substr(p,4);
                        m[0]='1';
                        if(g==m){
                            YES;
                            s[p]='1';
                            continue;
                        }
                    }
                    s[p]='1';
                    if(p-1>=0 && p+2<n){
                        string m=s.substr(p-1,4);
                        if(g==m){
                            st.insert(p-1);
                        }
                            
                    }
                    if(p+3<n){
                        string m=s.substr(p,4);
                        if(g==m){
                            st.insert(p);
                        }
                    }
                }
                NO;
            }
            // if(st.size() == 1){
            //     if(st.find(p-3) != st.end() || st.find(p-2) != st.end() || st.find(p-1) != st.end() || st.find(p)!=st.end())
            //         NO;
            //     else
            //         YES;
            //     s[p]='0'+z;    
            // }
            // else{
            //     if(z==0){
            //         if(p-2>=0 && p+1<n){
            //             string m=s.substr(p-2,4);
            //             m[2]='0';
            //             if(g==m){
            //                 YES;
            //                 continue;
            //             }
                            
            //         }
            //         if(p-3>=0 && p<n){
            //             string m=s.substr(p-3,4);
            //             cout<<m<<' ';
            //             m[3]='0';
            //             cout<<m<<' ';
            //             if(g==m){
            //                 YES;
            //                 continue;
            //             }
            //         }
            //         s[p]='0';
            //     }
            //     if(z==1){
            //         cout<<'k'<<' ';
            //         if(p-1>=0 && p+2<n){
            //             string m=s.substr(p-1,4);
            //             m[1]='1';
            //             if(g==m){
            //                 YES;
            //                 continue;
            //             }
            //         }
            //         if(p+3<n){
            //             string m=s.substr(p,4);
            //             m[0]='1';
            //             if(g==m){
            //                 YES;
            //                 continue;
            //             }
            //         }
            //         s[p]='1';
            //     }
                
            //     NO;

            // }       
        }   

    }
    return 0;
}