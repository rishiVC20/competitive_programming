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

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        string k = "";
        ll p = 0;
        vi a, b;
        if (n==2){
            cout<<1<<endl;
            continue;
        }
        for (ll i = 0; i < n - 1; i++)
        {
            if (i % 2 == 1)
            {
                k += s[i];
                if (s[i] == '(')
                {
                    p++;
                    // a.pb(i);
                }
                else
                {
                    // b.pb(i);
                }
            }
            else
            {
                if (p > 0)
                {
                    p--;
                    k += ")";
                }
                else
                {
                    k += "(";
                }
            }
        }
        k += s[n - 1];
        for (ll i=0; i<n; i++){
            if (k[i]=='('){
                a.pb(i);
            }
            else{
                b.pb(i);
            }
        }
        ll sum = 0;
        ll o = a.size();
        ll t=0;
        while (t<o){
            sum += abs(a[t]-b[t]);
            t++;
        }
        // for (auto i : a)
        //     cout << i << ' ';
        // for (auto i : b)
        //     cout << i << ' ';
        // cout<<endl;
        
        // cout << k << ' ';
        
        // ll e = 0, m = 0;
        // for (ll i = 0; i < n; i += 2)
        // {
        //     if (k[i] == '(')
        //     {
        //         if (e < b.size())
        //         {
        //             sum += abs(b[e] - i);
        //             e++;
        //         }
        //     }
        //     else
        //     {
        //         if (m < a.size())
        //         {
        //             sum += abs(a[m] - i);
        //             m++;
        //         }
        //     }
        //     cout<<sum<<' ';
        // }

        cout << sum << endl;
    }
    return 0;
}