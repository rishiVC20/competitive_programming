// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll, ll>>
#define vvt vector<tuple<ll, ll, ll>>
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
ll mAdd(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mSub(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
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
ll invmod(ll a, ll m = mod)
{
    return power(a, m - 2);
}
ll div(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return mul(a, invmod(b, m), m);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll tt = 1;
    // cin>>tt;
    while (tt--)
    {
        ll n, k;
        cin >> n >> k;

        vi a(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vi pre(n + 1);
        pre[0] = 0;
        pre[1] = a[1];
        for (ll i = 2; i <= n; i++)
        {
            pre[i] = pre[i - 1] + a[i];
        }

        vector<pair<ll, ll>> c(n + 1), d(n + 1);
        ll maxi1 = LLONG_MIN;
        ll j = -1;
        for (ll i = k; i <= n; i++)
        {
            ll p = 0;
            if (i == k)
            {
                p = pre[i];
            }
            else
            {
                p = pre[i] - pre[i - k];
            }
            if (p > maxi1)
            {
                j = i - k + 1;
                maxi1 = p;
                c[i].first = maxi1;
                c[i].second = j;
                continue;
            }
            c[i].first = maxi1, c[i].second = j;
        }
        ll maxi2 = LLONG_MIN, h = -1;
        for (ll i = n - k + 1; i >= 1; i--)
        {
            // maxi2=max(maxi2,a[i]);
            // d[i]=maxi2;
            ll p = 0;
            // if(i==1){
            //     p=pre[i+k-1];
            // }
            // else{
            //     p=pre[i+k-1]-pre[i-1];
            // }
            p = pre[i + k - 1] - pre[i - 1];
            if (p >= maxi2)
            {
                maxi2 = p;
                h = i;
                d[i].first = maxi2;
                d[i].second = h;
                continue;
            }
            d[i].second = h, d[i].first = maxi2;
        }
        // cout<<d.size()<<endl;
        // for(auto i:c){
        //     cout<<i.first<<' '<<i.second<<" ";
        // }
        // cout<<endl;
        // for(auto i:d){
        //     cout<<i.first<<' '<<i.second<<' ';
        // }
        // cout<<endl;

        ll cn = 0;
        pair<ll, ll> g = {n - 1, n - 1};
        for (ll i = 1; i <= n - k + 1; i++)
        {
            ll ch = pre[i + k - 1] - pre[i - 1];
            ll u = 0, v = 0;
            ll x = 0, y = 0;
            if (i > k)
            {
                u = c[i - 1].first;
                x = c[i - 1].second;
            }
            if (i + k <= n - k + 1)
            {
                v = d[i + k].first;
                y = d[i + k].second;
            }
            ll t = max(u, v);
            ch += t;
            // if(ch==cn){
            //     if(u>0){
            //         g.first=x;
            //         g.second=i;
            //     }
            //     else if(v>0){
            //         g.first=i;
            //         g.second=y;
            //     }
            // }
            // cout<<v<<' '<<y<<' ';
            if (ch > cn)
            {
                cn = ch;

                if (u >= v)
                {
                    // if(g.first > (i-k-1)){
                    g.first = x;
                    g.second = i;
                }
                else if (u < v)
                {
                    g.first = i;
                    g.second = y;
                }
            }
            // cout<<g.first<<' '<<g.second<<' ';
        }
        // cout<<endl;

        cout << g.first << ' ' << g.second << endl;
    }
    return 0;
}