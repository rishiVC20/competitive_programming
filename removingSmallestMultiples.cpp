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
        // for (auto i:a)
        //     cout<<i<<' ';
        ll sum = 0;
           
        for (ll i=1; i<=n; i++)
        {
            
                for (ll j=i; j<=n; j+=i){
                    // cout<<i<<' ';
                    // sum += k;
                    if (s[j-1]=='0'){
                        sum += i;
                        s[j-1]='2';
                    }
                    else if (s[j-1]=='1'){
                        break;
                    }

                }
            
        }       
        // for (auto i:a)
        //     cout<<i<<' ';
        cout<<sum<<endl;
    }
    return 0;
}