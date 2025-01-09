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

        vector<int> vec(n);
        vec[0] = 1;
        if (n >= 2)
            vec[1] = 1;
        // for(int i=2;i<n;i++){
        //     int a = vec[i-2];
        //     int b = vec[i-1];

        //     int num = a+b;
        //     // if(num > 10){
        //     //     int ans = num%10;
        //     //     num = num/10;
        //     //     ans += num;

        //     //     vec[i] = ans;
        //     // }
        //     // else{
        //     //     vec[i] = num;
        //     // }
        // }

        for (int i = 2; i < n; i++)
        {
            int a = vec[i - 2];
            int b = vec[i - 1];

            vec[i] = a + b;
        }

        for (int i = 2; i < n; i++)
        {
            int num = vec[i];

            int ans = 0;
            while (num != 0)
            {
                ans += num % 10;
                num = num / 10;
            }

            vec[i] = ans;
        }

        for (auto i : vec)
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