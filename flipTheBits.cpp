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
        string a,b;
        cin>>a>>b;
        vector<pair<ll,ll>>v;
        ll i=0, j=0;
        ll cn0=0, cn1=0;
        ll k=0;
        while (i<n){
            ll p,l;
            if (a[i]=='0'){
                cn0++;
                p=i;
            }
            else if (a[i]=='1'){
                cn1++;
                l=i;
            }
            if (cn0==cn1){
                // v[k].first = p;
                // v[k].second = l;
                v.pb({j,i});
                j = i+1;
            }
            i++;    
        }
        ll m = v.size();
        for (ll i=0; i<m; i++){
            ll st = v[i].first;
            ll end = v[i].second;
            if (a[st]==b[st]) continue;     
            for (ll j=st; j<=end; j++){
                if (a[j]=='1')
                    a[j] = '0';
                else
                    a[j] = '1';    
            }
        }

        bool f = true;
        for (ll i=0; i<n; i++){
            if (a[i]!=b[i]){
                f = false;
                break;
            }
        }   
        if (f)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}