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
        ll n,k;
        cin>>n>>k;
        vi a;
        ll z = 1;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
            z *= x;
        }
        if (z%k==0){
            cout<<0<<endl;
            continue;
        }
        ll mini = (k+1)/2;
        // cout<<mini<<' ';
        for (auto i:a){
            ll p = i%k;
            // cout<<p<<' ';
            if (p==0){
                mini = 0;
                break;
            }
            mini = min(mini,k-p);
        }

        cout<<mini<<endl;
    }
    return 0;
}

/*
2
2
1
0
2
0
1
2
0
1
1
4
0
4
3

*/