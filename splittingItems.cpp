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
        for (ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        sort(a.begin(),a.end());
        ll maxi = a[n-1];
        for (ll i=n-2; i>=0; i-=2){
            if (n%2==1 && i==0)
                break;
            if (k==0)
                break;
            if (k >= (maxi-a[i])){
                k -= (maxi-a[i]);
                a[i] = maxi;
                if (i-1>=0)
                    maxi=a[i-1];
            }    
            else{
                a[i]+=k;
                k=0;
                break;
            }
        }       
        ll v=0;
        ll sum=0;
        for (ll i=n-1; i>=0; i--){
            if (v%2==0){
                sum += a[i];
            }
            else{
                sum -= a[i];
            }
            v++;
        }

        cout<<sum<<endl;
    }
    return 0;
}