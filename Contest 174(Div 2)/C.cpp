// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll, ll>>
#define vvt vector<tuple<ll, ll, ll>>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define YES cout << 'Y' << 'E' << 'S' << endl
#define NO cout << 'N' << 'O' << endl

const ll mod = 998244353;

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

    ll tt;
    cin >> tt;
    while (tt--)
    {
        ll n;
        cin >> n;
        vi a;
        vi v1;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.pb(x);
        }
        ll cp = 0;
        for (ll i = 0; i < n; i++)
        {
            cp += (a[i] == 1);
            v1.pb(cp);
        }
        vi v2;
        cp = 0;
        for (ll i = n - 1; i >= 0; i--)
        {
            cp += (a[i] == 3);
            v2.pb(cp);
        }
        reverse(v2.begin(), v2.end());

        ll m = 0;
        vi v3(n);
        // if(a[0]==2){
        //     v3[0]=1;
        //     m=1;
        // }
        ll cn = 0;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] == 2)
            {
                m++;
            }
            // else{
            //     m=0;
            // }
            v3[i] = m;
        }

        for (ll i = 0; i < n; i++)
        {
            if (a[i] == 2)
            {
                ll k = v1[i];
                ll p = v2[i];
                ll q = v3[i];
                if (k == 0 || p == 0)
                    continue;
                cout << k << ' ' << p << ' ' << q << ' ';
                ll t = (k * p) % mod;
                cn = (cn + t) % mod;
                cn = (cn + q - 1) % mod;
            }
        }

        cout << cn << endl;
    }
    return 0;
}