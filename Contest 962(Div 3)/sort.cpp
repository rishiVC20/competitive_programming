// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>
// #define YES cout<<'Y'<<'E'<<'S'<<endl
// #define NO cout<<'N'<<'O'<<endl  

// const ll mod = 1e9+7;

// ll mul (ll a, ll b, ll m=mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll LCM(ll a, ll b)
// {
    
//     a = (a*b)/(__gcd(a,b));
//     return a;
// }
// bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
// {
//     return a.second < b.second;
// }
// ll power(ll base, ll exponent)
// {
//     if (exponent < 0)
//     {
//         return 0;
//     }
//     ll ans = 1;
//     while (exponent)
//     {
//         if (exponent%2==0)
//         {
//             base = (base*base) % mod;
//             exponent = exponent/2;
//         }
//         else
//         {
//             ans = (ans*base) % mod;
//             exponent--;
//         }
//     }
//     return ans;
// }

// ll calculate(string k1,string k2, ll l, ll r){
//     vi a(26,0);
//     vi b(26,0);
//     ll s = 0;
//     ll n = k1.size();
//     for (ll i=l; i<=r; i++){
//         ll x=k1[i]-'a';
//         ll y=k2[i]-'a';
//         // cout<<x<<' '<<y<<' ';
//         a[x]++;
//         b[y]++;
//     }
//     for (ll i=0; i<26; i++){
//         s += abs(a[i]-b[i]);
//     }

//     return s;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,q;
//         cin>>n>>q;
//         string a,b;
//         cin>>a>>b;
//         vector<string>c,d;
//         for (ll i=0; i<q; i++){
//             ll x,y; 
//             cin>>x>>y;
//             x--;
//             y--;
//             ll p = (y-x+1);
//             // string k1 = a.substr(x-1,p);
//             // string k2 = b.substr(x-1,p);
//             // c.pb(k1);
//             // d.pb(k2);
//             ll maxi = calculate(a,b,x,y);
//             cout<<(maxi/2)<<endl;
//         }
//     }
//     return 0;
// }


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


int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,q;
        cin>>n>>q;
        string s,t;
        cin>>s>>t;
        vector<vector<ll>>a(n+1,vector<ll>(26,0));
        vector<vector<ll>>b(n+1,vector<ll>(26,0));
        vi c(26,0);
        vi d(26,0);
        for (ll i=1; i<=n; i++){
            c[s[i-1]-'a']++;
            d[t[i-1]-'a']++;
            for (ll j=0; j<26; j++){
                a[i][j] = a[i-1][j];
                b[i][j] = b[i-1][j];
            }
            a[i][s[i-1]-'a'] = c[s[i-1]-'a'];
            b[i][t[i-1]-'a'] = d[t[i-1]-'a'];
        }
        for (ll i=0; i<q; i++){
            ll l,r;
            cin>>l>>r;
            ll sum = 0;
            for (ll j=0; j<26; j++){
                if (a[r][j]-a[l-1][j] != b[r][j]-b[l-1][j]){
                    sum += abs((a[r][j]-a[l-1][j]) - (b[r][j]-b[l-1][j]));
                }
            }
            cout<<sum/2<<endl;
        }
    }
    return 0;
}