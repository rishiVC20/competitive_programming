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
        ll n,x,y;
        cin>>n>>x>>y;
        
        // vi a(n+1,0);
        ll sum = 0;
        // for (ll i=k; i<n; i+=k){
        //     a[i] = p;
        //     p--;
        //     sum += a[i];
        // }       
        // ll h = 1;
        // for (ll i=l; i<n; i+=l){
        //     if (a[i] == 0){
        //         a[i] = h;
        //         h++;
        //         sum -= a[i];
        //     }
        // }

        ll p = n/x;
        ll q = n/y;
        if (x%y == 0){
            q -= p;
            sum += q*(q+1)/2;
            sum *= -1;
        }
        else{
            ll h = LCM(x,y);
            // cout<<h<<' ';
            ll u = n/h;
            // cout<<u<<' ';
            ll ans = n*(n+1)/2;
            sum += ans - ((n-(p-u))*(n-(p-u)+1)/2);
            // cout<<sum<<' ';
            sum -= (q-u)*(q-u+1)/2;
        }

        cout<<(ll)sum<<endl;
    }
    return 0;
}