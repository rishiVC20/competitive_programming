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

void postOrder(ll node, vector<vector<ll>> &mp, vector<bool> &visited, vi &arr)
{
    visited[node] = true;
    for (ll child : mp[node]){
        if (!visited[child]){
            postOrder(child,mp,visited,arr);
        }
    }

    arr.pb(node+1);
}

int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vi a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }       
        vector<vector<ll>>mp(n);
        for (ll i=0; i<n-1; i++){
            ll u,v;
            cin>>u>>v;
            u--, v--;
            mp[u].pb(v);
            mp[v].pb(u);
        }
        vector<bool>visited(n,false);
        ll mini = INT_MAX;
        ll idx = -1;
        for (ll i=0; i<n; i++){
            if (a[i] < mini){
                mini = a[i];
                idx = i;
            }
        }
        vi arr;
        postOrder(idx, mp, visited, arr);

        arr.pop_back();
        cout<<arr.size()<<endl;
        for (auto i:arr){
            cout<<i<<' ';
        }
        cout<<endl;

    }
    return 0;
}