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

// ll solve(vi &a, ll n, ll req, ll sum, ll i,  vector<vi> &dp){
//     if(i>=n || sum>req){
//         return 0;
//     }
//     if(sum==req)
//         return 1;
//     if(dp[i][sum] != -1)
//         return dp[i][sum];

//     ll take=solve(a,n,req,sum+a[i],i,dp)%mod;
//     ll nextake=solve(a,n,req,sum+a[i],i+1,dp)%mod;
//     ll notake=solve(a,n,req,sum,i+1,dp)%mod;
//     // return take+notake+nextake;
//     return dp[i][sum]=(take+notake+nextake)%mod;
// }
ll solve1(vi &a, ll n,  ll sum, ll i, vector<vi> &dp){
    if (i >= n ){
        return 0;
    }
    if (sum == 0)
        return 1;
    if (dp[i][sum] != -1)
        return dp[i][sum];

    ll take = solve1(a, n,sum - a[i], i, dp) % mod;
    // ll nextake = solve1(a, n,  sum + a[i], i + 1, dp) % mod;
    ll notake = solve1(a, n, sum, i + 1, dp) % mod;
    // return take+notake+nextake;
    // cout<<i<<"h "<<take<<" "<<notake<<endl;
    return dp[i][sum]= (take + notake ) % mod;
}

int main()
{
    ll tt = 1;
    // cin>>tt;
    while (tt--)
    {
        ll n, s;
        cin >> n >> s;
        vi a;
        for (ll i = 0; i < n; i++){
            ll x;
            cin >> x;
            a.pb(x);
        }
        // sort(a.begin(),a.end());
        // cout<< solve(a,n,s,0,0)<<endl;;
        vector<vi> dp(n + 1, vi(s + 1, -1));
        // vi dp(n + 1, -1);
        // solve(a,n,s,0,0,dp);

        ll p = 0;
        // for (ll i = 0; i < n; i++)
        // {
            ll k = (solve1(a, n, 0, s, dp)) % mod;
            cout << k <<endl;
            p += k;
        // }
        // for(auto i:dp){
        //     for(auto j:i)
        //         cout<<j<<' ';
        //     cout<<endl;
        // }
        // cout << p << endl;
        // dp[0]=1;
        // for(ll i=1; i<s+1; i++){
        //     for(ll j=0; j<n; j++){
        //         if(i>=a[j])
        //             dp[i]=(dp[i]+dp[i-a[j]])%mod;
        //     }
        // }

        // cout<<dp[s]<<endl;
    }
    return 0;
}