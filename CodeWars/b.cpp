// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>
// #define vvp vector<pair<ll,ll>>
// #define vvt vector<tuple<ll,ll,ll>>
// #define YES cout<<'Y'<<'E'<<'S'<<endl
// #define NO cout<<'N'<<'O'<<endl

// const ll mod = 1e9+7;

// class Disjoint{
//     vector<ll>size,rank,parent;
// public:
//     Disjoint(ll n){
//         size.resize(n+1,1);
//         parent.resize(n+1);
//         rank.resize(n+1,0);
//         for(ll i=0; i<=n; i++)
//             parent[i]=i;
//     }
//     ll findParent(ll node){
//         if(node==parent[node])
//             return node;
//         return parent[node]=(findParent(parent[node]));
//     }
//     void unionByRank(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u]<rank[ulp_v]){
//             parent[ulp_u]=ulp_v;
//         }
//         else if(rank[ulp_u]>rank[ulp_v]){
//             parent[ulp_v]=ulp_u;
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             rank[ulp_u]++;
//         }
//     }
//     void unionBySize(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(size[ulp_u]<size[ulp_v]){
//             parent[ulp_u]=ulp_v;
//             size[ulp_v]+=size[ulp_u];
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             size[ulp_u]+=size[ulp_v];
//         }
//     }
// };
// ll mAdd(ll a, ll b, ll m = mod){
//     a = a % m;
//     b = b % m;
//     return (((a + b) % m) + m) % m;
// }
// ll mSub(ll a, ll b, ll m = mod){
//     a = a % m;
//     b = b % m;
//     return (((a - b) % m) + m) % m;
// }
// ll mul (ll a, ll b, ll m=mod){
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll LCM(ll a, ll b){

//     a = (a*b)/(__gcd(a,b));
//     return a;
// }
// bool customComparator(const pair<int, int> &a, const pair<int, int> &b){
//     return a.second < b.second;
// }
// ll power(ll base, ll exponent){
//     if (exponent < 0){
//         return 0;
//     }
//     ll ans = 1;
//     while (exponent){
//         if (exponent%2==0){
//             base = (base*base) % mod;
//             exponent = exponent/2;
//         }
//         else{
//             ans = (ans*base) % mod;
//             exponent--;
//         }
//     }
//     return ans;
// }
// ll invmod(ll a, ll m = mod){
//     return power(a, m - 2);
// }
// ll div(ll a, ll b, ll m = mod){
//     a = a % m;
//     b = b % m;
//     return mul(a, invmod(b, m), m);
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr); std::cout.tie(nullptr);

//     ll tt=1;
//     // cin>>tt;
//     while (tt--)
//     {
//         ll n;
//         cin>>n;
//         if(n==1){
//             cout<<1<<endl;
//             continue;
//         }
//         if(n==2){
//             cout<<"1 2"<<endl;
//             continue;
//         }
//         ll k=n-3;
//         vi a(k);
//         for(ll i=1; i<=n; i++){
//             a[i]=i;
//         }
//         while(a.size() != n){
//             vi v;
//             v.pb(1);
//             for(ll i=1; i<a.size(); i++){
//                 v.pb(a.back()+a[i]);
//             }
//             a=v;
//         }

//         for(auto i:a)
//             cout<<i<<' ';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define sorti(v) sort(all(v))
#define rsorti(v) sort(v.rbegin(), v.rend())
#define MAXI(a) (*std::max_element((a).begin(), (a).end()))
#define MINI(a) (*std::min_element((a).begin(), (a).end()))
#define pp pair<int, int>
#define ff first
#define ss second
#define cy cout << "Yes" << endl
#define cn cout << "No" << endl

#define int long long
#define ll long long
#define ld long double
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pb push_back
#define ppb pop_back
#define cinall(a)     \
    for (auto &i : a) \
    cin >> i
#define coutall(a)        \
    for (auto i : a)      \
        cout << i << " "; \
    cout << endl
#define gcd __gcd
ll binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(ll a) { return bitset<64>(a).to_string(); }

const ll mod = 1e18;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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
ll mMul(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

ll power(ll a, ll b, ll m = mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = mMul(a, a);
        b = b >> 1;
    }
    return res;
}

ll invmod(ll a, ll m = mod) { return power(a, m - 2, m); } // For prime mod

ll mDiv(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return mMul(a, invmod(b, m), m);
}

const int N = 4'000'10;

int factorial[N], invFactorial[N];
// its same as power fn written above
int bin_pow_mod(int a, int p)
{
    // if mod is prime then to reduce complexity can use p = p % (mod - 1)  -- from FLT(Fermat's Little Theorem)
    //  p = p % (mod - 1);

    int result = 1;
    while (p)
    {
        if (p & 1)
            result = 1LL * a * result % mod;
        a = 1LL * a * a % mod;
        p >>= 1;
    }
    return result;
}

ll C(ll n, ll r)
{
    if (r > n || r < 0)
    {
        return 0;
    }
    return mMul(factorial[n], mMul(invFactorial[r], invFactorial[n - r]));
}

vector<ll> get_max3(vector<ll> a)
{
    ll mx1 = -1, mx2 = -1, mx3 = -1;
    ll n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (mx1 == -1 || a[i] > a[mx1])
        {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        }
        else if (mx2 == -1 || a[i] > a[mx2])
        {
            mx3 = mx2;
            mx2 = i;
        }
        else if (mx3 == -1 || a[i] > a[mx3])
        {
            mx3 = i;
        }
    }

    vector<ll> ret;
    ret.push_back(mx1);
    ret.push_back(mx2);
    ret.push_back(mx3);

    return ret;
}

// void prencr(){
//     factorial[0] = 1;
//     for(int i = 1; i < N; i++) factorial[i] = 1ll * factorial[i - 1] * i % mod;
//     invFactorial[N - 1] = bin_pow_mod(factorial[N - 1], mod - 2);
//     for(int i = N - 2; i >= 0; i--) invFactorial[i] = 1ll * invFactorial[i + 1] * (i + 1) % mod;
// }

//-----------------------------------Let's get Started--------------------------------

int defi(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // prenCr();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 1 << " " << 2 << endl;
            continue;
        }
        if (n == 3)
        {
            cout << 1 << " " << 2 << " " << 4 << endl;
            continue;
        }
        if (n == 4)
        {
            cout << 1 << " " << 2 << " " << 4 << " " << 8 << endl;
            continue;
        }

        vl vec(n - 3);
        for (int i = 0; i < n - 3; i++)
        {
            vec[i] = i + 1;
        }

        vl vec1(n - 2);
        vec1[0] = 1;
        for (int i = 0; i < n - 3; i++)
        {
            vec1[i + 1] = vec1[i] + vec[i];
        }

        vl vec2(n - 1);
        vec2[0] = 1;
        for (int i = 0; i < n - 2; i++)
        {
            vec2[i + 1] = vec2[i] + vec1[i];
        }

        vl vec3(n);
        vec3[0] = 1;
        for (int i = 0; i < n - 1; i++)
        {
            vec3[i + 1] = vec3[i] + vec2[i];
        }

        for (auto i : vec3)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
12
18
196
1975581
958900
38416403456028


*/