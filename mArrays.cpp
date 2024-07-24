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
        ll n,m;
        cin>>n>>m;
        vi a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }    
        map<ll,ll>mp;   
        for (auto i:a){
            mp[i%m]++;
        }
        ll sum = 0;
        map<ll,bool>f;
        for (auto i:mp){
            f[i.first] = true;
        }
        for (auto i:mp)
        {   
            if (i.first==0){
                sum++;
                // cout<<'1'<<' ';
            }
            else if (i.first*2 == m){
                sum++;
                // cout<<'2'<<' ';
            }
            else {
                ll k = i.first;
                ll q = i.second;
                // cout<<'3'<<' ';
                if (f[k]==true){
                    if (mp.find(m-k) != mp.end())
                    {
                        ll p = mp[m-k];
                        f[m-k] = false;
                        if (abs(p-q)){
                            sum += abs(p-q); 
                        }
                        else 
                            sum++;    
                    }
                    else{
                        sum += q;
                    }
                }
            }    
            // cout<<sum<<'h'<<' ';    
        }

        cout<<sum<<endl;
    }
    return 0;
}