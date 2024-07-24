// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
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
        vi a;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }
        if (count(a.begin(),a.end(),a[0]) == n){
            cout<<1<<endl;
            continue;
        }

        ll i=0, j=n-1;
        ll sum1 = a[i];
        ll sum2 = a[j];
        vi v;
        while (i<n && j>=0)
        {
            if (sum1==sum2){
                // break;
                v.pb(i);
                if (i>=j)
                    break;
            }
            sum1 |= a[i]; 
            sum2 |= a[j]; 
            i++;
            j--;
        }

        if (i>=j){
            cout<<i<<endl;
        }
        else{
            cout<<n<<endl;
        }
    }
    return 0;
}