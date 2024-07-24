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

bool check(string s, vector<string> &cp)
{
    for (ll i=0; i<cp.size(); i++)
    {
        if (cp[i] == s)
            return true;
    }

    return false;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<string>sp;
        for (ll i=0; i<n; i++)
        {
            string s;
            cin>>s;
            sp.pb(s);
        }

        string s = "";
        ll q = 0;
        // while (q<n){
        //     string k = sp[q]; 
        //     bool f = false;    
        //     for (ll i=0; i<n; i++)
        //     {
                
        //         for (ll j=0; j<n; j++)
        //         {
        //             if (i!=q && j!=q){
        //                 string cc = sp[i]+sp[j];
        //                 if (cc==k){
        //                     f = true;
        //                     break;
        //                 }
        //             }
        //         }
        //         // q++;
        //         if (f)
        //             // s += '1';
        //             break;
        //         // else
        //         //     s += '0';    
                
        //     }
        //     if (f)
        //         s += '1';
        //     else
        //         s += '0';    
        //     q++;
        // }
        vector<ll>kk(n,0);
        vector<string>cp;
        for (ll i=0; i<n; i++)
        {
            for (ll j=0; j<n; j++)
            {
                string s = sp[i] + sp[j];
                // check(s,i,j,sp,kk);
                cp.pb(s);
                // kk[i].first = i;
                // kk[i].second = j;
            }
        }
        for (ll i=0; i<sp.size(); i++)
        {
            if (check(sp[i],cp))
                kk[i] = 1;
            // else
            //     kk[i] = 0;    
        }

        for (auto i:kk)
            cout<<i;
        cout<<endl;
    }
    return 0;
}