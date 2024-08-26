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
        ll n;
        cin>>n;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }
        // for(auto i = a.begin(); i != a.end(); ++i){
        //     ll maxi = *min_element(a.begin(),a.end()-1);
        //     if(i+1 != a.end()){
        //         *i = *(i+1);
        //         a.erase(i+1);
        //     }
        //     if(a.size()==1)
        //         break;;
        //     ll mini = *max_element(a.begin(),a.end()-1);
        //     if(i+1 != a.end()){
        //         a.erase(i+1);
        //     }    
        // }
        // bool f=true;
        // while(a.size()>1){
        //     if(f){
        //         auto i=min_element(a.begin(),a.end()-1);
        //         if(i+1 != a.end()){
        //             *i = max(*i,*(i+1));
        //             a.erase(i+1);
        //         }
        //         f = !f;
        //     }
        //     else{
        //         auto i=max_element(a.begin(),a.end()-1);
        //         if(i+1 != a.end()){
        //             *i = min(*i,*(i+1));
        //             a.erase(i+1);
        //         }
        //         f = !f;
        //     }
        // }
        
        // for(auto i:a)
        //     cout<<i<<' ';
        // cout<<endl;   
        sort(a.begin(),a.end());
        // for(auto i:a)
        //     cout<<i<<' ';
        // cout<<endl;
        ll cp=(n)/2 ;
        // cout<<cp<<' ';
        ll m=n-2;
        ll ans;
        // if(m%2 == 0){
        //     ans = max(a[cp],a[n-1]);
        // }
        // else{
        //     ans=min(a[cp],a[n-1]);
        // }

        cout<<a[cp]<<endl;
    }
    return 0;
}