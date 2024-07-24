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
        ll n,m;
        cin>>n>>m;
        vector<vector<char>>cp(n,vector<char>(m));

        ll ma = -1;
        ll q;
        for (ll i=0; i<n; i++)
        {
            ll k = 0;
            // q = ma;
            for (ll j=0; j<m; j++)
            {
                char c; cin>>c;
                cp[i][j] = c;
                if (c=='#')
                    k++;
            }
            // ma = max(ma,k);
            if (k > ma){
                ma = k;
                q = i;
            }
            // if (q != ma)
            //     q = i;
        }
        ll r;
        for (ll i=0; i<m; i++)
        {
            ll k = 0;
            for (ll j=0; j<n; j++)
            {
                if (cp[j][i]=='#')
                    k++;
            }
            if (k==ma){
                r = i;
                break;
            }
        }
        cout<<q+1<<" "<<r+1<<endl;
    }
    return 0;
}