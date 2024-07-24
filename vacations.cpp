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

ll rec(vi &a, ll curr, ll prev, vector<vector<ll>> &dp)
{
    if (curr>=a.size())
        return 0;

    if (dp[curr][prev] != -1)
        return dp[curr][prev];

    ll sum = 0;
    if (a[curr]==0){
        sum = max(sum,rec(a,curr+1,0,dp));
    }    
    else if (a[curr]==1){
        if (prev != 1){
            sum = max(sum,rec(a,curr+1,1,dp)+1);
        }
        sum = max(sum,rec(a,curr+1,0,dp));
    }
    else if (a[curr]==2){
        if (prev != 2){
            sum = max(sum,rec(a,curr+1,2,dp)+1);
        }
        sum = max(sum,rec(a,curr+1,0,dp));
    }
    else if (a[curr]==3){
        if (prev != 2){
            sum = max(sum,rec(a,curr+1,2,dp)+1);
        }
        if (prev != 1){
            sum = max(sum,rec(a,curr+1,1,dp)+1);
        }
        sum = max(sum,rec(a,curr+1,0,dp));
    }

    // dp[curr][prev] = sum;
    return dp[curr][prev]=sum;
}

int main() {
    ll n;
    cin>>n;
    vi a;
    for (ll i=0; i<n; i++)
    {
        ll x; cin>>x;
        a.pb(x);
    }

    vector<vector<ll>>dp(n,vector<ll>(3,-1));
    if (a[0]==0){
        ll ans = rec(a,1,0,dp);
        cout<<n-ans<<endl;
    }
    else if (a[0]==1){
        ll ans1 = rec(a,1,0,dp);
        ll ans2 = rec(a,1,1,dp) + 1;
        cout<<n-max(ans1,ans2)<<endl;
    }
    else if (a[0]==2){
        ll ans1 = rec(a,1,0,dp);
        ll ans2 = rec(a,1,2,dp) + 1;
        cout<<n-max(ans1,ans2)<<endl;
    }
    else{
        ll ans1 = rec(a,1,0,dp);
        ll ans2 = rec(a,1,2,dp) + 1;
        ll ans3 = rec(a,1,1,dp) + 1;
        cout<<n-max(ans1,max(ans2,ans3))<<endl;
    }
    return 0;
}