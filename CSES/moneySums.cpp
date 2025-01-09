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

void solve(ll ind, vi &a)
{

}

int main()
{
    ll tt = 1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin >> n;

        vi a;
        set<ll>st;
        
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.pb(x);
            st.insert(x);
        }

        ll cn=accumulate(a.begin(),a.end(),0LL);
        vi dp(cn+1,0);

        sort(a.begin(),a.end());

        dp[0]=1;

        for(ll i=0; i<n; i++){
            for(ll j=cn; j>=0; j--){
                if(j-a[i] >= 0){
                    // cout<<j<<' '<<a[i]<<' ';
                    dp[j]=(dp[j-a[i]]==1)?1:dp[j];
                    // cout<<dp[j]<<endl;
                }
            }
        }

        // cout<<endl;
        

        // for(auto i:dp)
        //     cout<<i<<' ';
        // cout<<endl;    

        ll sum=0;
        for(ll i=1; i<=cn; i++){
            if(dp[i])
                sum++;

        }
        cout<<sum<<endl;

        for(ll i=1; i<=cn; i++){
            if(dp[i])
                cout<<i<<' ';
        }

        cout<<endl;

        // for(ll i=0; i<n; i++){
        //     ll cn=a[i];
        //     for(ll j=i+1; j<n; j++){
        //         ll p=a[i]+a[j];
        //         // cout<<cn<<' ';
        //         cn+=a[j];
        //         st.insert(cn);
        //         st.insert(p);
        //     }
        // }
        // cout<<endl;

        // cout<<st.size()<<endl;

        // for(auto i:st)
        //     cout<<i<<' ';
    }
    return 0;
}