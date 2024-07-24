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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if (n<=2){
            cout<<stoi(s)<<endl;
            continue;
        }
        vi a;
        bool f1 = true;
        for (ll i=0; i<n; i++)
        {
            a.pb(s[i]-'0');
            if (s[i]=='0')
                f1 = false;
        }       
        if (!f1 && n>3){
            cout<<0<<endl;
            continue;
        }
        if (!f1 && n==3 && (s[0]=='0' || s[2]=='0')){
            cout<<0<<endl;
            continue;
        }
        // if (n==3){
        //     ll k1 = ((s[0]-'0')*10 + (s[1]-'0')) + (s[2]-'0');
        //     ll k2 = ((s[1]-'0')*10 + (s[2]-'0')) + (s[0]-'0');
        //     cout<<min(k1,k2)<<endl;
        //     continue;
        // }
        
        ll ans = INFINITY;
        for (ll i=0; i<n-1; i++)
        {
            ll sum = 0;
            vi v;
            for (ll j=0; j<i; j++){
                v.pb(s[j]-'0');
            }
            v.pb(stoi(s.substr(i,2)));
            for (ll j=i+2; j<n; j++){
                v.pb(s[j]-'0');
            }
            for (auto i:v){
                // cout<<i<<' ';
                if (i!=1)
                    sum += i;
            }
            if (sum==0)
                sum = 1;
            // cout<<'h'<<' ';
            ans = min(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
10
74
0
1
9
1
19
0
11
261
0
0
0
12
93
12
24
0

*/