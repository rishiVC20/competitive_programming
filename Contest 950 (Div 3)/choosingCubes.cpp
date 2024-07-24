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
        ll n,f,k;
        cin>>n>>f>>k;
        vi a;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }       

        if (n==1){
            cout<<"YES"<<endl;
            continue;
        }
        ll pp = a[f-1];
        // cout<<pp<<" ";
        sort(a.rbegin(),a.rend());
        // for (auto i:a)
            // cout<<i<<" ";
        // bool f = false;
        // cout<<a[k-1]<<" "<<pp<<endl;
        // if (a[k] > pp)
        //     cout<<"NO"<<endl;
        // else if (a[k] < pp)
        //     cout<<"YES"<<endl;
        // else if (a[k]==pp){
        //     if (a[k-1]==pp)
        //         cout<<"MAYBE"<<endl;
        //     else
        //         cout<<"NO"<<endl;
        // }    
        ll x=n-1, y=0;
        for (ll i=0; i<n; i++)
        {   
            if (a[i]==pp){
                x = min(x,i);
                y = max(y,i);
            }
        }
        if (x>k-1 && y>k-1)
            cout<<"NO"<<endl;
        else if (x<=k-1 && y>k-1)
            cout<<"MAYBE"<<endl;
        else 
            cout<<"YES"<<endl;        
        
    }
    return 0;
}

/*
MAYBE
YES
NO
YES
YES
YES
MAYBE
MAYBE
YES
YES
YES
NO

*/