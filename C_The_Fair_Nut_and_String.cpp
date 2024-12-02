// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout << 'Y' << 'E' << 'S' << endl
#define NO cout << 'N' << 'O' << endl

const ll mod = 1e9 + 7;

class Disjoint
{
    vector<ll> size, rank, parent;

public:
    Disjoint(ll n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (ll i = 0; i <= n; i++)
            parent[i] = i;
    }
    ll findParent(ll node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = (findParent(parent[node]));
    }
    void unionByRank(ll u, ll v)
    {
        ll ulp_u = findParent(u);
        ll ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(ll u, ll v)
    {
        ll ulp_u = findParent(u);
        ll ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
ll mul(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{

    a = (a * b) / (__gcd(a, b));
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
        if (exponent % 2 == 0)
        {
            base = (base * base) % mod;
            exponent = exponent / 2;
        }
        else
        {
            ans = (ans * base) % mod;
            exponent--;
        }
    }
    return ans;
}

int main()
{
    ll tt = 1;
    // cin>>tt;
    while (tt--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        vi k;

        ll cn = 0, maxi = 0;
        bool f = false;
        for (ll i = 0; i < n; i++){
            ll p=s[i]-'a';

            if(p>1)
                continue;

            if(p==0)
                cn++;
            if(p==1 && cn>0){
                k.pb(cn);
                cn=0;
            }  
            cn=cn%mod;      
        }
        if(cn>0){
            k.pb(cn);
        }

        vi v=k;
        for(ll i=1; i<v.size(); i++){
            v[i]+=v[i-1];
        }
        ll m=k[0];
        vi d(v.size());
        if(v.size()>0){
            d[0]=k[0];
        }
        if(v.size()>1){
            d[1]=(k[0]+1)*k[1];
            m*=k[1];
            m=m%mod;
        }
        for(ll i=2; i<k.size(); i++){
            d[i]=(((v[i-1]%mod)+(m%mod)+1LL)*(k[i]%mod)%mod);
            m=(ll)(m*k[i]);
            m=m%mod;
        }
        ll sum=0;
        for(ll i=0; i<d.size(); i++){
            sum += d[i];
            sum=(ll)sum%mod;
        }
        // for(auto i:d)
        //     cout<<i<<' ';
        // cout<<endl;

        cout << sum % mod << endl;
    }
    return 0;
}