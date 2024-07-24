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
        ll n;
        cin>>n;
        vector<vector<ll>>mg(n,vector<ll>(n));
        for (ll i=0; i<n; i++)
        {
            for (ll j=0; j<n; j++)
            {
                char c;
                cin>>c;
                mg[i][j] = c-'0';
            }
        }
        
        ll sum = 0;
        ll r1 = 0, c2 = 0;
        ll r3 = n-1, c4 = n-1;
        while (r1<n && c2<n && r3>=0 && c4>=0)
        {
            // ll z = 0;
            
            ll r2 = n-1;
            ll r4 = 0;
            ll c1 = 0;
            ll c3 = n-1;  
            for (ll i=0; i<n; i++){
                ll o = 0;
                if (mg[r1][c1]) o++;
                if (mg[r2][c2]) o++;
                if (mg[r3][c3]) o++;
                if (mg[r4][c4]) o++;
                cout<<o<<" ";
                sum += min(o,4-o);
                c1++, r2--, c3--, r4++;
            }
            r1++, c2++, r3--, c4--;
            
        }

        cout<<(sum/4)<<endl;
    }
    return 0;
}