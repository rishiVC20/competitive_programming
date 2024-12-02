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
        ll n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        vector<vector<ll>>v(k,vector<ll>(26,0));

        for(ll i=0; i<n; i++){
            ll p=s[i]-'a';
            v[i%k][p]++;
        }       
        // for(ll i=0; i<k; i++){
        //     for(ll j=0; j<26; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        ll i=0,j=k-1;
        ll cn=0;
        while(i<=j){
            if(i!=j){
                for(ll m=0; m<26; m++){
                    v[i][m]+=v[j][m];
                }
                ll cp1=0,cp2=0;
                ll maxi1=0,maxi2=0;
                for(ll m=0; m<26; m++){
                    cp1 += v[i][m];
                    maxi1=max(maxi1,v[i][m]);
                }
                // cout<<cp1<<" "<<cp2<<endl;
                cn += (cp1-maxi1);
                // for(ll m=0; m<26; m++){
                //     cp2 += v[j][m];
                //     maxi2=max(maxi2,v[j][m]);
                // }
                // cn += (cp1+cp2-maxi1);
            }
            else{
                ll maxi=0,cp=0;
                for(ll m=0; m<26; m++){
                    cp+=v[i][m];
                    maxi=max(maxi,v[i][m]);
                }
                cn += (cp-maxi);
            }
            i++,j--;
        }
        // cout<<endl;
        cout<<cn<<endl;


    }
    return 0;
}