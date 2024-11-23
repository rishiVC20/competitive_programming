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
// ll solve1(vi &a, ll n, ll req, ll sum, ll i, vector<vi> &dp)
// {
//     if (i >= n || sum > req)
//     {
//         return 0;
//     }
//     if (sum == req)
//         return 1;
//     if (dp[i][sum] != -1)
//         return dp[i][sum];

//     ll take = solve1(a, n, req, sum + a[i], i, dp) % mod;
//     // ll nextake = solve1(a, n, req, sum + a[i], i + 1, dp) % mod;
//     ll notake = solve1(a, n, req, sum, i + 1, dp) % mod;
//     // return take+notake+nextake;
//     // cout<<i<<"h "<<take<<" "<<notake<<endl;
//     return dp[i][sum]= (take + notake ) % mod;
// }

int main()
{
    ll tt = 1;
    // cin>>tt;
    while (tt--)
    {
        ll n, s;
        cin >> n >> s;
        vi a;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.pb(x);
        }
        vector<vi>dp(n+1, vi(s+1));

        //dp[i][k]=dp[i+1][k]+dp[i][k-ci]
        for(ll i=0; i<=n; i++)
            dp[i][0]=1;
        for(ll i=n-1; i>=0; i--){
            for(ll j=1; j<=s; j++){
                // if(j==0){
                //     dp[i][0]=1;
                //     continue;
                // }
                ll pick=0;
                if(j >= a[i])
                    pick=(dp[i][j-a[i]])%mod;
                ll nopick=(i+1<=n)?dp[i+1][j]%mod:0;
                dp[i][j]=(pick+nopick)%mod;
            }
        }
        // dp[i][s]->no. of ways to get sum of s s.t. all coins from i to n are pickable and coins before i are skipped
        // dp[0][s]->no. of ways to get sum of s s.t. all coins from 0 to n are pickable and coins before 0 are skipped
        cout<<dp[0][s]<<endl;

        // for(auto i:dp){
        //     for(auto j:i)
        //         cout<<j<<' ';
        //     cout<<endl;    
        // }
    }
    return 0;
}