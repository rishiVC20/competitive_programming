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

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

bool func(ll i, ll j, vector<vector<char>> &v)
{
    for (ll k = 0; k < 4; k++)
    {
        ll l = i + dx[k], r = j + dy[k];
        if (l >= 0 && r >= 0 && l < v.size() && r < v[0].size())
        {
            if (v[l][r] == 'G')
                return false;
            if (v[l][r] == '.')
                v[l][r] = '#';
        }
    }

    return true;
}

void solve(vector<vector<bool>> &vis, vector<vector<char>> &v, ll i, ll j)
{
    queue<pair<ll, ll>> q;
    q.push({i, j});
    // vector<vector<bool>>
    vis[i][j] = true;
    while (!q.empty())
    {
        ll l = q.front().first;
        ll r = q.front().second;
        q.pop();
        // vis[l][r]=true;
        // if(l==v.size()-1 && r==v[0].size()-1 && v[l][r]=='.')
        //     return true;
        for (ll k = 0; k < 4; k++)
        {
            ll u = l + dx[k], w = r + dy[k];
            if (u >= 0 && w >= 0 && u < v.size() && w < v[0].size())
            {
                if ((v[u][w] == 'G' || v[u][w] == '.') && (vis[u][w] == false))
                {
                    q.push({u, w});
                    vis[u][w] = true;
                }
            }
        }
    }
    // return false;
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
        ll n, m;
        cin >> n >> m;
        vector<vector<char>> v(n, vector<char>(m));

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }

        // if(n==1 && m==1){
        //     YES;
        //     continue;
        // }

        bool f = true;
        vvp t;
        ll cp = 0;
        ll q = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (v[i][j] == 'B')
                {
                    q++;
                    if (!func(i, j, v))
                    {
                        f = false;
                        break;
                    }
                }
                if (v[i][j] == 'G')
                {
                    t.pb({i, j});
                }

                cp += (v[i][j] == 'G');
            }
            if (!f)
                break;
        }

        if (!f || (cp > 0 && v[n - 1][m - 1] == '#'))
        {
            NO;
            continue;
        }
        if (cp == 0)
        {
            YES;
            continue;
        }
        // for(auto i:v){
        //     for(auto j:i){
        //         cout<<j;
        //     }
        //     cout<<endl;
        // }
        // cout<<"hi ";
        // YES;

        bool r = true;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        solve(vis, v, n - 1, m - 1);
        for (ll i = 0; i < t.size(); i++)
        {
            // cout<<t[i].first<<' '<<t[i].second<<' ';
            if (!vis[t[i].first][t[i].second])
            {
                r = false;
                break;
            }
        }
        if (r)
            YES;
        else
            NO;
    }
    return 0;
}


// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
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
ll mAdd(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mSub(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mul (ll a, ll b, ll m=mod){
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b){
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
ll power(ll base, ll exponent){
    if (exponent < 0){
        return 0;
    }
    ll ans = 1;
    while (exponent){
        if (exponent%2==0){
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else{
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}
ll invmod(ll a, ll m = mod){
    return power(a, m - 2);
}
ll div(ll a, ll b, ll m = mod){
    a = a % m;
    b = b % m;
    return mul(a, invmod(b, m), m);
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        
    }
    return 0;
}