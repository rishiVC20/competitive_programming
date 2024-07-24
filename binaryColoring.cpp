// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll>

// const ll mod = 1e9+7;

// ll mul (ll a, ll b, ll m=mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
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

// bool check(vi &a, ll j)
// {
//     for (ll i=0; i<a.size(); i++)
//     {
//         if (a[i] == j)
//             return true;
//     }

//     return false;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;

//         vi a;
//         bool f=true;
//         bool g = false;
//         if (n%2){
//             n++;
//             g = true;
//         }
//         ll v = log2(n);
//         while (n){
//             ll p = log2(n);
//             // cout<<p<<" ";
//             if (p > 0 )
//                 a.pb(p);
//             // if (n==1)
//             //     break;
//             n -= pow(2,p);
//             // cout<<n<<" ";

//         }
//         while (a.size() <= v){
//             a.pb(0);
//         }

//         if (g)
//             a.pb(-1);
//         else
//             a.pb(0);

//         cout<<v+1<<endl;
//         // for (ll i=a.size()-1; i>=0; i--)
//         // {
//         //     cout<<a[i]<<" ";
//         // }

//         cout<<a[a.size()-1]<<" ";
//         for (ll i=1; i<=v; i++)
//         {
//             if (check(a,i)){
//                 cout<<1<<" ";
//             }
//             else{
//                 cout<<0<<" ";
//             }
//         }

//         // cout<<endl;

//         cout<<endl;
//     }

//     return 0;
// }

// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>

const ll mod = 1e9 + 7;

ll mul(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
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

bool check(vi &a, ll j)
{
    for (ll i = 0; i < a.size(); i++)
    {
        if (a[i] == j)
            return true;
    }
}
    int main()
    {
        ll t;
        cin >> t;
        while (t--)
        {
            ll n;
            cin >> n;
            ll v = log2(n) + 1;
            vi a;
            a.pb(v);
            ll d = pow(2, v) - n;
            while (d)
            {
                ll p = log2(d);
                if (p > 0)
                    a.pb(p);
                d -= pow(2, p);
            }
            cout<<1<<" ";
            for (ll i = 1; i < v; i++)
            {
                if (check(a, i))
                {
                    cout << -1 << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }

            cout << endl;
        }
        return 0;
    }
