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
        vi a,b;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x%m);
        } 
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            b.pb(x%m);
        }     

        sort(a.begin(),a.end());  
        sort(b.begin(),b.end());

        ll sum = 0;
        for (ll i=0; i<n; i++)
        {
            // for (ll j=0; j<n; j++)
            // {
            //     if ((a[i]+b[j]) == m)
            //         sum++;
            //     if (a[i]+b[j]==0)
            //         sum++;    
            // }

            if (a[i]==0){
                ll x = upper_bound(b.begin(),b.end(),0)-b.begin();
                x--;
                // cout<<x<<'h'<<' ';
                if (x>=0){
                    sum += x+1;
                }
            }
            else{
                ll y = lower_bound(b.begin(),b.end(),m-a[i]) - b.begin();
                ll x = upper_bound(b.begin(),b.end(),m-a[i]) - b.begin();
                x--;
                if (b[y]==(m-a[i]) && b[x]==(m-a[i]))
                    sum += (x-y)+1;
                // if (y-x >=0 && (a[i]+b[x]==m) && (a[i]+b[y]==m)){
                //     sum += (y-x)+1;
                // }
            }
        }  

        cout<<sum<<endl;
    }
    return 0;
}