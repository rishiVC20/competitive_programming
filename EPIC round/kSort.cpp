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

void changeArr(ll st, ll end, vi &a, ll cp)
{
    for (ll i=st; i<=end; i++)
    {
        a[i] += cp;
    }
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

        ll ans = a[0];
        ll cnt = 0;
        bool f = false;
        ll u = 0;
        for (ll i=1; i<n; i++)
        {
            if (a[i] < ans){
                cnt++;
            }
            else{
                ans = a[i];
                f = true;
                if (i!=n-1)
                     u++;
            }
        }
        vi k = a;
        ll sum = 0;
        ll maxi = INT_MIN;
        for (ll i=1; i<n; i++){
            ll curr = i;
            ll cp;
            if (a[i] < a[i-1]){
                cp = a[i-1] - a[i];
                // ll v = a[i];
                // while (a[i] < a[i+1] && i<n && a[i]<v){
                //     i++;
                //     // curr++;
                // }
                // // cout<<curr<<' '<<i<<' ';
                // u++;
                // changeArr(curr,i,a,cp);
                // sum += ((i-curr) + 1 + 1)*cp;
                sum += cp;
                maxi = max(maxi,cp);
                a[i] += cp;
            }
            // for (auto i:a)
            //     cout<<i<<' ';
            // cout<<'h';    

        }

        ll p = 0;
        ll diff = INT_MAX;
        for (ll i=0; i<n; i++){
            ll p = a[i]-k[i];
            if (p>0){
                diff = min(diff,p);
            }
        }
        // cout<<u<<' ';
        if (maxi != INT_MIN)    
            sum += maxi;
        cout<<sum<<endl;
    }
    return 0;
}