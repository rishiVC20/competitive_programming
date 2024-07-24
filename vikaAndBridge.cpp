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
        ll n,k;
        cin>>n>>k;
        vi a;
        for (ll i=0; i<n; i++){
            ll x; cin>>x;
            a.pb(x);
        }
        if (k==1){
            cout<<0<<"\n";
            continue;
        }

        vector<pair<ll,ll>>v;
        for (ll i=1; i<=k; i++){
            priority_queue<ll>qu;
            ll curr = 0;
            bool f = true;
            for (ll j=0; j<n; j++){
                if (a[j]==i){
                    qu.push(curr);
                    curr = 0;
                    if (j==(n-1))
                        f = false;
                }
                else
                    curr++; 
                       
            }
            if (f)
                qu.push(curr);
            ll one = qu.top();
            qu.pop();
            ll two = qu.top();
            qu.pop();
            // cout<<one<<' '<<two<<' ';
            v.push_back({one,two});
        }
        
        // for (auto i:v){
        //     cout<<i.first<<' '<<i.second<<"\n";
        // }
        // cout<<endl;
        ll maxi = INT_MAX;
        vi c;
        for (ll i=0; i<k; i++){
            ll maxi = 0;
            ll k = v[i].first/2;
            ll p = v[i].second;
            // cout<<k<<' '<<p<<' ';
            maxi = max(k,p);
            c.pb(maxi);
        }
        ll mini = n;
        for (auto i:c)
            mini = min(mini,i);

        cout<<mini<<"\n";
   }
    return 0;
}


