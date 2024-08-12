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
        string s;
        cin>>s;
        ll curr=1;
        vi a,b;
        bool f=true;
        bool h=true;
        for (ll i=0; i<n; i++){
            if (s[i]=='0'){
                h=false;
                break;
            }
        }
        if (h){
            cout<<0<<endl;
            continue;
        }
        for (ll i=1; i<n; i++){
            if (s[i]==s[i-1]){
                curr++;
            }
            else{
                if (s[i]=='1'){
                    a.pb(curr);
                }
                else{
                    b.pb(curr);
                }
                curr=1;
                if (i==n-1){
                    f=false;
                    if (s[i]=='1')
                        b.pb(curr);
                    else    
                        a.pb(curr);    
                }
            }
        }
        if (f){
            if (s[n-1]=='1'){
                b.pb(curr);
            }
            else{
                a.pb(curr);
            }
        }
        // cout<<a.size() <<' '<<b.size()<<' ';
        // if (a.size() < b.size()){
        //     cout<<0<<endl;
        //     continue;
        // }
        
        sort(a.begin(),a.end());
        ll r=a.size(), w=b.size();
        ll p=0;
        ll sum=0;
        while (r >= w){
            if (a[p]>2)
                sum+=2;
            else    
                sum += a[p];
            p++;
            r--;
            if (r==0)
                break;
        }
        cout<<sum<<endl;
    }
    return 0;
}