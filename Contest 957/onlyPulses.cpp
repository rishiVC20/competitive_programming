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
        vi a;
        for (ll i=0; i<3; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        sort (a.begin(),a.end());
        ll x=a[0],y=a[1],z=a[2];
        ll p = 5;
        if (x<y && y-x >=5){
            x += 5;
            cout<<x*y*z<<endl;
            continue;
        }
        if (x<y && y-x<5){
            p = p-(y-x);
            x = y;
            
        }
        while (x<z && y<z && p>0){
            x++;
            p--;
            if (p==0){
                break;
            }
            y++;
            p--;
        }
        while (p>0){
            z++;
            p--;
            if (p==0)
                break;
            y++;
            p--;
            if (p==0)
                break;
            x++;
            p--;        
        }
        cout<<x*y*z<<endl;


    }
    return 0;
}