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

        string s;
        cin>>s;
        if(n==1){
            cout<<s<<endl;
            continue;
        }
        vi a(26);
        for(ll i=0; i<n; i++){
            ll k=s[i]-'a';
            a[k]++;
        }       

        ll mini=INT_MAX,maxi=INT_MIN;
        ll p=-1,q=-1;
        for(ll i=0; i<26; i++){
            if(a[i]!=0){
                // mini=min(mini,a[i]);
                // maxi=max(maxi,a[i]);
                if(a[i] < mini){
                    mini=a[i];
                    p=i;
                }
                if(a[i]>maxi){  
                    maxi=a[i];
                    q=i;
                }
            }
        }

        if(mini==maxi){
            bool f=false;
            for(ll i=1; i<n; i++){
                if(s[i]!=s[i-1]){
                    f=true;
                    s[i]=s[i-1];
                    break;
                }
            }

            cout<<s<<endl;
            continue;
        }
        // cout<<p<<' '<<q<<' ';
        ll x,y;
        for(ll i=0; i<n; i++){
            ll c=s[i]-'a';
            if(a[c]==maxi){
                y=i;
                break;
            }
        }
        for(ll i=0; i<n; i++){
            ll c=s[i]-'a';
            if(a[c]==mini){
                x=i;
                break;
            }
        }

        s[x]=s[y];

        cout<<s<<endl;
    }
    return 0;
}